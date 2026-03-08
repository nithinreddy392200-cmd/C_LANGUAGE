#include <stdio.h>
#include <math.h>

double simpleInterest(double principal, double rate, double time) {
    return (principal * rate * time) / 100.0;
}

double compoundInterest(double principal, double rate, double time, int n) {
    return principal * pow((1 + rate / (n * 100.0)), (n * time)) - principal;
}

double emi(double principal, double rate, int months) {
    double r = rate / (12 * 100.0);
    return (principal * r * pow(1 + r, months)) / (pow(1 + r, months) - 1);
}

int main() {
    int choice;
    double p, r, t;
    int n, months;
    char ch;

    do {
        printf("\n=== Finance Calculator ===\n");
        printf("1. Simple Interest\n");
        printf("2. Compound Interest\n");
        printf("3. EMI Calculator\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter Principal (Rs): ");
                scanf("%lf", &p);
                printf("Enter Rate (%/year): ");
                scanf("%lf", &r);
                printf("Enter Time (years): ");
                scanf("%lf", &t);
                printf("Simple Interest: Rs %.2f\n", simpleInterest(p, r, t));
                break;
            case 2:
                printf("Enter Principal (Rs): ");
                scanf("%lf", &p);
                printf("Enter Rate (%/year): ");
                scanf("%lf", &r);
                printf("Enter Time (years): ");
                scanf("%lf", &t);
                printf("Enter compounding freq (1=ann,12=mon,365=daily): ");
                scanf("%d", &n);
                printf("Compound Interest: Rs %.2f\n", compoundInterest(p, r, t, n));
                break;
            case 3:
                printf("Enter Principal (Rs): ");
                scanf("%lf", &p);
                printf("Enter Rate (%/year): ");
                scanf("%lf", &r);
                printf("Enter Time (months): ");
                scanf("%d", &months);
                printf("Monthly EMI: Rs %.2f\n", emi(p, r, months));
                break;
            case 4:
                printf("Thanks for using Finance Calculator!\n");
                return 0;
            default:
                printf("Invalid choice!\n");
        }
        printf("Continue? (y/n): ");
        scanf(" %c", &ch);
    } while (ch == 'y' || ch == 'Y');

    return 0;
}
