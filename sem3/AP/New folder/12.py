
n = int(input("Enter the number: "))
for i in range(n*2+1):
    if(i%2 ==0):
        for j in range(n*2+1):
            if(j <  n*2):
                if(j%2 == 0):
                    print("+", end="")
                else:
                    print("----", end="")
            if(j == n*2):
                print("+")
    else:
        for j in range(4):
            for a in range(n*2+1):
                if(a <  n*2):
                    if(a%2 == 0):
                        print("|", end="")
                    else:
                        print("    ", end="")
                if(a == n*2):
                    print("|")
