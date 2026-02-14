#include <stdio.h>
#include <string.h>

struct House {
    int houseNumber;
    char street[30];
    char room[20];
};

int main() {
    struct House h1, h2;

    h1.houseNumber = 101;
    strcpy(h1.street, "Maple Street");
    strcpy(h1.room, "Living Room");

    h2.houseNumber = 202;
    strcpy(h2.street, "Oak Avenue");
    strcpy(h2.room, "Kitchen");

    printf("House Address Analogy:\n");
    printf("House %d on %s -> %s\n", h1.houseNumber, h1.street, h1.room);
    printf("House %d on %s -> %s\n", h2.houseNumber, h2.street, h2.room);

    struct House *ptr = &h1;
    printf("Pointer points to House %d on %s -> %s\n",
           ptr->houseNumber, ptr->street, ptr->room);

    return 0;
}