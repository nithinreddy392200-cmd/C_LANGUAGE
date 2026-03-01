#include <stdio.h>
#include <stdbool.h>

// Simulated hardware states
bool isWaterLevelHigh = true;
bool isButtonPressed = true;

void heatWater() {
    printf("Heating water to 90°C...\n");
}

void activatePump() {
    printf("Dispensing coffee. Enjoy your drink!\n");
}

int main() {
    printf("--- Smart Coffee System 1.0 ---\n");

    // Real-time logic: Check conditions before acting
    if (isButtonPressed) {
        if (isWaterLevelHigh) {
            heatWater();
            activatePump();
        } else {
            printf("Error: Please refill water tank.\n");
        }
    } else {
        printf("System Standby.\n");
    }

    return 0;
}