/*
Programs Description: This program demonstrates decoding sentence based on the key given.

Author: Blessing Ugochukwu

Date: 08/02/24
*/
#include <stdio.h>
#include <string.h>

#define SIZE 26

// function assignments
void decoding(char [], int);

int main() {
    char word[SIZE];
    int key;


    printf("Enter the Message to Decode: \n");
    scanf("%[^\n]", word);

    printf("\nEnter the key for this word: ");
    scanf("%d", &key);

    decoding(word, key);
}

void decoding(char word[], int k) {
    int i, j;
    int length = strlen(word);
    char c1;


    for (i = 0; i < length; i++) {
        c1 = word[i];

        if ((c1 >= 'A' && c1 <= 'Z')) {
            word[i] = ((c1 - 'A' - k) % SIZE) + 'A';
        } else if ((c1 >= 'a' && c1 <= 'z')) {
            word[i] = ((c1 - 'a' - k) % SIZE) + 'a';
        }
    }


    printf("\nDecoded Word: %s", word);
}