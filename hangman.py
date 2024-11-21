'''
Description: This program demonstrates making a hangman game

Author: Blessing Ugochukwu

Date: 02/11/23
'''
import random

# List of words for Hangman game
word_list = ["imperium", "eggshell", "programming", "forklift", "random", "hoverman", "maccies", "poohead", "slutina"]
random_word = random.choice(word_list)

# shows the length of the word
size = len(set(random_word))
guessed_letters = set() # Puts an empty list for guessed letters
ans = "K"
i = 0


# Allows user to enter a username
userName = str(input("What's your name?\n"))
print("Hi " +userName +("!"))

# Asks the user if they would like to play the game
while ans != "Y" or ans != "y" or ans != "N" or ans != "n":
    ans = str(input("Would you like to answer a game? [Y/N]: "))
    
    if ans == "Y" or ans == "y" or ans == "N" or ans == "n":
        break
    else:
        print("Please enter either 'Y' or 'N' for this question!\n")
        
# If the user answered 'N'
if ans == "N" or ans == "n":
    print("Have a nice day "+ userName+ "!")

# If the user answered 'Y'
else:
    print("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~")
    print("Welcome to Hangman!\n")
    print("You have 5 lives and you have to guess exactly what the word is.\nGOOD LUCK!!")

    # Only lets you make 5 mistakes
    while i < 5:
        # Displays an '_' if the guess is wrong and the letter if right
        displayed_word = ""
        for letter in random_word:
            if letter in guessed_letters:
                displayed_word += letter
            else:
                displayed_word += "_"
        print(displayed_word)
        
        # Allows the user to guess a letter 
        guess = str(input("\nGuess a letter: "))
        
        if guess not in guessed_letters:
            guessed_letters.add(guess)
            
        # Only adds this part if the guessed letter is not in the word
        if guess not in random_word:
            i = i + 1            
        
        # If all letters are guessed correctly
        if set(random_word).issubset(guessed_letters):
            print("\nCongratulations!! You guessed the word correctly!\nGood Job") #userName)
            break

# Check if the player used all attempts
if i == 5:
    print("\nSorry, you're out of attempts! The word was:", random_word)