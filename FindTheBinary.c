/*
Programs Description: This program demonstrates taking in an integer and prints the binary version.

Author: Blessing Ugochukwu

Date: 05/02/24
*/
#include <stdio.h>

#define BINARY 10

// function assignments
void convertToBinary(int);

int main() {
    int num1;
    char ans = ' ';


    while (ans != '0') {
        // allows the user to enter positive integer
        printf("Enter an positive integer: ");
        scanf("%d", &num1);

        // finds the binary form of num1
        convertToBinary(num1);

        // allows the user to choose if they would like to enter another number or end the program
        printf("\n\nWould you like to end the program? \n[Press Enter] [Enter 0 to end]: ");
        while (getchar() != '\n');
        scanf("%c", &ans);
    } // end while

} // end main

// finds the binary number of the user inputted integer
void convertToBinary(int n1) {
    int conversion = 2;
    int r = 2;
    int binary = 0;


    // loops until r is bigger than n1
    while (n1 > r) {
        // multiplies the value of r by 2
        r = r * 2;

        // 
        if (n1 > r) {
            conversion = r;
        } // end if
    }

    // loop runs while conversion isn't equal to 0
    while (conversion != 0) {
        // checks if the user input is less or equal to conversion
        if (n1 >= conversion) {
            binary = binary * BINARY + 1;
            n1 = n1 - conversion;
        } else {
            binary = binary * BINARY;
        } // end if

        // divides the variable by 2 until it reaches 0 (e.g., 16, 8, 4,...)
        conversion = conversion / 2;
    } // end while

    // prints the binary of the code inputted
    printf("Binary: %d", binary);
} // end convertoBinary()