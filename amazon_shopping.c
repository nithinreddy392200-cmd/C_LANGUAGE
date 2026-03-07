#include <stdio.h>
#include <string.h>

int main() {
    static int totalCost = 0;
    int i, choice, c = 1, a[9] = {0}, cost[9];
    char str[100];
    char items[9][100] = {"Sandisk 16GB", "Logitech Mouse", "Pendrive 16GB", "Adidas Shoes", "Nike Shoes", "LeeCooper Shoes", "Mi Note 3", "Nokia 3", "Samsung Galaxy"};
    
    printf("Please Enter Your Name\n");
    gets(str);
    printf("Hello %s, Welcome to Amazon Shopping!\n", str);
    
    do {
        if (c == 1) {
            printf("Enter\n1 - Electronics\n2 - Clothing\n3 - Books\nAny other number to Checkout\n");
            scanf("%d", &choice);
            cost[0] = 355; cost[1] = 500; cost[2] = 550;  // Electronics
            cost[3] = 3550; cost[4] = 5000; cost[5] = 2800;  // Clothing
            cost[6] = 11000; cost[7] = 9866; cost[8] = 12800;  // Books (example prices)
            
            switch (choice) {
                case 1:  // Electronics submenu
                    printf("1 - Sandisk 16GB Rs.355\n2 - Logitech Mouse Rs.500\n3 - Pendrive 16GB Rs.550\nAny other to back\n");
                    scanf("%d", &choice);
                    if (choice == 1 && choice <= 3) {
                        int num; printf("Confirm buy (1=Yes)?\n"); scanf("%d", &num);
                        if (num == 1) { a[choice-1]++; totalCost += cost[choice-1]; }
                    }
                    break;
                case 2:  // Clothing
                    printf("1 - Adidas Rs.3550\n2 - Nike Rs.5000\n3 - LeeCooper Rs.2800\nAny other to back\n");
                    scanf("%d", &choice);
                    if (choice == 1 && choice <= 3) {
                        int num; printf("Confirm buy (1=Yes)?\n"); scanf("%d", &num);
                        if (num == 1) { a[choice+2]++; totalCost += cost[choice+2]; }
                    }
                    break;
                case 3:  // Books
                    printf("1 - Mi Note 3 Rs.11000\n2 - Nokia 3 Rs.9866\n3 - Samsung Rs.12800\nAny other to back\n");
                    scanf("%d", &choice);
                    if (choice == 1 && choice <= 3) {
                        int num; printf("Confirm buy (1=Yes)?\n"); scanf("%d", &num);
                        if (num == 1) { a[choice+5]++; totalCost += cost[choice+5]; }
                    }
                    break;
                default: printf("Invalid category.\n");
            }
            // Display cart
            printf("%s's Cart:\n", str);
            printf("ID\tItem\t\tQty\tCost\n");
            for (i = 0; i < 9; i++) {
                if (a[i] > 0) {
                    printf("%d\t%s\t\t%d\t%d\n", i, items[i], a[i], (cost[i] * a[i]));
                }
            }
            printf("Total: Rs.%d\n", totalCost);
            printf("1-Add more 2-Remove 3-Update Qty 0-Checkout\n");
            scanf("%d", &c);
        }
        if (c == 2) {  // Remove
            int id;
            printf("Enter ID to remove:\n");
            scanf("%d", &id);
            if (id >= 0 && id < 9 && a[id] > 0) {
                totalCost -= (cost[id] * a[id]);
                a[id] = 0;
            } else printf("Invalid ID.\n");
            // Redisplay cart...
            printf("Total now: Rs.%d\n", totalCost);
            printf("1-Add 2-Remove 3-Update 0-Checkout\n");
            scanf("%d", &c);
        }
        if (c == 3) {  // Update qty
            int id, qty;
            printf("Enter ID:\n"); scanf("%d", &id);
            printf("New Qty:\n"); scanf("%d", &qty);
            if (id >= 0 && id < 9 && a[id] > 0 && qty > 0) {
                int diff = qty - a[id];
                totalCost += (cost[id] * diff);
                a[id] = qty;
            } else printf("Invalid.\n");
            // Redisplay...
            printf("Total now: Rs.%d\n", totalCost);
            printf("1-Add 2-Remove 3-Update 0-Checkout\n");
            scanf("%d", &c);
        }
    } while (c != 0);
    
    printf("Final Bill: Rs.%d\nThanks %s for shopping on Amazon!\n", totalCost, str);
    return 0;
}
