def print_number(val):
    if(val == 'd'):
        for i in range(10,0,-1):
            print(i)
    elif (val == 'a'):
        for j in range(1,11):
            print(j)
    else:
        print("Invalid input!!")

val = input("Enter 'a' or 'd': ")
print_number(val)
