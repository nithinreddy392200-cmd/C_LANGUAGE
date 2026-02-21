#include <stdio.h>
#include <string.h>

int main() {
    char query[50];

    printf("Welcome to Mini Google!\n");
    printf("Search for: physics, chemistry, biology, computers\n");
    printf("Enter your query: ");
    scanf("%s", query);

    if (strcmp(query, "physics") == 0) {
        printf("Result: Physics is the study of matter, energy, and forces.\n");
    }
    else if (strcmp(query, "chemistry") == 0) {
        printf("Result: Chemistry deals with elements, compounds, and reactions.\n");
    }
    else if (strcmp(query, "biology") == 0) {
        printf("Result: Biology is the study of living organisms.\n");
    }
    else if (strcmp(query, "computers") == 0) {
        printf("Result: Computers process data using hardware and software.\n");
    }
    else {
        printf("No results found for '%s'. Try another search.\n", query);
    }

    return 0;
}