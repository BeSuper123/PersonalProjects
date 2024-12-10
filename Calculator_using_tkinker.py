import tkinter as tk
import random

window = tk.Tk()

window.geometry("400x300")

window.title("My First GUI with python")

label = tk.Label(window, text="Basic Calculator", font=('Arial', 16))
label.pack()

textbox = tk.Text(window, height=3, font=('Arial', 12))
textbox.pack(padx=10, pady=10)
'''
button = tk.Button(window, text="Click Me!", font=('Arial', 11))
button.pack(padx=10, pady=10)

myEntry = tk.Entry(window)
myEntry.pack(padx=10, pady=10)
'''

buttonFrame = tk.Frame(window)
buttonFrame.columnconfigure(0, weight=1)
buttonFrame.columnconfigure(1, weight=1)
buttonFrame.columnconfigure(2, weight=1)
buttonFrame.columnconfigure(3, weight=1)

'''
def on_button_click(text):
    words = ["Hello", "World", "Test"]
    anotherBtn = tk.Button(window, text=random.choice(words))
    anotherBtn.place(x=350, y=450, height=100, width=100)
'''

# Function to handle button clicks without using try-except or advanced methods
def on_button_click(value):
    if value == "=":
        expression = textbox.get(1.0, tk.END).strip()  # Get the text from the textbox
        if "+" in expression or "-" in expression or "*" in expression or "/" in expression:
            result = eval(expression)  # Evaluate the expression
            textbox.delete(1.0, tk.END)
            textbox.insert(tk.END, str(result))  # Display the result
        else:
            textbox.delete(1.0, tk.END)
            textbox.insert(tk.END, "Invalid")
    elif value == "C":
        textbox.delete(1.0, tk.END)  # Clear the textbox
    else:
        textbox.insert(tk.END, value)  # Append the button value to the textbox

# Add buttons manually
btn1 = tk.Button(buttonFrame, text="1", font=('Arial', 14), command=lambda: on_button_click("1"))
btn1.grid(row=0, column=0, sticky=tk.W + tk.E)

btn2 = tk.Button(buttonFrame, text="2", font=('Arial', 14), command=lambda: on_button_click("2"))
btn2.grid(row=0, column=1, sticky=tk.W + tk.E)

btn3 = tk.Button(buttonFrame, text="3", font=('Arial', 14), command=lambda: on_button_click("3"))
btn3.grid(row=0, column=2, sticky=tk.W + tk.E)

btn4 = tk.Button(buttonFrame, text="4", font=('Arial', 14), command=lambda: on_button_click("4"))
btn4.grid(row=1, column=0, sticky=tk.W + tk.E)

btn5 = tk.Button(buttonFrame, text="5", font=('Arial', 14), command=lambda: on_button_click("5"))
btn5.grid(row=1, column=1, sticky=tk.W + tk.E)

btn6 = tk.Button(buttonFrame, text="6", font=('Arial', 14), command=lambda: on_button_click("6"))
btn6.grid(row=1, column=2, sticky=tk.W + tk.E)

btn7 = tk.Button(buttonFrame, text="7", font=('Arial', 14), command=lambda: on_button_click("7"))
btn7.grid(row=2, column=0, sticky=tk.W + tk.E)

btn8 = tk.Button(buttonFrame, text="8", font=('Arial', 14), command=lambda: on_button_click("8"))
btn8.grid(row=2, column=1, sticky=tk.W + tk.E)

btn9 = tk.Button(buttonFrame, text="9", font=('Arial', 14), command=lambda: on_button_click("9"))
btn9.grid(row=2, column=2, sticky=tk.W + tk.E)

btn10 = tk.Button(buttonFrame, text="+", font=('Arial', 14), command=lambda: on_button_click("+"))
btn10.grid(row=0, column=3, sticky=tk.W + tk.E)

btn11 = tk.Button(buttonFrame, text="-", font=('Arial', 14), command=lambda: on_button_click("-"))
btn11.grid(row=1, column=3, sticky=tk.W + tk.E)

btn12 = tk.Button(buttonFrame, text="*", font=('Arial', 14), command=lambda: on_button_click("*"))
btn12.grid(row=2, column=3, sticky=tk.W + tk.E)

btn13 = tk.Button(buttonFrame, text="=", font=('Arial', 14), command=lambda: on_button_click("="))
btn13.grid(row=3, column=3, sticky=tk.W + tk.E)

btn14 = tk.Button(buttonFrame, text="C", font=('Arial', 14), command=lambda: on_button_click("C"))
btn14.grid(row=3, column=0, sticky=tk.W + tk.E)

btn15 = tk.Button(buttonFrame, text="0", font=('Arial', 14), command=lambda: on_button_click("0"))
btn15.grid(row=3, column=1, sticky=tk.W + tk.E)

buttonFrame.pack(fill='x')


window.mainloop()
