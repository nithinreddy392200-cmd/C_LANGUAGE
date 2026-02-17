#include <stdio.h>

int main() {
    int n, i;
    int runs[50];
    int total = 0;
    int highest;
    int highest_index = 0;
    float average;

    printf("Enter number of players: ");
    scanf("%d", &n);

    // Input runs
    for(i = 0; i < n; i++) {
        printf("Enter runs scored by player %d: ", i + 1);
        scanf("%d", &runs[i]);
        total += runs[i];
    }

    // Calculate highest score
    highest = runs[0];
    for(i = 1; i < n; i++) {
        if(runs[i] > highest) {
            highest = runs[i];
            highest_index = i;
        }
    }

    // Calculate average
    average = (float)total / n;

    // Display results
    printf("\n--- Match Summary ---\n");
    printf("Total Runs: %d\n", total);
    printf("Average Runs: %.2f\n", average);
    printf("Highest Score: %d (Player %d)\n", highest, highest_index + 1);

    return 0;
}