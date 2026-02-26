#include <stdio.h>

int main() {
    int choice;
    float balance = 0;

    printf("Welcome to Jio Recharge System\n");
    printf("Available Plans:\n");
    printf("1. ₹199 - 28 days - 1.5GB/day\n");
    printf("2. ₹399 - 56 days - 2GB/day\n");
    printf("3. ₹599 - 84 days - 3GB/day\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            balance = 199;
            printf("You selected ₹199 plan.\nValidity: 28 days\nData: 1.5GB/day\n");
            break;
        case 2:
            balance = 399;
            printf("You selected ₹399 plan.\nValidity: 56 days\nData: 2GB/day\n");
            break;
        case 3:
            balance = 599;
            printf("You selected ₹599 plan.\nValidity: 84 days\nData: 3GB/day\n");
            break;
        default:
            printf("Invalid choice!\n");
            return 0;
    }

    printf("Recharge successful! Amount deducted: ₹%.2f\n", balance);
    return 0;
}