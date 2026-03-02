#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_LEN 100
#define PHONE_LEN 12

// Structure for user data
typedef struct {
    char firstName[MAX_LEN];
    char lastName[MAX_LEN];
    char dob[11];  // YYYY-MM-DD
    char gender[10];
    char username[MAX_LEN];
    char password[MAX_LEN];
    char phone[PHONE_LEN];
    char recoveryEmail[MAX_LEN];
} User;

// Function prototypes
int validateName(const char* name);
int validateDOB(const char* dob);
int validateUsername(const char* username);
int validatePassword(const char* pwd);
int validatePhone(const char* phone);
int isUsernameTaken(const char* username);
int generateOTP();
void saveUser(User* user);
void clearInputBuffer();

int main() {
    User user = {0};
    int step = 1;
    printf("=== Gmail Account Creation Simulator ===\n");

    while (step <= 8) {
        switch (step) {
            case 1:
                printf("\nStep 1: Enter First Name: ");
                fgets(user.firstName, MAX_LEN, stdin);
                user.firstName[strcspn(user.firstName, "\n")] = 0;
                if (!validateName(user.firstName)) {
                    printf("Invalid: Use letters only (3-20 chars).\n");
                    break;
                }
                printf("Step 1: Enter Last Name: ");
                fgets(user.lastName, MAX_LEN, stdin);
                user.lastName[strcspn(user.lastName, "\n")] = 0;
                if (!validateName(user.lastName)) {
                    printf("Invalid: Use letters only (3-20 chars).\n");
                    break;
                }
                step++;
                break;

            case 2:
                printf("Step 2: Date of Birth (YYYY-MM-DD): ");
                fgets(user.dob, 11, stdin);
                user.dob[strcspn(user.dob, "\n")] = 0;
                if (!validateDOB(user.dob)) {
                    printf("Invalid: Format YYYY-MM-DD (e.g., 2000-01-01).\n");
                    break;
                }
                printf("Gender (M/F/Other): ");
                fgets(user.gender, 10, stdin);
                user.gender[strcspn(user.gender, "\n")] = 0;
                step++;
                break;

            case 3:
                printf("Step 3: Choose Username (letters/numbers, 6-30 chars): ");
                fgets(user.username, MAX_LEN, stdin);
                user.username[strcspn(user.username, "\n")] = 0;
                if (!validateUsername(user.username) || isUsernameTaken(user.username)) {
                    printf("Invalid or taken.\n");
                    break;
                }
                step++;
                break;

            case 4:
                printf("Step 4: Create Password (8+ chars, 1 upper, 1 lower, 1 digit, 1 special): ");
                fgets(user.password, MAX_LEN, stdin);
                user.password[strcspn(user.password, "\n")] = 0;
                if (!validatePassword(user.password)) {
                    printf("Password too weak.\n");
                    break;
                }
                printf("Confirm Password: ");
                char confirm[MAX_LEN];
                fgets(confirm, MAX_LEN, stdin);
                confirm[strcspn(confirm, "\n")] = 0;
                if (strcmp(user.password, confirm) != 0) {
                    printf("Passwords don't match.\n");
                    break;
                }
                step++;
                break;

            case 5:
                printf("Step 5: Phone (+91XXXXXXXXXX): ");
                fgets(user.phone, PHONE_LEN, stdin);
                user.phone[strcspn(user.phone, "\n")] = 0;
                if (!validatePhone(user.phone)) {
                    printf("Invalid: +91 followed by 10 digits.\n");
                    break;
                }
                step++;
                break;

            case 6:
                printf("Step 6: Recovery Email (optional): ");
                fgets(user.recoveryEmail, MAX_LEN, stdin);
                user.recoveryEmail[strcspn(user.recoveryEmail, "\n")] = 0;
                step++;
                break;

            case 7: {
                int otp = generateOTP();
                printf("OTP sent to %s: %d\nEnter OTP: ", user.phone, otp);
                int inputOTP;
                scanf("%d", &inputOTP);
                clearInputBuffer();
                if (inputOTP != otp) {
                    printf("Invalid OTP. Retry?\n");
                    step = 5;
                    break;
                }
                step++;
                break;
            }

            case 8:
                printf("\nReview:\n");
                printf("Name: %s %s\nUsername: %s@gmail.com\nPhone: %s\n", user.firstName, user.lastName, user.username, user.phone);
                printf("Accept terms? (y/n): ");
                char accept;
                scanf(" %c", &accept);
                clearInputBuffer();
                if (accept == 'y' || accept == 'Y') {
                    saveUser(&user);
                    printf("Account created successfully! Welcome, %s@gmail.com\n", user.username);
                    return 0;
                } else {
                    printf("Restarting...\n");
                    step = 1;
                }
                break;
        }
    }
    return 0;
}

// Validation functions
int validateName(const char* name) {
    int len = strlen(name);
    if (len < 3 || len > 20) return 0;
    for (int i = 0; name[i]; i++) {
        if (!isalpha(name[i])) return 0;
    }
    return 1;
}

int validateDOB(const char* dob) {
    if (strlen(dob) != 10) return 0;
    if (dob[4] != '-' || dob[7] != '-') return 0;
    // Simple check; add full date logic if needed
    return 1;
}

int validateUsername(const char* un) {
    int len = strlen(un);
    if (len < 6 || len > 30) return 0;
    for (int i = 0; un[i]; i++) {
        if (!isalnum(un[i])) return 0;
    }
    return 1;
}

int validatePassword(const char* pwd) {
    int len = strlen(pwd), upper=0, lower=0, digit=0, special=0;
    if (len < 8) return 0;
    for (int i = 0; pwd[i]; i++) {
        if (isupper(pwd[i])) upper = 1;
        else if (islower(pwd[i])) lower = 1;
        else if (isdigit(pwd[i])) digit = 1;
        else if (strchr("!@#$%^&*", pwd[i])) special = 1;
    }
    return upper && lower && digit && special;
}

int validatePhone(const char* phone) {
    if (strlen(phone) != PHONE_LEN - 1) return 0;
    if (strncmp(phone, "+91", 3) != 0) return 0;
    for (int i = 3; phone[i]; i++) {
        if (!isdigit(phone[i])) return 0;
    }
    return 1;
}

int isUsernameTaken(const char* username) {
    FILE* fp = fopen("users.txt", "r");
    if (!fp) return 0;  // No file yet
    char line[MAX_LEN * 2];
    while (fgets(line, sizeof(line), fp)) {
        char fileUser[MAX_LEN];
        sscanf(line, "%s", fileUser);
        if (strcmp(fileUser, username) == 0) {
            fclose(fp);
            return 1;
        }
    }
    fclose(fp);
    return 0;
}

int generateOTP() {
    srand(time(NULL));
    return rand() % 900000 + 100000;
}

void saveUser(User* user) {
    FILE* fp = fopen("users.txt", "a");
    if (fp) {
        fprintf(fp, "%s|%s|%s|%s|%s|%s|%s|%s\n",
                user->firstName, user->lastName, user->dob, user->gender,
                user->username, user->password, user->phone, user->recoveryEmail);
        fclose(fp);
    }
}

void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}
