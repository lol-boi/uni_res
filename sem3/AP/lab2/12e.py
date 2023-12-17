def do_2ice(f,val): 
    f(val)
    f(val)
def print_2ice(a):
    print (a)
s = input("Enter a input: ")
do_2ice(print_2ice,s)
