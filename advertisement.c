#include <stdio.h>
#include <string.h>

#define MAX 100

// Structure for Advertisement
struct Advertisement {
    int id;
    char title[50];
    char company[50];
    float cost;
};

int main() {
    struct Advertisement ads[MAX];
    int count = 0;
    int choice, searchId, i;
    
    do {
        printf("\n===== Advertisement Management System =====\n");
        printf("1. Add Advertisement\n");
        printf("2. Display All Advertisements\n");
        printf("3. Search Advertisement by ID\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                if(count < MAX) {
                    printf("\nEnter Advertisement ID: ");
                    scanf("%d", &ads[count].id);
                    
                    printf("Enter Advertisement Title: ");
                    scanf(" %[^\n]", ads[count].title);
                    
                    printf("Enter Company Name: ");
                    scanf(" %[^\n]", ads[count].company);
                    
                    printf("Enter Advertisement Cost: ");
                    scanf("%f", &ads[count].cost);
                    
                    count++;
                    printf("Advertisement Added Successfully!\n");
                } else {
                    printf("Advertisement list is full!\n");
                }
                break;

            case 2:
                if(count == 0) {
                    printf("No Advertisements Available!\n");
                } else {
                    printf("\n--- Advertisement List ---\n");
                    for(i = 0; i < count; i++) {
                        printf("\nAd ID: %d\n", ads[i].id);
                        printf("Title: %s\n", ads[i].title);
                        printf("Company: %s\n", ads[i].company);
                        printf("Cost: %.2f\n", ads[i].cost);
                    }
                }
                break;

            case 3:
                if(count == 0) {
                    printf("No Advertisements to Search!\n");
                } else {
                    printf("Enter Advertisement ID to Search: ");
                    scanf("%d", &searchId);
                    
                    int found = 0;
                    for(i = 0; i < count; i++) {
                        if(ads[i].id == searchId) {
                            printf("\nAdvertisement Found!\n");
                            printf("Title: %s\n", ads[i].title);
                            printf("Company: %s\n", ads[i].company);
                            printf("Cost: %.2f\n", ads[i].cost);
                            found = 1;
                            break;
                        }
                    }
                    
                    if(!found) {
                        printf("Advertisement Not Found!\n");
                    }
                }
                break;

            case 4:
                printf("Exiting Program...\n");
                break;

            default:
                printf("Invalid Choice! Please Try Again.\n");
        }

    } while(choice != 4);

    return 0;
}