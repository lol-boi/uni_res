n = int(input("Enter the number: "));
a = 0
b = 1
print(a,end=" ")
for i in range(0,n-1):
    print(b,end=" ")
    t = b
    b += a
    a = t
