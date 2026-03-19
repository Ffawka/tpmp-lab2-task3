#include <stdio.h>
#include "utils.h"

void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void printMenu() {
    printf("\n===== MENU =====\n");
    printf("1. Find twin primes\n");
    printf("2. Work with students\n");
    printf("3. Exit\n");
    printf("Choice: ");
}

int getValidIntInput(const char* prompt, int min, int max) {
    int value;
    int valid;
    
    do {
        printf("%s", prompt);
        valid = scanf("%d", &value);
        
        if(valid != 1) {
            printf("Invalid input! Please enter a number.\n");
            clearInputBuffer();
            valid = 0;
        } else if(value < min || value > max) {
            printf("Please enter a number between %d and %d.\n", min, max);
            valid = 0;
        }
    } while(!valid);
    
    return value;
}
