#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10

// function assignment
void game(char *);

int main() {
    char choice[SIZE], word[SIZE];
    int i, outcome = 0;


    // allows the user to play the game
    game(choice);
    

} // end main

// allows the user to pick an option and to see if they win or not
void game(char *choice) {
    int random, outcome = 0;
    char word[SIZE];


    // randomises a number between 0 and 3
    srand(time(NULL));
    random = rand() % 3;

    // assigns a word to 'word' based on the randomised number
    if (random == 0) {
        strcpy(word, "rock\n");

    } else if (random == 1) {
        strcpy(word, "paper\n");

    } else if (random == 2) {
        strcpy(word, "scissors\n");

    } // end if

    // allows the user to enter in rock, paper or scissors
    printf("Enter in rock, paper, or scissors: \n");
    fgets(choice, SIZE, stdin);

    // prints what the randomised word is
    printf("\nOpponent used %s", word);

    // checks if the user entered in rock
    if (strcmp(choice, "rock\n") == 0) {
        // checks if the random word is paper and changes the value of outcome
        if (strcmp(word, "paper\n") == 0) {
            outcome = 2;
                
        // checks if the random word is scissors and changes the value of outcome
        } else if (strcmp(word, "scissors\n") == 0) {
            outcome = 1;

        } // end inner if

    } // end outer if

    // checks if the user entered in paper
    if (strcmp(choice, "paper\n") == 0) {
        // checks if the random word is scissors and changes the value of outcome
        if (strcmp(word, "scissors\n") == 0) {
            outcome = 2;

        // checks if the random word is rock and changes the value of outcome
        } else if (strcmp(word, "rock\n") == 0) {
            outcome = 1;

        } // end inner if

    } // end outer if

    // checks if the user entered in scissors
    if (strcmp(choice, "scissors\n") == 0) {
        // checks if the random word is rocm and changes the value of outcome
        if (strcmp(word, "rock\n") == 0) {
            outcome = 2;

        // checks if the random word is paper and changes the value of outcome
        } else if (strcmp(word, "paper\n") == 0) {
            outcome = 1;

        } // end inner if

    } // end outer if

    // checks if the two words are the same
    if (strcmp(word, choice) == 0) {
        // asks the user to start again
        game(choice);

    } // end if

    // if the outcome is 1, the user wins
    if (outcome == 1) {
        printf("You Win");
    
    // if the outcome is 2, the user loses
    } else if (outcome == 2) {
        printf("You Lose");

    } // end if

} // end game