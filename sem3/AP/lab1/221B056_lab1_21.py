num1 = int(input("Enter a number: "))
num2 = int(input("Enter a number: "))
largest = 0
tmp = 0 
ans = 1
while True:
    if ans%num1==0 and ans%num2==0:
        break
    ans += 1

print("LCM is: ", ans)         
