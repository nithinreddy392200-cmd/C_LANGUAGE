#include <stdio.h>

// Function declaration (prototype)
int add(int a, int b);
void greet();

int main() {
    int x, y, sum;

    // Call greet function
    greet();

    // Input two numbers
    printf("Enter two numbers: ");
    scanf("%d %d", &x, &y);

    // Call add function
    sum = add(x, y);

    // Display result
    printf("Sum = %d\n", sum);

    return 0;
}

// Function definition
int add(int a, int b) {
    return a + b;  // returns sum of two numbers
}

// Another function definition
void greet() {
    printf("Welcome to the C Functions Program!\n");
}