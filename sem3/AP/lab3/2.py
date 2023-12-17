gems = ("Emerald","Ivory", "Jasper", "Ruby", "Garnet")
prices = (1760,2119,1599,3929,3999)
print("The gems avalable are: ")
a = 1
for i in gems:    
    print(a,i)
    a += 1;
inp = ()
amt = ()
inp = input("Enter the gems wanted: " ).split()
amt = input("Enter their amount: ").split()
bill = 0 
for i in inp:
    if i not in gems:
        bill = -1
        break
    else:
        bill += (int(amt[inp.index(i)])*prices[gems.index(i)])

if bill >30000:
    print("Your puchase is applicable for 5% discoutnt: ")
    print("Your total is: ",(bill - bill*(5/100)))
else:
    print("Your bill is: ", bill)
