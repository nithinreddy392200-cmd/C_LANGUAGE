#include <stdio.h>

struct Item {
    char name[30];
    float price;
    int quantity;
};

int main() {
    struct Item items[3];   // Array of structures to store particulars
    int i;
    float total = 0;

    printf("Enter particulars of 3 items:\n");
    for (i = 0; i < 3; i++) {
        printf("\nItem %d name: ", i + 1);
        scanf("%s", items[i].name);

        printf("Price of %s: ", items[i].name);
        scanf("%f", &items[i].price);

        printf("Quantity of %s: ", items[i].name);
        scanf("%d", &items[i].quantity);

        total += items[i].price * items[i].quantity;
    }

    printf("\n--- Bill Summary ---\n");
    for (i = 0; i < 3; i++) {
        printf("%s - Price: %.2f, Quantity: %d, Subtotal: %.2f\n",
               items[i].name, items[i].price, items[i].quantity,
               items[i].price * items[i].quantity);
    }
    printf("Grand Total: %.2f\n", total);

    return 0;
}