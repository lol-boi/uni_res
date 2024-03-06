import tkinter as tk
import random
import time
import math
import sys


def generate_cities(num_cities):
    return [(random.randint(50, 450), random.randint(50, 450)) for _ in range(num_cities)]
def populate_population(population_size, num_cities):
    return [[i for i in range(num_cities)] for _ in range(population_size)]



def calculateFitness(cities, population):
    global fitness, record_distance, bestEver
    currentRecord = float('inf')
    fitness = [0] * len(population)
    for i in range(len(population)):
        d = calc_total_distance(cities, population[i])
        if d < record_distance:
            record_distance = d
            bestEver = population[i]
        if d < currentRecord:
            currentRecord = d
            currentBest = population[i]
            draw_points(currentBest)
            time.sleep(0.06)
        fitness[i] = 1 / (d + 1)
    max_fitness = max(fitness)
    if max_fitness != 0:
        fitness = [f / max_fitness for f in fitness] 
    draw_duplicate_cities(bestEver)

def nextGeneration():
    global population
    newPopulation = []
    for i in range(len(population)):
        orderA = pickOne(population, fitness)
        orderB = pickOne(population, fitness)
        order = crossOver(orderA, orderB)
        mutate(order, 0.01)
        newPopulation.append(order)
    population = newPopulation

def pickOne(list, prob):
    index = 0
    r = random.random()
    while r > 0:
        r -= prob[index]
        index += 1
    index -= 1
    return list[index][:]

def crossOver(orderA, orderB):
    start = random.randint(0, len(orderA) - 1)
    end = random.randint(start + 1, len(orderA))
    neworder = orderA[start:end]
    for city in orderB:
        if city not in neworder:
            neworder.append(city)
    return neworder

def mutate(order, mutationRate):
    for i in range(total_cities):
        if random.random() < mutationRate:
            indexA = random.randint(0, len(order) - 1)
            indexB = (indexA + 1) % total_cities
            order[indexA], order[indexB] = order[indexB], order[indexA]

def calc_total_distance(cities, order):
    total_distance = 0
    num_cities = len(cities)
    for i in range(num_cities):
        from_city = order[i]
        to_city = order[(i + 1) % num_cities]
        x1, y1 = cities[from_city]
        x2, y2 = cities[to_city]
        distance = math.sqrt((x2 - x1) ** 2 + (y2 - y1) ** 2)
        total_distance += distance
    return total_distance

def draw_points(order):
    canvas.delete("all")
    for i, (x, y) in enumerate(cities):
        canvas.create_oval(x - 3, y - 3, x + 3, y + 3, fill='blue')
        canvas.create_text(x + 10, y - 10, text=chr(65 + i))
    for i in range(len(order) - 1):
        city1_index = order[i]
        city2_index = order[i + 1]
        x1, y1 = cities[city1_index]
        x2, y2 = cities[city2_index]
        canvas.create_line(x1, y1, x2, y2, fill='red')
    canvas.update()

def draw_duplicate_cities(order):
    canvas_duplicate.delete("all")
    for i, (x, y) in enumerate(cities):
        canvas_duplicate.create_oval(x - 3, y - 3, x + 3, y + 3, fill='blue')
        canvas_duplicate.create_text(x + 10, y - 10, text=chr(65 + i))
    if order:
        for i in range(len(order) - 1):
            city1_index = order[i]
            city2_index = order[i + 1]
            x1, y1 = cities[city1_index]
            x2, y2 = cities[city2_index]
            canvas_duplicate.create_line(x1, y1, x2, y2, fill='green', width=2)
    canvas_duplicate.update()

total_generations = 100
population_size = 75
total_cities = 8

if len(sys.argv) >= 4:
    total_generations = int(sys.argv[1])
    population_size = int(sys.argv[2])
    total_cities = int(sys.argv[3])

bestEver = None
population = []
fitness = []
record_distance = float('inf')
cities = generate_cities(total_cities)

root = tk.Tk()
root.title("Draw Points and Join")
root.resizable(False, False)

label_population = tk.Label(root, text="Best Among Population")
label_population.pack()

canvas = tk.Canvas(root, width=500, height=500)
canvas.pack()

label_generation = tk.Label(root, text="Best Among the Generations")
label_generation.pack()

canvas_duplicate = tk.Canvas(root, width=500, height=500)
canvas_duplicate.pack()

population = populate_population(population_size, total_cities)

for _ in range(total_generations):
    calculateFitness(cities, population)
    nextGeneration()

root.mainloop()
