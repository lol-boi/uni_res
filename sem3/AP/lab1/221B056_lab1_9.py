num1 = int(input("Enter the num: "))
num2 = int(input("Enter the num: "))
num3 = int(input("Enter the num: "))

if num1 > num2 and num1 > num3:
    print(num1, "is the greatest")
elif  num2 > num3 and num2 >num1:
    print(num2, "is the greatest")
elif num3 > num1 and num3 > num2:
    print(num3, "is the greatest")
else:
    print("Invalid input ")
    
