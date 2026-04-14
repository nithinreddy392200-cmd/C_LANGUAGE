#include <stdio.h>
#include <stdlib.h>

int main() {
    const char *url = "https://www.google.com";
    char command[512];
    snprintf(command, sizeof(command), "google-chrome --new-tab '%s'", url);
    int result = system(command);
    if (result != 0) {
        printf("Failed to open Chrome. Install google-chrome if needed.\n");
    }
    return 0;
}