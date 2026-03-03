#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STUDENTS 100
#define FILE_NAME "students.dat"

struct Student {
    int rollNo;
    char name[50];
    float marks;
    char grade[5];
};

struct Student students[MAX_STUDENTS];
int totalStudents = 0;

void addStudent();
void viewStudents();
void searchStudent();
void updateStudent();
void deleteStudent();
void saveToFile();
void loadFromFile();

int main() {
    int choice;
    loadFromFile();  // Load data on startup

    while (1) {
        printf("\n=== Student Record Management System ===\n");
        printf("1. Add Student\n");
        printf("2. View All Students\n");
        printf("3. Search Student\n");
        printf("4. Update Student\n");
        printf("5. Delete Student\n");
        printf("6. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        fflush(stdin);

        switch (choice) {
            case 1: addStudent(); break;
            case 2: viewStudents(); break;
            case 3: searchStudent(); break;
            case 4: updateStudent(); break;
            case 5: deleteStudent(); break;
            case 6: saveToFile(); printf("Data saved. Goodbye!\n"); exit(0);
            default: printf("Invalid choice!\n");
        }
    }
    return 0;
}

void addStudent() {
    if (totalStudents >= MAX_STUDENTS) {
        printf("Max students reached!\n");
        return;
    }
    struct Student *s = &students[totalStudents];
    printf("Enter roll no: ");
    scanf("%d", &s->rollNo);
    fflush(stdin);
    printf("Enter name: ");
    fgets(s->name, 50, stdin);
    s->name[strcspn(s->name, "\n")] = 0;
    printf("Enter marks: ");
    scanf("%f", &s->marks);
    fflush(stdin);

    if (s->marks >= 90) strcpy(s->grade, "A");
    else if (s->marks >= 80) strcpy(s->grade, "B");
    else if (s->marks >= 70) strcpy(s->grade, "C");
    else strcpy(s->grade, "F");

    totalStudents++;
    printf("Student added!\n");
}

void viewStudents() {
    if (totalStudents == 0) {
        printf("No students!\n");
        return;
    }
    printf("\nRoll No\tName\tMarks\tGrade\n");
    for (int i = 0; i < totalStudents; i++) {
        printf("%d\t%s\t%.2f\t%s\n", students[i].rollNo, students[i].name, students[i].marks, students[i].grade);
    }
}

void searchStudent() {
    int roll;
    printf("Enter roll no: ");
    scanf("%d", &roll);
    for (int i = 0; i < totalStudents; i++) {
        if (students[i].rollNo == roll) {
            printf("Found: %s, Marks: %.2f, Grade: %s\n", students[i].name, students[i].marks, students[i].grade);
            return;
        }
    }
    printf("Student not found!\n");
}

void updateStudent() {
    int roll;
    printf("Enter roll no to update: ");
    scanf("%d", &roll);
    for (int i = 0; i < totalStudents; i++) {
        if (students[i].rollNo == roll) {
            printf("Enter new marks: ");
            scanf("%f", &students[i].marks);
            if (students[i].marks >= 90) strcpy(students[i].grade, "A");
            else if (students[i].marks >= 80) strcpy(students[i].grade, "B");
            else if (students[i].marks >= 70) strcpy(students[i].grade, "C");
            else strcpy(students[i].grade, "F");
            printf("Updated!\n");
            return;
        }
    }
    printf("Student not found!\n");
}

void deleteStudent() {
    int roll;
    printf("Enter roll no to delete: ");
    scanf("%d", &roll);
    for (int i = 0; i < totalStudents; i++) {
        if (students[i].rollNo == roll) {
            for (int j = i; j < totalStudents - 1; j++) {
                students[j] = students[j + 1];
            }
            totalStudents--;
            printf("Deleted!\n");
            return;
        }
    }
    printf("Student not found!\n");
}

void saveToFile() {
    FILE *fp = fopen(FILE_NAME, "wb");
    if (fp == NULL) return;
    fwrite(&totalStudents, sizeof(int), 1, fp);
    fwrite(students, sizeof(struct Student), totalStudents, fp);
    fclose(fp);
}

void loadFromFile() {
    FILE *fp = fopen(FILE_NAME, "rb");
    if (fp == NULL) return;
    fread(&totalStudents, sizeof(int), 1, fp);
    if (totalStudents > 0 && totalStudents <= MAX_STUDENTS) {
        fread(students, sizeof(struct Student), totalStudents, fp);
    }
    fclose(fp);
}
