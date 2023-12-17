lst = []
for i in range(9):
    num = int(input("Enter the number: "))
    if i%2 == 1: 
        lst.append(num)

if len(lst) != 0:
    largest = lst[0]
    for i in lst:
        if i > largest:
            largest = i
    print("Largest: ", largest)
else:
    print("No odd number.")

    
