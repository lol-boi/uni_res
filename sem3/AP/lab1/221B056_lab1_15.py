num = int(input("Enter the number: "))
tmp = 1;

for i in range(5):
    num = num + tmp
    tmp *= 10
print("The answer is: ", num)
