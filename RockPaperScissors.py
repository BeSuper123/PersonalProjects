import random

class RockPaperScissors:
    def __init__(self):
        self.choice = self.random_choice() # randomises the computers answer
        self.characters = self.opponents() # randomises the opponents name

    # method to choose the random choice
    def random_choice(self):
        decision = ["rock", "paper", "scissors"]
        self.choice = random.choice(decision)
        return self.choice

    # method to choose a random characters name
    def opponents(self):
        character = ["Elsa", "Mirabel", "Olaf", "Monkey D. Luffy"]
        self.characters = random.choice(character)
        return self.characters # returns the chosen character


class Game:
    def __init__(self):
        self.choices = RockPaperScissors()
        self.random_decision = self.choices.choice
        self.char = self.choices.characters
        self.name = ""

    # method to show how each decisions answer is found
    def decision_making(self, decision):
        if decision in  ["rock", "paper", "scissors"]:
            if decision == self.random_decision:
                print(f"You chose {decision}. {self.char} also chose {self.random_decision}"
                        f"\nIts a draw.")
                decision = input("\nrock, paper, or scissors: ")

                chosen_word = ["rock", "paper", "scissors"]
                self.random_decision = random.choice(chosen_word)
                return self.decision_making(decision)

            elif decision == "rock" and self.random_decision== "paper":
                return (f"You chose {decision}. {self.char} chose {self.random_decision}"
                        f"\nYou lose!")

            elif decision == "rock" and self.random_decision== "scissors":
                return (f"You chose {decision}. {self.char} chose {self.random_decision}"
                        f"\nYou win!")

            elif decision == "scissors" and self.random_decision== "paper":
                return (f"You chose {decision}. {self.char} chose {self.random_decision}"
                        f"\nYou win!")

            elif decision == "scissors" and self.random_decision== "rock":
                return (f"You chose {decision}. {self.char} chose {self.random_decision}"
                        f"\nYou lose!")

            elif decision == "paper" and self.random_decision== "rock":
                return (f"You chose {decision}. {self.char} chose {self.random_decision}"
                        f"\nYou win!")

            elif decision == "paper" and self.random_decision== "scissors":
                return (f"You chose {decision}. {self.char} chose {self.random_decision}"
                        f"\nYou lose!")
        else:
            print("This is not a valid input, Try again")
            decision = input("\nrock, paper, or scissors: ")
            return self.decision_making(decision)

    # implementation of the game
    def play_game(self):
        print("Welcome to Rock, Paper, Scissors!")
        self.name = input("What is your name?: ")

        print(f"\nHello {self.name}!")
        print(f"---Today's Battle---")
        print(f"{self.name} vs {self.char}")

        decision = input("\nrock, paper, or scissors: ")
        ans = self.decision_making(decision)

        print(ans)


# main method
if __name__ == "__main__":
    rock_paper_scissors = Game()
    rock_paper_scissors.play_game()


