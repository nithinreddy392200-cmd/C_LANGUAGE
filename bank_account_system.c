#include <stdio.h>

int main() {
    int choice;
    double balance = 0.0, amount;

    while (1) {
        printf("\n--- Bank Menu ---\n");
        printf("1. Deposit\n");
        printf("2. Withdraw\n");
        printf("3. Check Balance\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter amount to deposit: ");
                scanf("%lf", &amount);
                balance += amount;
                printf("Deposited %.2lf successfully.\n", amount);
                break;

            case 2:
                printf("Enter amount to withdraw: ");
                scanf("%lf", &amount);
                if (amount <= balance) {
                    balance -= amount;
                    printf("Withdrawn %.2lf successfully.\n", amount);
                } else {
                    printf("Insufficient balance!\n");
                }
                break;

            case 3:
                printf("Current balance: %.2lf\n", balance);
                break;

            case 4:
                printf("Thank you for banking with us!\n");
                return 0;

            default:
                printf("Invalid choice. Try again.\n");
        }
    }
}