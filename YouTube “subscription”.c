#include <stdio.h>
#include <string.h>

int main() {
    char username[50];
    char channel[50];
    char response[10];

    printf("Enter your name: ");
    scanf("%s", username);

    printf("Enter the YouTube channel you want to subscribe to: ");
    scanf("%s", channel);

    printf("Do you want to subscribe to %s? (yes/no): ", channel);
    scanf("%s", response);

    if (strcmp(response, "yes") == 0 || strcmp(response, "YES") == 0) {
        printf("%s has successfully subscribed to the channel '%s'!\n", username, channel);
    } else {
        printf("%s chose not to subscribe.\n", username);
    }

    return 0;
}