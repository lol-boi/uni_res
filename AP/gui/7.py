from tkinter import *
root =Tk()
root.geometry('500x500')
label1 = Label(root, text="Enter your first name:")
label2 = Label(root, text="Enter your last name:")

entry1 = Entry(root)
entry2 = Entry(root)

button = Button(root, text="Submit")
greeting = Label(root, text="")

def wish_user():
    first_name = entry1.get()
    last_name = entry2.get()
    message = first_name + " " + last_name + ", Welcome to Python"
    greeting.config(text=message)
button.config(command=wish_user)
label1.pack()
entry1.pack()
label2.pack()
entry2.pack()
button.pack()
greeting.pack()
root.mainloop()
