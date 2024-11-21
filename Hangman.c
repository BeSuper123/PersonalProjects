/*
Programs Description: This program demonstrates using functions and strings to make a hangman game

Author: Blessing Ugochukwu

Date: 12/02/24
*/
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

#define ROW 7
#define COL 20
#define COUNT 20

// function assignments
void guessingGame(char *);
void guessedWords(char *, int);

int main() {
    int i;
    char words[ROW][COL] = {"apple", "pear", "mango", "pineapple", "dragonfruit", "melon", "watermelon"};


    printf("Welcome to Hangman!\n\n");
    srand(time(NULL));
    i = rand() % ROW;
    
    guessingGame(words[i]);

    return 0;
}

void guessedWords(char *word, int length) {
    int i;


    printf("\n");
    for (i = 0; i < length; i++) {
        printf("%c ", word[i]);
    } 
}

void guessingGame(char *word) {
    int i, j = 0;
    int length = strlen(word);
    int count = 0;
    char guesses[COUNT];
    char guessedWord[length];
    char guessLetter, win = 0;


    for (i = 0; i < length; i++) {
        guessedWord[i] = '_';
    } 

    printf("Hint: fruit\n");
    for (i = 0; i < length; i++) {
        printf("%c ", guessedWord[i]);
    } 

    while (win != 1 && count < 10) {
        printf("\n\n\nGuess a Letter \n-----> ");
        scanf(" %c", &guessLetter);

        for (i = 0; i < length; i++) {
            if (guessLetter == word[i]) {
                guessedWord[i] = guessLetter;;
            } else if (strcmp(guessedWord, word) == 0) {
                win = 1;
            }
        } 


        guesses[j] = guessLetter;
        j++;
        count = count + 1;

        if (win != 1) {
            guessedWords(guessedWord, length);
        }

    } 

    if (count == 10) {
        printf("\n\nYou Lose! The Word was %s", word);
    } else if (win == 1) {
        printf("\n\nCongratulations You Guessed Correctly!");
    }

}

