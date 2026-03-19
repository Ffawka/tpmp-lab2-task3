#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "student.h"

void inputStudent(STUD *s, int index) {
    printf("\n--- Student %d ---\n", index + 1);
    printf("Enter name (surname and initials): ");
    scanf(" %[^\n]", s->name);
    
    printf("Enter group (faculty, course, group number): ");
    scanf(" %[^\n]", s->group);
    
    printf("Enter grades for %d subjects:\n", SUBJECTS);
    for(int i = 0; i < SUBJECTS; i++) {
        printf("Subject %d: ", i + 1);
        scanf("%d", &s->ses[i]);
    }
    
    s->average = calculateAverage(s->ses);
    s->original_index = index;
}

void printStudent(const STUD *s) {
    printf("Name: %s\n", s->name);
    printf("Group: %s\n", s->group);
    printf("Grades: ");
    for(int i = 0; i < SUBJECTS; i++) {
        printf("%d ", s->ses[i]);
    }
    printf("\nAverage: %.2f\n", s->average);
    printf("Original position: %d\n", s->original_index + 1);
    printf("------------------------\n");
}

float calculateAverage(const int *ses) {
    float sum = 0;
    for(int i = 0; i < SUBJECTS; i++) {
        sum += ses[i];
    }
    return sum / SUBJECTS;
}

// Функция сравнения для сортировки по имени (алфавиту)
int compareByName(const void *a, const void *b) {
    STUD *studentA = (STUD *)a;
    STUD *studentB = (STUD *)b;
    return strcmp(studentA->name, studentB->name);
}

// Функция сравнения для сортировки по среднему баллу
int compareByAverage(const void *a, const void *b) {
    STUD *studentA = (STUD *)a;
    STUD *studentB = (STUD *)b;
    
    if (studentA->average < studentB->average) return -1;
    if (studentA->average > studentB->average) return 1;
    return 0;
}

void sortStudentsByName(STUD *students, int count) {
    qsort(students, count, sizeof(STUD), compareByName);
}

void printHighAchievers(STUD *students, int count) {
    // Создаем временный массив для студентов с баллом > 4.2
    STUD highAchievers[MAX_STUDENTS];
    int highCount = 0;
    
    // Отбираем студентов со средним баллом > 4.2
    for(int i = 0; i < count; i++) {
        if(students[i].average > 4.2) {
            highAchievers[highCount] = students[i];
            highCount++;
        }
    }
    
    if(highCount == 0) {
        printf("\nNo students with average grade > 4.2\n");
        return;
    }
    
    // Сортируем по возрастанию среднего балла
    qsort(highAchievers, highCount, sizeof(STUD), compareByAverage);
    
    printf("\n=== Students with average grade > 4.2 (sorted by average) ===\n");
    for(int i = 0; i < highCount; i++) {
        printStudent(&highAchievers[i]);
    }
}
