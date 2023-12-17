from tkinter import *
root = Tk()
button1 = Button(root, text="Create another button")
def create_button2():
    button2 = Button(root, text="Create a label")
    button2.pack()
    def create_label():
        label = Label(root, text="Nice job!").pack()
    button2.config(command=create_label)
button1.config(command=create_button2)
button1.pack()
root.mainloop()






