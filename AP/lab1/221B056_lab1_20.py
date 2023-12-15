num1 = int(input("Enter the first number: "))
num2 = int(input("Entert the second number: "))
smallest = 0
if num1 < num2:
    smallest = num1
else:
    smallest = num2
ans = 0 
for i in range(1,smallest+1):
    if(num1%i==0) and (num2%i==0):
        ans = i
print("The GCD is ", ans)
