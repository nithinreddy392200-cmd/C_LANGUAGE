#include <stdio.h>

int main() {
    int n = 8;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if((i + j) % 2 == 0) {
                printf("██ ");
            } else {
                printf("  ");
            }
        }
        printf("\n");
    }
    return 0;
}