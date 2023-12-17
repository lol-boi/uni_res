arr = []
for i in range(5):
    num = int(input("Enter the sub marks: "))
    if  num >= 0 and num <= 100:
        arr.append(num)
    else:
        print("Invaid input")
sum = 0
for i in arr:
    sum += i
print("Aggregate marks is: ", sum)
print("Percentage marks is: ", sum/500*100)

