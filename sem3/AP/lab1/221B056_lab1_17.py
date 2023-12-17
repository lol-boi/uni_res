num = int(input("Enter the number: "))
tmp  = 0
for i in range((num//4) +1):
    if i**3 == num:
        print("The number is a perfect cube.")
        tmp = 1
        break
if tmp == 0:
    print("The number is not a perfect cube")
