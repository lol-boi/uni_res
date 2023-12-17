def rightjustify(s):
    length = len(s)
    for i in range(15-length):
        print(" ", end ='')
    print(s)

s = input("Enter a sring: ")
t = s.split()
for i in t: 
    rightjustify(i)
