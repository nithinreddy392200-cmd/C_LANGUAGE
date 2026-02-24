#include <stdio.h>
#include <string.h>

// Function declarations
void displayMenu();
void addStudent(char names[][50], int marks[], int *count);
void displayStudents(char names[][50], int marks[], int count);
float calculateAverage(int marks[], int count);
int findTopper(int marks[], int count);
void searchStudent(char names[][50], int marks[], int count, char query[]);

int main() {
    char names[100][50];   // Array of student names
    int marks[100];        // Array of student marks
    int count = 0;         // Number of students
    int choice;

    do {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                addStudent(names, marks, &count);
                break;
            case 2:
                displayStudents(names, marks, count);
                break;
            case 3:
                printf("Class Average = %.2f\n", calculateAverage(marks, count));
                break;
            case 4:
                if(count > 0) {
                    int topperIndex = findTopper(marks, count);
                    printf("Topper: %s with %d marks\n", names[topperIndex], marks[topperIndex]);
                } else {
                    printf("No students available!\n");
                }
                break;
            case 5: {
                char query[50];
                printf("Enter name to search: ");
                scanf("%s", query);
                searchStudent(names, marks, count, query);
                break;
            }
            case 0:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice! Try again.\n");
        }
    } while(choice != 0);

    return 0;
}

// Function definitions

void displayMenu() {
    printf("\n--- Student Management System ---\n");
    printf("1. Add Student\n");
    printf("2. Display All Students\n");
    printf("3. Calculate Average Marks\n");
    printf("4. Find Topper\n");
    printf("5. Search Student by Name\n");
    printf("0. Exit\n");
}

void addStudent(char names[][50], int marks[], int *count) {
    printf("Enter student name: ");
    scanf("%s", names[*count]);
    printf("Enter marks: ");
    scanf("%d", &marks[*count]);
    (*count)++;
    printf("Student added successfully!\n");
}

void displayStudents(char names[][50], int marks[], int count) {
    if(count == 0) {
        printf("No students to display!\n");
        return;
    }
    printf("\n--- Student List ---\n");
    for(int i = 0; i < count; i++) {
        printf("%d. %s - %d marks\n", i+1, names[i], marks[i]);
    }
}

float calculateAverage(int marks[], int count) {
    if(count == 0) return 0.0;
    int sum = 0;
    for(int i = 0; i < count; i++) {
        sum += marks[i];
    }
    return (float)sum / count;
}

int findTopper(int marks[], int count) {
    int maxIndex = 0;
    for(int i = 1; i < count; i++) {
        if(marks[i] > marks[maxIndex]) {
            maxIndex = i;
        }
    }
    return maxIndex;
}

void searchStudent(char names[][50], int marks[], int count, char query[]) {
    int found = 0;
    for(int i = 0; i < count; i++) {
        if(strcmp(names[i], query) == 0) {
            printf("Found: %s - %d marks\n", names[i], marks[i]);
            found = 1;
            break;
        }
    }
    if(!found) {
        printf("Student not found!\n");
    }
}