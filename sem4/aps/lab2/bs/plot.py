import matplotlib.pyplot as plt
import sys
# Read data from file
file = sys.argv[1]
with open(file, 'r') as file:
    lines = file.readlines()

# Extract x and y values
x_values = [float(line.split()[0]) for line in lines]
y_values = [float(line.split()[1]) for line in lines]

# Plot the data
plt.scatter(y_values, x_values, label='Data Points')
plt.title('Scatter Plot from data.txt')
plt.xlabel('Size of input')
plt.ylabel('Execution time')
plt.legend()
plt.grid(True)
plt.show()

