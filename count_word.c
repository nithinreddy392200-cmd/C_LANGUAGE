#include <stdio.h>
#define MAX_SIZE 100 // Maximum string size

int main()
{
    char str[MAX_SIZE];
    char prevChar;
    int i, words;

    /* Input string from user */
    printf("Enter any string: ");
    // Note: gets() is unsafe; use fgets(str, MAX_SIZE, stdin); in practice
    fgets(str, MAX_SIZE, stdin);

    i = 0;
    words = 0;
    