def com_interest(tmp, time , rate , principle):
    return principle*(1+(rate/time)**(time*tmp))

p = int(input("Enter the principle: "))
t = int(input("Enter the time period: "))
r = int(input("Enter the rate of interest: "))
n = int(input("Enter the number of times: "))
print(com_interest(n,t,r,p))
