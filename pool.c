#include <stdio.h>

int main() {
    int age, hours;
    float rate, total;

    printf("Enter your age: ");
    scanf("%d", &age);

    printf("Enter number of hours: ");
    scanf("%d", &hours);

    // Determine rate based on age
    if (age < 12) {
        rate = 50.0;   // For children
    } 
    else if (age <= 60) {
        rate = 100.0;  // For adults
    } 
    else {
        rate = 70.0;   // For senior citizens
    }

    // Calculate total charge
    total = rate * hours;

    printf("\n--- Swimming Pool Charges ---\n");
    printf("Age: %d\n", age);
    printf("Hours: %d\n", hours);
    printf("Rate per hour: %.2f\n", rate);
    printf("Total Charges: %.2f\n", total);

    return 0;
}