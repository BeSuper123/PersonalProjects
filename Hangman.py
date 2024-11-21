import random # random function

# class to implement the game hangman
class Hangman:
    def __init__(self): # constructor method
        # creating a list of categories
        self.fruits = ["apple", "pear", "banana", "dragonfruit", "melon", "durian", "watermelon", "grapefruit", "orange", "peach", "plum", "grape", "pomegranate"]
        self.marvel_characters = ["spider man", "iron man", "hulk", "wolverine", "black panther", "deadpool", "black widow", "captain america"]
        self.star_wars_characters = ["anakin skywalker", "han solo", "luke skywalker", "yoda", "darth vader", "storm trooper", "chewbacca"]
        self.disney_movies = ["frozen", "inside out", "encanto", "coco", "monsters inc", "tangled", "aladdin", "toy story"]
        self.anime_characters = ["monkey d luffy", "roronoa zoro" , "nico robin", "ken kaneki", "juuzou suzuya", "izuku midoriya", "shoto todoroki", "katsuki bakugo",
                                "ochaco uraraka", "asta", "satoru gojo", "yuji itadori"]
        self.anime_shows = ["one piece", "black clover", "my hero academia", "jujutsu kaisen", "tokyo ghoul", "blue lock", "spy x family", "demon slayer",
                            "yuri on ice", "attack on titan"]
        self.word = self.randomised_word() # sets the word to a randomised word based on the ones in that method
        self.guesses = 7 # sets the guesses
        self.already_guessed = [] # makes a list to hold all the letters already guessed
        self.acc_word = list(self.word) # makes a list of the letters in word
        self.length = len(self.word) # makes an integer value of the length of the word
        self.guessed = ["_"] * self.length # changes the guessed value to _
        self.g = self.guesses # sets the variable g to the guesses number
        self.clue = 2
        self.letter_found = False
        self.guess = False

    # method to show the hangman loss steps
    def hangman_character(self):
        if self.g - self.guesses == 1: # stage 1
            print("+--------+")
            print("|        |")
            print("|")
            print("|               0    -  (\"uh oh...\")")
            print("|              /|\\     (\"i'm defo getting hung today\")")
            print("|              / \\")
            print("----------")

        elif self.g - self.guesses == 2: # stage 2
            print("+--------+")
            print("|        |")
            print("|        0")
            print("|")
            print("|")
            print("|")
            print("----------")

        elif self.g - self.guesses == 3: # stage 3
            print("+--------+")
            print("|        |")
            print("|        0")
            print("|        |")
            print("|")
            print("|")
            print("----------")

        elif self.g - self.guesses == 4: # stage 4
            print("+--------+")
            print("|        |")
            print("|        0")
            print("|        |\\")
            print("|")
            print("|")
            print("----------")

        elif self.g - self.guesses == 5: # stage 5
            print("+--------+")
            print("|        |")
            print("|        0")
            print("|       /|\\")
            print("|")
            print("|")
            print("----------")

        elif self.g - self.guesses == 6: # stage 6
            print("+--------+")
            print("|        |")
            print("|        0")
            print("|       /|\\")
            print("|         \\")
            print("|")
            print("----------")

        elif self.g - self.guesses == 7: # stage 7
            print("+--------+")
            print("|        |")
            print("|        0")
            print("|       /|\\")
            print("|       / \\")
            print("|")
            print("----------")


    # method to create the random word
    def randomised_word(self):
        # sets the word to be randomised
        all_categories = self.fruits + self.marvel_characters + self.star_wars_characters + self.disney_movies + self.anime_characters + self.anime_shows

        # makes the word whatever the randomised item is
        self.word = random.choice(all_categories)

        # returns the randomised word back into the class
        return self.word


    # method to guess the word out to the terminal
    def guessed_word(self):
        # loop to print either the letter or an underscore
        for i in range(self.length):

            # checks to see if the word contains a whitespace
            if self.acc_word[i] == ' ':
                self.guessed[i] = ' '

            # prints out the current word so far of guessed whether its letters or underscores
            print(self.guessed[i], end="")

    # method to allow the user to reveal a letter to themselves
    def clue_given(self):
        # makes sure the user has clues remaining
        if self.clue > 0:
            # asks the user to pick the number letter they wish to reveal
            num = int(input("Pick the number letter you wish to reveal?: "))
            num = num - 1 # decrements num by 1

            # checks if there is a space in a word to skip it entirely
            if " " in self.acc_word:
                space = 0 # initialising a variable space

                # checks to see where the space is
                for i in range(self.length):
                    if self.acc_word == " ":
                        space = i # adds the value of i to space

                # checks if the number is more than the value in space
                if num > space:
                    num = num + 1 # increments the value by one

            # checks first to see if the space is an underscore
            if self.guessed[num] == "_":
                self.guessed[num] = self.acc_word[num] # adds the letter into the guessed list
                self.guesses = self.guesses - 2 # removes the guesses

                self.guessed_word() # prints the word out with the new letter included

                # lets the user know how many guesses they have remaining
                print(f"\n\nYou now have {self.guesses} guesses left!")
                self.clue = self.clue - 1 # removes a clue

            else:
                # prints to the user that the option they chose is invalid
                print("\n\nThis is an invalid choice, don't go wasting my time")
        else:
            # lets the user know that they ran out of clues and cannot use this method
            print("\n\nYou ran outta clues, gotta figure it out on your own bud...")

    # function to give a hint to the user
    def hint_given(self):
        hint = "" # initialises hint to nothing

        # checks if the word is to do with the genre and prints the corresponding hint
        if self.word in self.fruits:
            hint = "Fruits"

        elif self.word in self.marvel_characters:
            hint = "Marvel Characters"

        elif self.word in self.star_wars_characters:
            hint = "Star Wars Characters"

        elif self.word in self.disney_movies:
            hint = "Disney Movies"

        elif self.word in self.anime_characters:
            hint = "Anime Characters"

        elif self.word in self.anime_shows:
            hint = "Anime Shows"

        # returns hint back to the method
        return hint

