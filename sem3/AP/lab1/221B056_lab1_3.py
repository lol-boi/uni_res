principle = int(input("Enter the amout: "))
rate = float(input("Enter the rate of interest: "))
time = float(input("Enter the time: ")) 
tmp = int(input("Enter the no of times to apply interest: "))

print("The SI is: ", principle +(principle*rate*time/100))
print("The CI is: ", principle*(1+(rate/time)**(time*tmp)))

