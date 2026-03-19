#include <stdio.h>
#include <stdlib.h>
#include "student.h"
#include "twins.h"
#include "utils.h"

int main() {
    int choice;
    STUD students[MAX_STUDENTS];
    
    do {
        printMenu();
        choice = getValidIntInput("", 1, 3);
        
        switch(choice) {
            case 1: {
                // Задача с числами-близнецами
                int limit = getValidIntInput("Enter upper limit: ", 2, 1000);
                findTwinPrimes(limit);
                break;
            }
            
            case 2: {
                // Работа со студентами
                printf("\n=== Enter data for %d students ===\n", MAX_STUDENTS);
                
                // Ввод данных
                for(int i = 0; i < MAX_STUDENTS; i++) {
                    inputStudent(&students[i], i);
                }
                
                // Сортировка по алфавиту
                sortStudentsByName(students, MAX_STUDENTS);
                
                printf("\n=== Sorted by name ===\n");
                for(int i = 0; i < MAX_STUDENTS; i++) {
                    printStudent(&students[i]);
                }
                
                // Вывод студентов с баллом > 4.2
                printHighAchievers(students, MAX_STUDENTS);
                break;
            }
            
            case 3:
                printf("Exiting program...\n");
                break;
        }
        
    } while(choice != 3);
    
    return 0;
}
