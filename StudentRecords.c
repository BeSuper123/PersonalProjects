/*
Programs Description: This program demonstrates using structures to hold variables and display structures

Author: Blessing Ugochukwu

Date: 07/03/24
*/
#include <stdio.h>

#define SIZE 40
#define PUPILS 5

// structure templates
struct studentRec {
    int studentID;
    char firstname[SIZE];
    char surname[SIZE];
    char course[SIZE];
};

struct teacherRec {
    int teacherID;
    char firstname[SIZE];
    char surname[SIZE];
};


// function assignments
void display(struct studentRec);
void allDisplay(struct studentRec students[], struct teacherRec principal);


int main() {
    int userAnswer, i;
    char ans;
    struct studentRec students[PUPILS] = {
        {12345, "Blessing", "Ugochukwu", "Computer Science Infrastructure"},
        {12468, "Bartek", "Sobiegraj", "Computer Science Infrastructure"},
        {13579, "Rebecca", "Bowe", "Computer Science International"},
        {14702, "Renee", "Low", "Computer Science Infrastructure"},
        {15936, "Daniel", "Courage", "Computer Science International"}
    };

    struct teacherRec principal = {
        11111,
        "Katara",
        "Shivers"
    };
    

    // asks the user to enter in their ID
    printf("Please Enter ID: ");
    scanf("%d", &userAnswer);

    // loops to see if the ID is in file
    for (i = 0; i < PUPILS; i++) {
        // checks if  the user is in file
        if (students[i].studentID == userAnswer) {
            // greet the user and asks if they would like to see their records
            printf("\nHello %s, \nWould you like to see your student records? [y/n]\n--> ", students[i].firstname);
            scanf(" %c", &ans);
            break;

        } else if (principal.teacherID == userAnswer) {
            // greet the user and asks if they would like to see the records
            printf("\nHello Principal %s, \nWould you like to see current records? [y/n]\n--> ", principal.surname);
            scanf(" %c", &ans);
            break;

        } // end if

    } // end for
    
    // checks if 
    if (ans == 'y' || ans == 'Y') {
        // checks if the user would like to see their records
        if (i < PUPILS && students[i].studentID == userAnswer) {
            // displays the contents of the structured variable students depending on what i is
            display(students[i]);

        } else if (principal.teacherID == userAnswer) {
            // displays either the principal records or all students records
            allDisplay(students, principal);

        } // end inner if

    } // end outer if

    // checks if the user still was not found
    if (i == PUPILS && principal.teacherID != userAnswer) {
        // prints if there was no user found
        printf("\nUser Not Found");

    } // end if

    return 0;

} // end main

// displays a given students name
void display(struct studentRec stu) {

    // prints student record
    printf("\t**Student Record**\n");
    printf("\tStudent ID: %d \n\tName: %s %s \n\n\tCourse: %s", stu.studentID, stu.firstname, stu.surname, stu.course);
    
} // end display

void allDisplay(struct studentRec stus[], struct teacherRec principal) {
    char ans;
    int i;


    // asks the user if they
    printf("\nWould you like to see your own or the student ones? [y for own/s for students]\n--> ");
    scanf(" %c", &ans);

    // checks if the user entered in 'y' or 's'
    if (ans == 'y') {
        // prints the principals records
        printf("\t**Principal Records**\n");
        printf("\tTeacher ID: %d \n\tName: %s %s\n", principal.teacherID, principal.firstname, principal.surname);

    } else if (ans == 's') {
        //prints all the student records
        printf("\t**Student Record**\n");
        for (i = 0; i < PUPILS; i++) {
            // prints each record per student
            printf("\tStudent ID: %d \n\tName: %s %s \n\tCourse: %s\n\n", stus[i].studentID, stus[i].firstname, stus[i].surname, stus[i].course);

        } // end for

    } else {
        // prints if the user dID not enter the correct character
        printf("\nInvalID input.");

    } // end if

} // end allDisplay