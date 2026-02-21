#include <stdio.h>
#include <math.h>

int main() {
    double N0, lambda, time, Nt;

    printf("Enter initial number of atoms: ");
    scanf("%lf", &N0);

    printf("Enter decay constant (lambda): ");
    scanf("%lf", &lambda);

    printf("Enter time (in seconds): ");
    scanf("%lf", &time);

    Nt = N0 * exp(-lambda * time);

    printf("Remaining atoms after %.2f seconds = %.2f\n", time, Nt);

    return 0;
}