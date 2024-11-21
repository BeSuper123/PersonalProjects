print("---Calculator---")
print("1    2    3    +")
print("4    5    6    -")
print("7    8    9    /")
print("     0         *")
print("----------------")

class Calculator:
    def __init__(self, expression):
        self.expression = expression
        self.num1, self.operator, self.num2 = self.__expressions()

    def __expressions(self):
        self.expression = self.expression.replace(" ", "")

        for self.operator in ['+', '-', '/', '*']:
            if self.operator in self.expression:
                num1, num2 = self.expression.split(self.operator)
                return float(num1), self.operator, float(num2)

    def calculation(self):
        if self.operator == "+":
            return f"Answer: {self.num1 + self.num2}"
        elif self.operator == "-":
            return f"Answer: {self.num1 - self.num2}"
        elif self.operator == "/":
            if self.num2 == 0:
                return "Error: Not able to divide by 0"
            else:
                return f"Answer: {self.num1 / self.num2}"
        elif self.operator == "*" or self.operator == "x" or self.operator == "X":
            return f"Answer: {self.num1 * self.num2}"
        else:
            return "That is not a valid calculation"



if __name__ == "__main__":
    expression = input()
    calculator = Calculator(expression)
    result = calculator.calculation()
    print(result)
