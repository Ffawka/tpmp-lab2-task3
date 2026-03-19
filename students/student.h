
#ifndef STUDENT_H
#define STUDENT_H

#define SUBJECTS 4
#define MAX_STUDENTS 10
#define NAME_LEN 50
#define GROUP_LEN 30

typedef struct {
    char name[NAME_LEN];        // Фамилия и инициалы
    char group[GROUP_LEN];       // Название группы (факультет, курс, номер группы)
    int ses[SUBJECTS];           // Успеваемость (массив из 4-х элементов)
    float average;               // Средний балл (будет вычисляться)
    int original_index;          // Исходная позиция в списке
} STUD;

void inputStudent(STUD *s, int index);
void printStudent(const STUD *s);
float calculateAverage(const int *ses);
void sortStudentsByName(STUD *students, int count);
void printHighAchievers(STUD *students, int count);
int compareByName(const void *a, const void *b);
int compareByAverage(const void *a, const void *b);

#endif
