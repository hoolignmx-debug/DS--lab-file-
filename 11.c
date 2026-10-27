/*
 * Name     : Priyanshu Yadav
 * Roll No. : 2501920110286
 * Subject  : Data Structures Lab (BCS351)
 *
 * Question 11:
 *   Write a C program to implement Sequential search and Binary search.
 */

#include <stdio.h>
#define MAX 100

int sequentialSearch(int a[], int n, int key) {
    for (int i = 0; i < n; i++)
        if (a[i] == key) return i;
    return -1;
}

/* array must be sorted in ascending order */
int binarySearch(int a[], int n, int key) {
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (a[mid] == key) return mid;
        else if (a[mid] < key) low = mid + 1;
        else high = mid - 1;
    }
    return -1;
}

void sortArray(int a[], int n) {
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (a[j] > a[j + 1]) { int t = a[j]; a[j] = a[j + 1]; a[j + 1] = t; }
}

int main() {
    int a[MAX], n, key, ch, pos;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);

    while (1) {
        printf("\n1. Sequential Search\n2. Binary Search\n3. Exit\nEnter choice: ");
        if (scanf("%d", &ch) != 1 || ch == 3) break;
        if (ch != 1 && ch != 2) { printf("Invalid choice\n"); continue; }
        printf("Enter element to search: ");
        scanf("%d", &key);
        if (ch == 1) pos = sequentialSearch(a, n, key);
        else {
            sortArray(a, n);                  /* binary search needs sorted data */
            printf("Sorted array: ");
            for (int i = 0; i < n; i++) printf("%d ", a[i]);
            printf("\n");
            pos = binarySearch(a, n, key);
        }
        if (pos == -1) printf("Element %d not found\n", key);
        else printf("Element %d found at position %d\n", key, pos + 1);
    }
    return 0;
}
