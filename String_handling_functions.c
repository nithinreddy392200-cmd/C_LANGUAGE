#include <stdio.h>
#include <string.h>

int main() {
    char str1[50], str2[50];
    
    printf("Enter first string: ");
    scanf("%s", str1);
    printf("Enter second string: ");
    scanf("%s", str2);
    
    printf("Length of str1: %lu\n", strlen(str1));  // Length
    strcpy(str2, str1);                            // Copy
    printf("str2 after copy: %s\n", str2);
    strcat(str2, " World");                        // Concat
    printf("str2 after concat: %s\n", str2);
    if (strcmp(str1, "Hello") == 0) {              // Compare
        printf("str1 equals 'Hello'\n");
    } else {
        printf("str1 differs\n");
    }
    
    return 0;
}