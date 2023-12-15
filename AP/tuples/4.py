counter1 = 0
while counter1 < 5:
    star = ""
    counter2 = 5 
    while counter2 > counter1:
        star = star+"*"
        counter2 -= 1
    print(star)
    counter1 += 1
