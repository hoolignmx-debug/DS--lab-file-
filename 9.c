/*
 * Name     : Priyanshu Yadav
 * Roll No. : 2501920110286
 * Subject  : Data Structures Lab (BCS351)
 *
 * Question 9:
 *   Write a C program to implement tower of Hanoi problem using recursion.
 */

#include <stdio.h>

long long moves = 0;

void hanoi(int n, char from, char to, char aux) {
    if (n == 0) return;
    hanoi(n - 1, from, aux, to);
    printf("Move disk %d from %c to %c\n", n, from, to);
    moves++;
    hanoi(n - 1, aux, to, from);
}

int main() {
    int n;
    printf("Enter number of disks: ");
    scanf("%d", &n);
    printf("\nSteps to solve Tower of Hanoi:\n");
    hanoi(n, 'A', 'C', 'B');
    printf("\nTotal moves = %lld\n", moves);
    return 0;
}
