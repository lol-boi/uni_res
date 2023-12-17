from tkinter import *
root = Tk()
def event():
    Label(root,text="Welcome..........").pack()
Button(root,text="GO", command=event).pack()
root.mainloop()

