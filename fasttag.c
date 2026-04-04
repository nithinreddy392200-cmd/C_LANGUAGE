#include <stdio.h>
#include <string.h>

#define MAX_VEH 50
#define MIN_RECHARGE 100

struct FastTag {
    char vehicleNo[20];
    float balance;
};

int findVehicle(struct FastTag tags[], int n, char vehNo[]) {
    for (int i = 0; i < n; i++) {
        if (strcmp(tags[i].vehicleNo, vehNo) == 0)
            return i;
    }
    return -1;
}

void rechargeTag(struct FastTag *tag) {
    float amount;
    printf("Enter recharge amount: ");
    scanf("%f", &amount);

    if (amount < MIN_RECHARGE) {
        printf("Minimum recharge is Rs %.2f.\n", MIN_RECHARGE);
    } else {
        tag->balance += amount;
        printf("Recharge successful. New balance: Rs %.2f\n", tag->balance);
    }
}

void passToll(struct FastTag *tag, float toll) {
    if (tag->balance >= toll) {
        tag->balance -= toll;
        printf("Toll Rs %.2f deducted. Balance: Rs %.2f\n", toll, tag->balance);
    } else {
        printf("Insufficient balance. Please recharge.\n");
    }
}

int main() {
    struct FastTag tags[MAX_VEH];
    int n = 0;
    char vehNo[20];
    int choice;
    float toll;

    printf("=== FASTag Recharge & Toll Simulator ===\n");

    while (1) {
        printf("\n1. Add new vehicle\n");
        printf("2. View balance\n");
        printf("3. Recharge FASTag\n");
        printf("4. Pass toll (deduct)\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if 