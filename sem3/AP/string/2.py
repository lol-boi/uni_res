def display_prime(a,b):
    if(a<=1):
        print("Number should be larger than 1")
        return
    for i in range(a, b+1):
        count = 0
        for j in range(2,i):
            if i%j == 0:
                count = 1
        if count == 0:
            print(i)

def main():
    a = int(input("Enter the first number: "))
    b = int(input("Enter the second number: "))
    display_prime(a,b)

main()
    
