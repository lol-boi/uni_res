amount = int(input("Enter the amount: "))
hun = 0
fif = 0
ten = 0
one = 0
while amount != 0:
    if(amount - 100 > -1):
        amount=amount-100
        hun += 1
    elif(amount-50 > -1):
        amount -= 50
        fif += 1
    elif(amount-10 > -1 ):
        amount -= 10
        ten += 1
    else:
        one = amount
        amount = 0
print("No of Hundred, Fifty, Tens notes needed are: ", hun,fif,ten)

