/*
 * Name     : Priyanshu Yadav
 * Roll No. : 2501920110286
 * Subject  : Data Structures Lab (BCS351)
 *
 * Question 2:
 *   Write a C program to perform various operations on 2D array:
 *   a) Multiplication of 2 matrix
 *   b) Finding difference of sum of two diagonal elements.
 */

#include <stdio.h>
#include <stdlib.h>
#define MAX 10

void readMatrix(int m[MAX][MAX], int r, int c) {
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            scanf("%d", &m[i][j]);
}

void multiply() {
    int A[MAX][MAX], B[MAX][MAX], C[MAX][MAX];
    int r1, c1, r2, c2;
    printf("Enter rows and columns of matrix A: ");
    scanf("%d %d", &r1, &c1);
    printf("Enter rows and columns of matrix B: ");
    scanf("%d %d", &r2, &c2);
    if (c1 != r2) { printf("Multiplication not possible (cols of A != rows of B)\n"); return; }
    printf("Enter elements of A:\n"); readMatrix(A, r1, c1);
    printf("Enter elements of B:\n"); readMatrix(B, r2, c2);
    for (int i = 0; i < r1; i++)
        for (int j = 0; j < c2; j++) {
            C[i][j] = 0;
            for (int k = 0; k < c1; k++) C[i][j] += A[i][k] * B[k][j];
        }
    printf("Product matrix:\n");
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) printf("%d\t", C[i][j]);
        printf("\n");
    }
}

void diagonalDifference() {
    int M[MAX][MAX], n, d1 = 0, d2 = 0;
    printf("Enter order of square matrix: ");
    scanf("%d", &n);
    printf("Enter elements:\n"); readMatrix(M, n, n);
    for (int i = 0; i < n; i++) {
        d1 += M[i][i];
        d2 += M[i][n - 1 - i];
    }
    printf("Sum of primary diagonal   = %d\n", d1);
    printf("Sum of secondary diagonal = %d\n", d2);
    printf("Absolute difference       = %d\n", abs(d1 - d2));
}

int main() {
    int ch;
    while (1) {
        printf("\n--- 2D ARRAY OPERATIONS ---\n1. Multiplication of 2 matrices\n2. Difference of sum of two diagonals\n3. Exit\nEnter choice: ");
        if (scanf("%d", &ch) != 1) break;
        if (ch == 1) multiply();
        else if (ch == 2) diagonalDifference();
        else if (ch == 3) break;
        else printf("Invalid choice\n");
    }
    return 0;
}
