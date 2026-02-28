#include <stdio.h>
#define MAX_SIZE 10

// Function prototypes
void inputMatrix(int mat[][MAX_SIZE], int rows, int cols, char name[]);
void multiplyMatrices(int A[][MAX_SIZE], int B[][MAX_SIZE], int C[][MAX_SIZE], 
                     int rowA, int colA, int rowB, int colB);
void displayMatrix(int mat[][MAX_SIZE], int rows, int cols, char name[]);

int main() {
    int A[MAX_SIZE][MAX_SIZE], B[MAX_SIZE][MAX_SIZE], C[MAX_SIZE][MAX_SIZE];
    int rowA, colA, rowB, colB;
    
    // Get matrix dimensions with validation
    printf("Enter rows and cols for Matrix A: ");
    scanf("%d %d", &rowA, &colA);
    printf("Enter rows and cols for Matrix B: ");
    scanf("%d %d", &rowB, &colB);
    
    // Validate multiplication condition
    while (colA != rowB) {
        printf("Error: Columns of A (%d) must equal rows of B (%d)\n", colA, rowB);
        printf("Re-enter dimensions for A: ");
        scanf("%d %d", &rowA, &colA);
        printf("Re-enter dimensions for B: ");
        scanf("%d %d", &rowB, &colB);
    }
    
    // Input matrices
    inputMatrix(A, rowA, colA, "A");
    inputMatrix(B, rowB, colB, "B");
    
    // Multiply
    multiplyMatrices(A, B, C, rowA, colA, rowB, colB);
    
    // Display result (rowA x colB)
    displayMatrix(C, rowA, colB, "C");
    
    return 0;
}

void inputMatrix(int mat[][MAX_SIZE], int rows, int cols, char name[]) {
    int i, j;
    printf("\nEnter elements of %s:\n", name);
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("Element [%d][%d]: ", i+1, j+1);
            scanf("%d", &mat[i][j]);
        }
    }
}

void multiplyMatrices(int A[][MAX_SIZE], int B[][MAX_SIZE], int C[][MAX_SIZE], 
                     int rowA, int colA, int rowB, int colB) {
    int i, j, k;
    
    // Initialize result to 0
    for (i = 0; i < rowA; i++) {
        for (j = 0; j < colB; j++) {
            C[i][j] = 0;
        }
    }
    
    // Matrix multiplication: C[i][j] = Σ(A[i][k] * B[k][j])
    for (i = 0; i < rowA; i++) {
        for (j = 0; j < colB; j++) {
            for (k = 0; k < colA; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

void displayMatrix(int mat[][MAX_SIZE], int rows, int cols, char name[]) {
    int i, j;
    printf("\nMatrix %s:\n", name);
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("%4d ", mat[i][j]);
        }
        printf("\n");
    }
}
