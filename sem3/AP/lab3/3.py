def check_triangle(a,b,c):
    if (a <= b+c) and (b <= c+a) and (c <= a+b):
        print("Triagle is possible.")
    else:
        print("Triangle is not possible.")

a = ()
a = input("Enter the sides: ").split()
check_triangle(int(a[0]), int(a[1]), int(a[2]))

