from tkinter import *
root = Tk()

label1 = Label(root, text="Enter the first number:")
label2 = Label(root, text="Enter the second number:")
label3 = Label(root, text="The result is:")

entry1 = Entry(root)
entry2 = Entry(root)

result = Label(root, text="")

button1 = Button(root, text="Sum")
button2 = Button(root, text="Diff")
button3 = Button(root, text="Multiplication")
button4 = Button(root, text="Div")
button5 = Button(root, text="Remainder")

def add():

    num1 = float(entry1.get())
    num2 = float(entry2.get())
    ans = num1 + num2
    result.config(text=str(ans))

def subtract():
    num1 = float(entry1.get())
    num2 = float(entry2.get())
    ans = num1 - num2
    result.config(text=str(ans))

def multiply():
    num1 = float(entry1.get())
    num2 = float(entry2.get())
    ans = num1 * num2
    result.config(text=str(ans))

def divide():
    num1 = float(entry1.get())
    num2 = float(entry2.get())
    if num2 != 0:
        ans = num1 / num2
        result.config(text=str(ans))
    else:
        result.config(text="Cannot divide by zero")

def modulo():
    num1 = float(entry1.get())
    num2 = float(entry2.get())
    if num2 != 0:
        ans = num1 % num2
        result.config(text=str(ans))
    else:
        result.config(text="Cannot divide by zero")

        
button1.config(command=add)
button2.config(command=subtract)
button3.config(command=multiply)
button4.config(command=divide)
button5.config(command=modulo)
label1.pack()
entry1.pack()
label2.pack()
entry2.pack()
button1.pack()
button2.pack()
button3.pack()
button4.pack()
button5.pack()
label3.pack()
result.pack()
root.mainloop()