# class for the actual game
class Game(Hangman):
    # method for the actual game
    def play_game(self):
        # welcome message for the user
        print("Welcome to Hangman")

        # asks the user to input their name
        name = input("What is Your Name?: ")
        print(f"\nHello {name}!")

        # lets the user know how many guesses they start off with
        print(f"You Have {self.guesses} Guesses")
        print("You get two clues to reveal a letter, but using a clue results in losing two guesses") # tells the user to be careful using clues
        print(f"Guess the Word || Hint: {self.hint_given()}") # gives the user a hint to help them

        # prints out the word so far
        self.guessed_word()
        print("\n")

        # loop to run guess a letter while there are remaining guesses
        while self.guesses != 0 and self.guessed != self.acc_word:
            # allows the user to guess in a letter
            letter = input("Enter in a Letter or Enter \"clue\" for a Clue: ")

            # checks if the user entered in clue
            if letter == "clue":
                self.clue_given() # runs the clue command to give the user the clue
                continue # continues the game

            if letter in [" ", "", "  "]:
                continue # continues the game

            # tells the user that the letter has been entered before
            if letter in self.already_guessed:
                print("\nThis letter has already been guessed")
                continue # continues the game

            # checks if the user entered the correct word
            elif len(letter) != 1:
                if letter == self.word:
                    self.guessed = self.acc_word # makes the guessed word, the random word
                    print("\nCorrect!")
                    continue # continues the game

            # adds the letter to the already guessed list
            self.already_guessed.append(letter)

            # changes the state of letter found to false
            self.letter_found = False

            # loop to check if the letter is in the word
            for i in range(self.length):
                # checks if the letter is in the word
                if letter == self.acc_word[i]:
                    # replaces the underscore with the letter
                    self.guessed[i] = letter
                    self.letter_found = True

            # adds the letter to the already guessed list
            self.already_guessed.append(letter)

            # prints out the word so far
            self.guessed_word()

            # checks if the letter was found
            if self.letter_found == True:
                print("\n\nCorrect!")

            else:
                print("\n\nIncorrect")
                self.guesses = self.guesses - 1 # decrements guesses by 1

                self.hangman_character()

                # prints the amount of guesses left
                print(f"You have {self.guesses} guesses left")

        # checks if the guessed word is the actual word with no clues used and congratulates the player
        if self.guessed == self.acc_word and self.clue < 2:
            print(f"Congratulations {name}! You guessed the word correctly with a bit of help along the way!")
        elif self.guessed == self.acc_word: # congratulates the player on their win
            print(f"Congratulations {name}! You guessed the word correctly!")
        elif self.guesses == 0: # checks if the guesses are at 0
            print(f"Hard Luck {name}! The correct answer was {self.word}!") # prints what the word was


# main function
if __name__ == "__main__":
    # creating the hangman class to run the game
    hangman = Game()
    hangman.play_game()