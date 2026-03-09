#include <stdio.h>
#include <string.h>

#define MAX 50

// Structure for product
struct Product {
    int id;
    char name[30];
    float price;
};

// Structure for cart
struct Cart {
    int productId;
    int quantity;
};

int main() {
    struct Product products[MAX] = {
        {1, "Laptop", 55000},
        {2, "Smartphone", 25000},
        {3, "Headphones", 2000},
        {4, "Shoes", 1500},
        {5, "Watch", 3000}
    };

    struct Cart cart[MAX];
    int cartCount = 0;
    int choice, qty, i;
    float total = 0;

    printf("=== Welcome to Flipkart Simulation ===\n");

    while (1) {
        printf("\nMenu:\n");
        printf("1. View Products\n");
        printf("2. Add to Cart\n");
        printf("3. View Cart\n");
        printf("4. Checkout\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nAvailable Products:\n");
                for (i = 0; i < 5; i++) {
                    printf("%d. %s - Rs. %.2f\n", products[i].id, products[i].name, products[i].price);
                }
                break;

            case 2:
                printf("Enter Product ID to add: ");
                scanf("%d", &choice);
                printf("Enter Quantity: ");
                scanf("%d", &qty);

                cart[cartCount].productId = choice;
                cart[cartCount].quantity = qty;
                cartCount++;

                printf("Product added to cart!\n");
                break;

            case 3:
                printf("\nYour Cart:\n");
                total = 0;
                for (i = 0; i < cartCount; i++) {
                    int pid = cart[i].productId;
                    qty = cart[i].quantity;
                    printf("%s x %d = Rs. %.2f\n", products[pid-1].name, qty, products[pid-1].price * qty);
                    total += products[pid-1].price * qty;
                }
                printf("Total: Rs. %.2f\n", total);
                break;

            case 4:
                printf("\n=== Checkout ===\n");
                total = 0;
                for (i = 0; i < cartCount; i++) {
                    int pid = cart[i].productId;
                    qty = cart[i].quantity;
                    printf("%s x %d = Rs. %.2f\n", products[pid-1].name, qty, products[pid-1].price * qty);
                    total += products[pid-1].price * qty;
                }
                printf("Grand Total: Rs. %.2f\n", total);
                printf("Thank you for shopping with Flipkart!\n");
                cartCount = 0; // Empty cart after checkout
                break;

            case 5:
                printf("Exiting... Thank you!\n");
                return 0;

            default:
                printf("Invalid choice! Try again.\n");
        }
    }
}