#include <stdio.h>

int main() {
    int choice;
    float area, yield;

    printf("Enter land area in acres: ");
    scanf("%f", &area);

    printf("Choose crop type:\n");
    printf("1. Rice\n2. Wheat\n3. Maize\n");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            yield = area * 25; // 25 quintals per acre for Rice
            printf("Estimated Rice yield = %.2f quintals\n", yield);
            break;
        case 2:
            yield = area * 20; // 20 quintals per acre for Wheat
            printf("Estimated Wheat yield = %.2f quintals\n", yield);
            break;
        case 3:
            yield = area * 18; // 18 quintals per acre for Maize
            printf("Estimated Maize yield = %.2f quintals\n", yield);
            break;
        default:
            printf("Invalid crop choice