#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100   // Maximum number of records

struct Student {
    int id;
    char name[50];
    int age;
    float marks;
};

struct Student db[MAX];  // Database array
int count = 0;           // Current number of records

// Function to add a student
void addStudent() {
    if (count >= MAX) {
        printf("Database full! Cannot add more records.\n");
        return;
    }
    struct Student s;
    printf("Enter ID: ");
    scanf("%d", &s.id);
    printf("Enter Name: ");
    scanf("%s", s.name);
    printf("Enter Age: ");
    scanf("%d", &s.age);
    printf("Enter Marks: ");
    scanf("%f", &s.marks);

    db[count++] = s;
    printf("Record added successfully!\n");
}

// Function to display all students
void displayStudents() {
    if (count == 0) {
        printf("No records found.\n");
        return;
    }
    printf("\n--- Student Database ---\n");
    for (int i = 0; i < count; i++) {
        printf("ID: %d | Name: %s | Age: %d | Marks: %.2f\n",
               db[i].id, db[i].name, db[i].age, db[i].marks);
    }
}

// Function to search student by ID
void searchStudent() {
    int id;
    printf("Enter ID to search: ");
    scanf("%d", &id);
    for (int i = 0; i < count; i++) {
        if (db[i].id == id) {
            printf("Record Found: ID: %d | Name: %s | Age: %d | Marks: %.2f\n",
                   db[i].id, db[i].name, db[i].age, db[i].marks);
            return;
        }
    }
    printf("Record not found!\n");
}

// Function to update student by ID
void updateStudent() {
    int id;
    printf("Enter ID to update: ");
    scanf("%d", &id);
    for (int i = 0; i < count; i++) {
        if (db[i].id == id) {
            printf("Enter new Name: ");
            scanf("%s", db[i].name);
            printf("Enter new Age: ");
            scanf("%d", &db[i].age);
            printf("Enter new Marks: ");
            scanf("%f", &db[i].marks);
            printf("Record updated successfully!\n");
            return;
        }
    }
    printf("Record not found!\n");
}

// Function to delete student by ID
void deleteStudent() {
    int id;
    printf("Enter ID to delete: ");
    scanf("%d", &id);
    for (int i = 0; i < count; i++) {
        if (db[i].id == id) {
            for (int j = i; j < count - 1; j++) {
                db[j] = db[j + 1];
            }
            count--;
            printf("Record deleted successfully!\n");
            return;
        }
    }
    printf("Record not found!\n");
}

// Main menu
int main() {
    int choice;
    while (1) {
        printf("\n--- Mini DBMS Menu ---\n");
        printf("1. Add Student\n");
        printf("2. Display Students\n");
        printf("3. Search Student\n");
        printf("4. Update Student\n");
        printf("5. Delete Student\n");
        printf("6. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addStudent(); break;
            case 2: displayStudents(); break;
            case 3: searchStudent(); break;
            case 4: updateStudent(); break;
            case 5: deleteStudent(); break;
            case 6: exit(0);
            default: printf("Invalid choice!\n");
        }
    }
    return 0;
}