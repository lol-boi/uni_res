def find_area(base,hight):
    area = base*hight*.5
    return area

height = float(input("Enter the height: "))
base = float(input("Enter the base: "))
print(find_area(base,height) )
