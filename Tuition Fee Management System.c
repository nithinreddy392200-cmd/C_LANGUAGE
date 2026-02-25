#include <stdio.h>

int main() {
    int credits, hostel, scholarship;
    char courseType;
    float feePerCredit, tuitionFee, labFee = 0, hostelFee = 0, scholarshipAmount = 0, totalFee;

    // Input section
    printf("Enter number of credits: ");
    scanf("%d", &credits);

    printf("Enter course type (U for UG, P for PG): ");
    scanf(" %c", &courseType);

    printf("Do you require hostel facility? (1 for Yes, 0 for No): ");
    scanf("%d", &hostel);

    printf("Do you have a scholarship? (1 for Yes, 0 for No): ");
    scanf("%d", &scholarship);

    // Fee per credit based on course type
    if(courseType == 'U' || courseType == 'u') {
        feePerCredit = 1500;   // UG fee per credit
        labFee = 2000;         // Fixed lab fee for UG
    } else if(courseType == 'P' || courseType == 'p') {
        feePerCredit = 2500;   // PG fee per credit
        labFee = 3000;         // Fixed lab fee for PG
    } else {
        printf("Invalid course type entered!\n");
        return 0;
    }

    // Tuition fee calculation
    tuitionFee = credits * feePerCredit;

    // Hostel fee
    if(hostel == 1) {
        hostelFee = 15000; // Fixed hostel fee per semester
    }

    // Scholarship deduction
    if(scholarship == 1) {
        scholarshipAmount = 0.20 * tuitionFee; // 20% scholarship
    }

    // Total fee calculation
    totalFee = tuitionFee + labFee + hostelFee - scholarshipAmount;

    // Output section
    printf("\n--- Tuition Fee Details ---\n");
    printf("Credits Registered   : %d\n", credits);
    printf("Fee per Credit       : %.2f\n", feePerCredit);
    printf("Tuition Fee          : %.2f\n", tuitionFee);
    printf("Lab Fee              : %.2f\n", labFee);
    printf("Hostel Fee           : %.2f\n", hostelFee);
    printf("Scholarship Deduction: %.2f\n", scholarshipAmount);
    printf("Total Payable Fee    : %.2f\n", totalFee);

    return 0;
}