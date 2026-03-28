#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Simple XOR encryption/decryption
void encryptDecrypt(char *data, char key) {
    for (int i = 0; data[i] != '\0'; i++) {
        data[i] ^= key;
    }
}

void addPassword() {
    char website[50], username[50], password[50];
    printf("Enter website: ");
    scanf("%s", website);
    printf("Enter username: ");
    scanf("%s", username);
    printf("Enter password: ");
    scanf("%s", password);

    // Encrypt password before saving
    encryptDecrypt(password, 'K');

    FILE *fp = fopen("passwords.txt", "a");
    if (fp == NULL) {
        printf("Error opening file!\n");
        return;
    }
    fprintf(fp, "%s %s %s\n", website, username, password);
    fclose(fp);

    printf("Password saved successfully!\n");
}

void viewPasswords() {
    char website[50], username[50], password[50];
    FILE *fp = fopen("passwords.txt", "r");
    if (fp == NULL) {
        printf("No saved passwords found.\n");
        return;
    }

    printf("\nStored Passwords:\n");
    while (fscanf(fp, "%s %s %s", website, username, password) != EOF) {
        // Decrypt password before showing
        encryptDecrypt(password, 'K');
        printf("Website: %s | Username: %s | Password: %s\n", website, username, password);
    }
    fclose(fp);
}

int main() {
    int choice;
    while (1) {
        printf("\n--- Password Manager ---\n");
        printf("1. Add Password\n");
        printf("2. View Passwords\n");
        printf("3. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addPassword();
                break;
            case 2:
                viewPasswords();
                break;
            case 3:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice. Try again.\n");
        }
    }
    return 0;
}