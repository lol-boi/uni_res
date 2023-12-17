def si(p,r,t):
    si = p+(p*r*t)/ 100
    return si

p = int(input("Enter the principal: "))
r = int(input("Enter the rate: "))
t = int(input("Enter the time period: "))
print(si(p,r,t))

