/*
Programs Description: This program demonstrates
    (a) creating a method called EuclidAlg1()
    (b) asking for 2 integer numbers
    (C) calculating and returning the gcd value using the user inputted integers

Author: Blessing Ugochukwu

Date: 01/02/24
*/
#include <stdio.h>

// function assignment
int EuclidAlg1(int, int);


int main() {
    int a, b, gcd;


    // asks the user to enter 2 integers
    printf("Enter 2 integers: \n");
    scanf("%d", &a);
    scanf("%d", &b);

    // puts the numbers entered in a different order depending on which value is larger
    if (a > b) {
        gcd = EuclidAlg1(a, b);
    } else {
        gcd = EuclidAlg1(b, a);
    } // end if

    // prints the integers entered and the gcd value of them
    printf("\n\nGCD(%d, %d) = %d", a, b, gcd);

} // end main() 

// finds the gcd value using Euclidean Algorithm I
int EuclidAlg1(int a, int b) {
    int q; 
    int gcd;
    int r = 1;

    // makes the gcd the value of b incase there is no remainder
    gcd = b;

    // repeats until the remainder reaches 0
    while (r > 0) {
        // to find the quotient value
        q = a / b;

        // changes the value of the gcd
        gcd = b;

        // the algorithm to find the gcd
        r = a - (q * b);
        printf("\n%d = %d(%d) + %d", a, q, b, r);

        // changes the values of a and b to find the next remainder
        a = b;
        b = r;
    } // end while

    // returns the gcd value of the integers entered
    return gcd;

} // end EuclidAlg1() 