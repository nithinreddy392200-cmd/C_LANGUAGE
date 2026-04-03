#include <stdio.h>

int main() {
    float salary, tax = 0.0;

    printf("Enter your annual salary: ");
    scanf("%f", &salary);

    if (salary <= 10000) {
        tax = 0.0;                    // 0% tax
    }
    else if (salary <= 30000) {
        tax = (salary - 10000) * 0.10; // 10% on amount above 10,000
    }
    else if (salary <= 60000) {
        tax = 2000.0 + (salary - 30000) * 0.20; // 20% on amount above 30,000
    }
    else {
        tax = 8000.0 + (salary - 60000) * 0.30; // 30% on amount above 60,000
    }

    printf("Income tax: %.2f\n", tax);
    printf("Net income after tax: %.2f\n", salary - tax);

    return 0;
}