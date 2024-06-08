#include <stdio.h>

#define ROWS 3
#define COLS 3

// Function to calculate parity
int parity(int num) {
    int count = 0;
    while(num) {
        count += num & 1;
        num >>= 1;
    }
    return count % 2;
}

int main() {
    int matrix[ROWS][COLS];
    int rowParity[ROWS] = {0};
    int colParity[COLS] = {0};
    int i, j;

    printf("Enter the elements of the matrix:\n");
    for(i = 0; i < ROWS; i++) {
        for(j = 0; j < COLS; j++) {
            scanf("%d", &matrix[i][j]);
            rowParity[i] ^= parity(matrix[i][j]);
            colParity[j] ^= parity(matrix[i][j]);
        }
    }

    printf("Row Parity:\n");
    for(i = 0; i < ROWS; i++) {
        printf("%d ", rowParity[i]);
    }
    printf("\n");

    printf("Column Parity:\n");
    for(j = 0; j < COLS; j++) {
        printf("%d ", colParity[j]);
    }
    printf("\n");

    return 0;
}