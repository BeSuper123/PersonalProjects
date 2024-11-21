/*
Programs Description: This program demonstrates
    (a) creating methods that multiply, add and subtract modded numbers
    (b) asking for an integer
    (C) calculating and creates a table showing the numbers in the table order using the user inputted integer

Author: Blessing Ugochukwu

Date: 02/02/24
*/
#include <stdio.h>

// function assignments
void calculations(int);
void addition(int, int, int);
void subtraction(int, int, int);
void multiplication(int, int, int);


int main() {
    int num1;
    int z = 1;


    // while the user has not entered 0
    while (z != 0) {
        // asks the user to enter an integer
        printf("Enter an integer: \n");
        scanf("%d", &num1);

        // finds the addition value of the integer entered
        calculations(num1);

        // calculates and prints all the values of the method
        printf("\nWould you like to try another number? \n[Enter any Number for Yes, 0 to End Program]: ");
        scanf("%d", &z);
        printf("\n");
    } // end while

} // end main ()


// calculates and prints all the values of the method
void calculations(int z1) {
    int i, j;
    int ans = 0;


    // while the user has not chosen any of the options
    while (ans > 3 || ans < 1) {
        printf("\nEnter: \n1 for Addition \n2 for Multiplication \n3 for Subtraction\n--> ");
        scanf("%d", &ans);
    } // end while

    printf("\n");

    // prints the header row
    printf("+ | ");
    for (i = 0; i < z1; i++) {
        printf("%d  ", i);
    } // end for

    printf("\n");

    // prints a seperator line
    for (i = 0; i < ((z1 * 3) + 2); i++) {
        printf("-");
    } // end for

    printf("\n");

    // prints the main pattern
    for (i = 0; i < z1; i++) {
        // prints row label
        printf("%d | ", i);
        
        // prints the values in the row
        for (j = 0; j < z1; j++) {
            if (ans == 1) {
                addition(z1, i, j);
            } else if (ans == 2) {
                multiplication(z1, i, j);
            } else if (ans == 3) {
                subtraction(z1, i, j);
            } // end if

        } // end for

        printf("\n");
    } // end for

} // end calculations()


// finds the addition value
void addition(int z1, int i, int j) {
    // prints the values in the row
    printf("%d  ", ((i + j) % z1));
} // end addition()


// finds the multiplication value
void multiplication(int z1, int i, int j) {
    // prints the values in the row
    printf("%d  ", ((i * j) % z1));
} // end multiplication()


// finds the subtraction value
void subtraction(int z1, int i, int j) {
    // prints the values in the row
    printf("%d  ", ((i - j) % z1));
} // end subtraction()