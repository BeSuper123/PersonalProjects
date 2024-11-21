/*
    Programs Description: This program creates a who wants to be a milionaire game where the user is:
        (a). Allows the user to make a username
        (b). Allows them to choose their difficulty (easy, medium, hard)
        (c). Allows them to choose what question they want to do
        (d). Checks if they are correct and adds their points to their total
        (e). Shows how many points were racked up and the total prize money

    Author: Blessing Ugochukwu

    Date: 06/12/2023
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define SIZE 100
#define AMOUNT 6

// Global Variables
int qAns;
int i;
bool check = true;
int prizeMoney = 400;
float userName[SIZE];
float easyGuess[SIZE];
float medGuess[SIZE];
float hardGuess[SIZE];
float easyAns = 0;
bool sameNumber = false;
int easyPts = 300;
float medAns = 0;
int medPts = 600;
float hardAns = 0;
int hardPts = 1000;
int totalPoints = 0;


// Method to go over the rules of the game
void rules() {
    // Print statments go over the rules of the game
    printf("RULES\n");
    printf("-> You have to answer %d questions \n-> You can pick a dfficulty of Easy, Medium, or Hard for each question\n", AMOUNT);
    printf("-> To answer a question, you enter the number beside the answer\n");
    printf("-> Easy gives you %d points, medium gives you %d points, and hard gives you %d points \n", easyPts, medPts, hardPts);
    printf("-> If you get a question wrong the game ends and you lose!\n");
} // End method

// Method for the east quesions
void easyQuestions() {
    // Allows the user to pick a question
    while (sameNumber == false) {
        // Print statement to allow the user to pick which question they answer
        printf("\nPlease pick a number from 1 to %d\n--> ", AMOUNT);
        scanf("%f", &easyAns);

        // Checks if the number entered is a duplicate
        for (i = 0; i < AMOUNT; i++) {
            // Checks if the number has been entered previously
            if (easyGuess[i] == easyAns) {
                sameNumber = true;
                break;
            } // End if

        } // End for

        // If the number is not a duplicate, add it to the array
        if (sameNumber == false) {
            // Find the first empty slot in the array     
            for (i = 0; i < AMOUNT; i++) {
                if (easyGuess[i] == 0) {
                    // Breaks the loop
                    break;
                } // End if

            } // End for

            // Add the entered number to the array
            easyGuess[i] = easyAns;

        } // End if

        // Checks if the user entered a valid answer
        if (sameNumber == true) {
            // Print statement for if the number is the same as the one they chose before
            printf("\nYou have already chosen that number, please choose a different one");
            sameNumber = false;
        } else if (easyAns < 1 || easyAns > AMOUNT) {
            // Print statement for if they chose a number out of range
            printf("\nError!");
        } else {
            // Breaks the loop
            break;
        } // End if

    } // End while

    // Displays the question based on the number the user entered
    if (easyAns == 1 && sameNumber == false) {
        // Print statement to show the user the question and the answer options
        printf("\nWhat is the name of the artist that sang watermelon sugar?\n");
        printf("1. Zane Low\n2. Harry Styles\n3. Zayn Malik\n--> ");
        scanf("%d", &qAns);

        // Prints if you got the question right or not
        if (qAns != 2) {
            // Print statement to tell the user what the answer was
            printf("\nYou lose, the answer was Harry Styles :(\n");
            check = false;
        } else {
            // Adds the points earnt into the total points
            totalPoints += easyPts;

            // Print statement to congratulate the user and show how many points they earnt
            printf("\nCongrats %s! You got it right! Your total points amount to %d so far!\n", userName, totalPoints);            
            check = true;
        } // End if

    } else if (easyAns == 2 && sameNumber == false) {
        // Print statement to show the user the question and the answer options
        printf("\nWhat is the name of the largest ocean in the world?\n");
        printf("1. Atlantic\n2. Pacific\n--> ");
        scanf("%d", &qAns);

        // Prints if you got the question right or not
        if (qAns != 2) {
            // Print statement to tell the user what the answer was
            printf("\nYou lose, the answer was Pacific :(\n");
            check = false;
        } else {
            // Adds the points earnt into the total points
            totalPoints += easyPts;

            // Print statement to congratulate the user and show how many points they earnt
            printf("\nCongrats %s! You got it right! Your total points amount to %d so far!\n", userName, totalPoints);           
            check = true;
        } // End if

    } else if (easyAns == 3 && sameNumber == false) {
        // Print statement to show the user the question and the answer options
        printf("\nHow many reindeer does santa have?\n");
        printf("1. 6\n2. 7\n3. 8\n--> ");
        scanf("%d", &qAns);

        // Prints if you got the question right or not
        if (qAns != 3) {
            // Print statement to tell the user what the answer was
            printf("\nYou lose, the answer was 8 :(\n");
            check = false;
        } else {
            // Adds the points earnt into the total points          
            totalPoints += easyPts;

            // Print statement to congratulate the user and show how many points they earnt
            printf("\nCongrats %s! You got it right! Your total points amount to %d so far!\n", userName, totalPoints);
            check = true;
        } // End if

    } else if (easyAns == 4 && sameNumber == false) {
        // Print statement to show the user the question and the answer options
        printf("\nWhat do you call a shape with 5 sides?\n");
        printf("1. Hexagon\n2. Octagon\n3. Pentagon\n--> ");
        scanf("%d", &qAns);

        // Prints if you got the question right or not
        if (qAns != 3) {
            // Print statement to tell the user what the answer was
            printf("\nYou lose, the answer was Pentagon :(\n");
            check = false;
        } else {
            // Adds the points earnt into the total points
            totalPoints += easyPts;

            // Print statement to congratulate the user and show how many points they earnt
            printf("\nCongrats %s! You got it right! Your total points amount to %d so far!\n", userName, totalPoints);
            check = true;
        } // End if

    } else if (easyAns == 5 && sameNumber == false) {
        // Print statement to show the user the question and the answer options
        printf("\nWho is the founder of Microsoft?\n");
        printf("1. Mark Zuckerburg\n2. Bill Gates\n3. Elon Musk\n--> ");
        scanf("%d", &qAns);

        // Prints if you got the question right or not
        if (qAns != 2) {
            // Print statement to tell the user what the answer was
            printf("\nYou lose, the answer was Bill Gates :(\n");
            check = false;
        } else {
            // Adds the points earnt into the total points
            totalPoints += easyPts;

            // Print statement to congratulate the user and show how many points they earnt
            printf("\nCongrats %s! You got it right! Your total points amount to %d so far!\n", userName, totalPoints);
            check = true;
        } // End if

    } else if (easyAns == 6 && sameNumber == false) {
        // Print statement to show the user the question and the answer options
        printf("\nHow many dots are there on a die?\n");
        printf("1. 25\n2. 21\n3. 19\n--> ");
        scanf("%d", &qAns);

        // Prints if you got the question right or not
        if (qAns != 2) {
            // Print statement to tell the user what the answer was
            printf("\nYou lose, the answer was 21 :(\n");
            check = false;
        } else {
            // Adds the points earnt into the total points
            totalPoints += easyPts;

            // Print statement to congratulate the user and show how many points they earnt
            printf("\nCongrats %s! You got it right! Your total points amount to %d so far!\n", userName, totalPoints);
            check = true;
        } // End if
    }

}

// Method for the medium questions
void mediumQuestions() {
    // Allows the user to pick a question
    while (sameNumber == false) {
        // Print statement to allow the user to pick which question they answer
        printf("\nPlease pick a number from 1 to %d\n--> ", AMOUNT);
        scanf("%f", &medAns);

        // Checks if the number entered is a duplicate
        for (i = 0; i < AMOUNT; i++) {
            // Checks if the number has been entered previously
            if (medGuess[i] == medAns) {
                sameNumber = true;
                break;
            } // End if
            
        } // End for

        // If the number is not a duplicate, add it to the array
        if (sameNumber == false) {
            // Find the first empty slot in the array     
            for (i = 0; i < AMOUNT; i++) {
                if (medGuess[i] == 0) {
                    // Breaks the loop
                    break;
                } // End if

            } // End for

            // Add the entered number to the array
            medGuess[i] = easyAns;

        } // End if

        // Checks if the user entered a value that they entered before
        if (sameNumber == true) {
            // Print statement for if the number is the same as the one they chose before
            printf("\nYou have already chosen that number, please choose a different one");
            sameNumber = false;
        } else if (medAns < 1 || medAns > AMOUNT) {
            // Print statement for if they chose a number out of range
            printf("\nError!");
        } else {
            // Breaks the loop
            break;
        } // End if

    } // End while

    // Displays the question based on the number the user entered
    if (medAns == 1 && sameNumber == false) {
        // Print statement to show the user the question and the answer options
        printf("\nWhat is the rarest blood type?\n");
        printf("1. AB Negative\n2. AB Positive\n3. O Positive\n--> ");
        scanf("%d", &qAns);

        // Prints if you got the question right or not
        if (qAns != 1) {
            // Print statement to tell the user what the answer was
            printf("\nYou lose, the answer was AB Negative :(\n");
            check = false;
        } else {
            // Adds the points earnt into the total points
            totalPoints += medPts;

            // Print statement to congratulate the user and show how many points they earnt
            printf("\nCongrats %s! You got it right! Your total points amount to %d so far!\n", userName, totalPoints);
            check = true;
        } // End if

    } else if (medAns == 2 && sameNumber == false) {
        // Print statement to show the user the question and the answer options
        printf("\nWhat is the name of Harry Potter's pet owl?\n");
        printf("1. Hedgewin\n2. Humpfrey\n3. Hedwig\n--> ");
        scanf("%d", &qAns);

        // Prints if you got the question right or not
        if (qAns != 3) {
            // Print statement to tell the user what the answer was
            printf("\nYou lose, the answer was Hedwig :(\n");
            check = false;
        } else {
            // Adds the points earnt into the total points
            totalPoints += medPts;

            // Print statement to congratulate the user and show how many points they earnt
            printf("\nCongrats %s! You got it right! Your total points amount to %d so far!\n", userName, totalPoints);
            check = true;
        } // End if

    } else if (medAns == 3 && sameNumber == false) {
        // Print statement to show the user the question and the answer options
        printf("\nHow many bones in the human body?\n");
        printf("1. 206\n2. 204\n3. 205\n--> ");
        scanf("%d", &qAns);

        // Prints if you got the question right or not
        if (qAns != 1) {
            // Print statement to tell the user what the answer was
            printf("\nYou lose, the answer was 206 :(\n");
            check = false;
        } else {
            // Adds the points earnt into the total points
            totalPoints += medPts;

            // Print statement to congratulate the user and show how many points they earnt
            printf("\nCongrats %s! You got it right! Your total points amount to %d so far!\n", userName, totalPoints);
            check = true;
        } // End if

    } else if (medAns == 4 && sameNumber == false) {
        // Print statement to show the user the question and the answer options
        printf("\nWhat is the name of Shakespears shortest tragedy?\n");
        printf("1. Othello\n2. Macbeth\n--> ");
        scanf("%d", &qAns);

        // Prints if you got the question right or not
        if (qAns != 2) {
            // Print statement to tell the user what the answer was
            printf("\nYou lose, the answer was Macbeth :(\n");
            check = false;
        } else {
            // Adds the points earnt into the total points
            totalPoints += medPts;

            // Print statement to congratulate the user and show how many points they earnt
            printf("\nCongrats %s! You got it right! Your total points amount to %d so far!\n", userName, totalPoints);
            check = true;
        } // End if

    } else if (medAns == 5 && sameNumber == false) {
        // Print statement to show the user the question and the answer options
        printf("\nWho sang the song 'you belong with me'?\n");
        printf("1. Mimi Webb\n2. Tate McRae\n3. Taylor Swift\n--> ");
        scanf("%d", &qAns);

        // Prints if you got the question right or not
        if (qAns != 3) {
            // Print statement to tell the user what the answer was
            printf("\nYou lose, the answer was Taylor Swift >:(\n");
            check = false;
        } else {
            // Adds the points earnt into the total points
            totalPoints += medPts;

            // Print statement to congratulate the user and show how many points they earnt
            printf("\nCongrats %s! You got it right! Your total points amount to %d so far!\n", userName, totalPoints);
            check = true;
        } // End if

    } else if (medAns == 6 && sameNumber == false) {
        // Print statement to show the user the question and the answer options
        printf("\nWhat year was the first iPhone released?\n");
        printf("1. 2006\n2. 2007\n3. 2009\n--> ");
        scanf("%d", &qAns);

        // Prints if you got the question right or not
        if (qAns != 2) {
            // Print statement to tell the user what the answer was
            printf("\nYou lose, the answer was 2007\n");
            check = false;
        } else {
            // Adds the points earnt into the total points
            totalPoints += medPts;

            // Print statement to congratulate the user and show how many points they earnt
            printf("\nCongrats %s! You got it right! Your total points amount to %d so far!\n", userName, totalPoints);
            check = true;
        } // End if

    } // End if

} // End method

// Method for the hard questions
void hardQuestions() {
    // Allows the user to pick a question
    while (sameNumber == false) {
        // Print statement to allow the user to pick which question they answer
        printf("\nPlease pick a number from 1 to %d\n--> ", AMOUNT);
        scanf("%f", &hardAns);

        // Checks if the number entered is a duplicate
        for (i = 0; i < AMOUNT; i++) {
            // Checks if the number has been entered previously
            if (hardGuess[i] == hardAns) {
                sameNumber = true;
                break;
            } // End if
            
        } // End for

        // If the number is not a duplicate, add it to the array
        if (sameNumber == false) {
            // Find the first empty slot in the array     
            for (i = 0; i < AMOUNT; i++) {
                if (hardGuess[i] == 0) {
                    // Breaks the loop
                    break;
                } // End if

            } // End for

            // Add the entered number to the array
            hardGuess[i] = hardAns;

        } // End if

        // Checks if the user entered a value that they entered before
        if (sameNumber == true) {
            // Print statement for if the number is the same as the one they chose before
            printf("\nYou have already chosen that number, please choose a different one");
            sameNumber = false;
        } else if (hardAns < 1 || hardAns > AMOUNT) {
            // Print statement for if they chose a number out of range
            printf("\nError!");
        } else {
            // Breaks the loop
            break;
        } //End if

    } // End while

    // Displays the question based on the number the user entered
    if (hardAns == 1 && sameNumber == false) {
        // Print statement to show the user the question and the answer options
        printf("\nWhich U.S State is the largest?\n");
        printf("1. Alaska\n2. Atlanta\n3. Hawaii\n--> ");
        scanf("%d", &qAns);

        // Prints if you got the question right or not
        if (qAns != 1) {
            // Print statement to tell the user what the answer was
            printf("\nYou lose, the answer was Alaska :(\n");
            check = false;
        } else {
            // Adds the points earnt into the total points
            totalPoints += hardPts;

            // Print statement to congratulate the user and show how many points they earnt
            printf("\nCongrats %s! You got it right! Your total points amount to %d so far!\n", userName, totalPoints);
            check = true;
        } // End if

    } else if (hardAns == 2 && sameNumber == false) {
        // Print statement to show the user the question and the answer options
        printf("\nWhat is the name of the Social Media Platform that came out in 2003?\n");
        printf("1. Vine\n2. MySpace\n3. Friendster\n--> ");
        scanf("%d", &qAns);

        // Prints if you got the question right or not
        if (qAns != 2) {
            // Print statement to tell the user what the answer was
            printf("\nYou lose, the answer was MySpace :(\n");
            check = false;
        } else {
            // Adds the points earnt into the total points
            totalPoints += hardPts;

            // Print statement to congratulate the user and show how many points they earnt
            printf("\nCongrats %s! You got it right! Your total points amount to %d so far!\n", userName, totalPoints);
            check = true;
        } // End if

    } else if (hardAns == 3 && sameNumber == false) {
        // Print statement to show the user the question and the answer options
        printf("\nWhat year did Barbie come out?\n"); 
        printf("1. 1974\n2. 1982\n3. 1959\n--> ");
        scanf("%d", &qAns);

        // Prints if you got the question right or not
        if (qAns != 3) {
            // Print statement to tell the user what the answer was
            printf("\nYou lose, the answer was 1959 :(\n");
            check = false;
        } else {
            // Adds the points earnt into the total points
            totalPoints += hardPts;

            // Print statement to congratulate the user and show how many points they earnt
            printf("\nCongrats %s! You got it right! Your total points amount to %d so far!\n", userName, totalPoints);
            check = true;
        } // End if

    } else if (hardAns == 4 && sameNumber == false) {
        // Print statement to show the user the question and the answer options
        printf("\nWhat does the Roman Numeral 'M' stand for?\n");
        printf("1. 100\n2. 10000\n3. 1000\n--> ");
        scanf("%d", &qAns);

        // Prints if you got the question right or not
        if (qAns != 3) {
            // Print statement to tell the user what the answer was
            printf("\nYou lose, the answer was 1000 :(\n");
            check = false;
        } else {
            // Adds the points earnt into the total points
            totalPoints += hardPts;

            // Print statement to congratulate the user and show how many points they earnt
            printf("\nCongrats %s! You got it right! Your total points amount to %d so far!\n", userName, totalPoints);
            check = true;
        } // End if

    } else if (hardAns == 5 && sameNumber == false) {
        // Print statement to show the user the question and the answer options
        printf("\nWhat is the rarest M&M colour?\n");
        printf("1. Green\n2. Brown\n3. Red\n--> ");
        scanf("%d", &qAns);

        // Prints if you got the question right or not
        if (qAns != 2) {
            // Print statement to tell the user what the answer was
            printf("\nYou lose, the answer was Brown :(\n");
            check = false;
        } else {
            // Adds the points earnt into the total points
            totalPoints += hardPts;

            // Print statement to congratulate the user and show how many points they earnt
            printf("\nCongrats %s! You got it right! Your total points amount to %d so far!\n", userName, totalPoints);
            check = true;
        } // End if

    } else if (hardAns == 6 && sameNumber == false) {
        // Print statement to show the user the question and the answer options
        printf("\nWhat is Joe Biden's middle name?\n");
        printf("1. Richard\n2. Ranson\n3. Robinette\n--> ");
        scanf("%d", &qAns);

        // Prints if you got the question right or not
        if (qAns != 3) {
            // Print statement to tell the user what the answer was
            printf("\nYou lose, the answer was Robinette :(\n");
            check = false;
        } else {
            // Adds the points earnt into the total points
            totalPoints += hardPts;

            // Print statement to congratulate the user and show how many points they earnt
            printf("\nCongrats %s! You got it right! Your total points amount to %d so far!\n", userName, totalPoints);
            check = true;
        } // End if

    } // End if

} // End method

// Method for the game
void game() {
    int Qnumber = 1;
    int ans;


    // Allows the user to create a name for themselves
    printf("Hello there, What shall I call you?\n--> ");
    scanf("%[^\n]", userName);

    // Greets the user
    printf("\nHi %s\n", userName);
    printf("\nWelcome to Who Wants To Be a Millionaire!!\n");
    
    // Prints out the contents of the rules() method
    rules();
    
    // Loops while the question number is lower than the amount of questions
    while (Qnumber <= AMOUNT) {
        // Allows the user to enter a number for what type of question they would like to do
        printf("\n\nQuestion %d, Please enter 1 for easy, 2 for medium, or 3 for hard\n--> ", Qnumber);
        scanf("%d", &ans);

        // Gives the user their question based on the number entered
        if (ans == 1) {
            // Prints out the contents of the easyQuestions() method and adds 1 to Qnumber
            easyQuestions();
            Qnumber = Qnumber + 1; 
        } else if (ans == 2) {
            // Prints out the contents of the mediumQuestions() method and adds 1 to Qnumber
            mediumQuestions();
            Qnumber = Qnumber + 1;
        } else if (ans == 3) {
            // Prints out the contents of the hardQuestions() method and adds 1 to Qnumber
            hardQuestions();
            Qnumber = Qnumber + 1;
        } else {
            // Print statement to tell the user the number they entered is invalid
            printf("\nThis is not an option, please try again!\n");
        } // End if
        
        // Checks if the check variable is false
        if (check == false) {
            break;
        } // End if

    } // End while

    // Checks if the check variable is not false
    if (check != false) {
        // Checks if total money is up to a million
        if ((totalPoints * prizeMoney) < 1000000) {
            // Print statement to let the user know how much they earned
            printf("\nYour Earnings: %d", (totalPoints * prizeMoney));
            // Print statement to tell the user that they lost the game
            printf("\nYou didn't become a millionaire this time :(");
        } else {
            // Print statement to congratulate the user and let them know their final score and prize money
            printf("\nCongratulations %s, You have won who wants to be a millionaire!!\nYou reached a total of %d points throughout which means you won %d euro!!", userName, totalPoints,(totalPoints * prizeMoney));
        } // End if
        
    } else {
        // Print statement to let the user know they lost the game
        printf("\nYou didn't become a millionaire this time :(");
    } // End if

} // End method

// Main method
int main() {
    // Outputs the game 
    game();
} // End Program