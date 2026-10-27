/*
 * Name     : Priyanshu Yadav
 * Roll No. : 2501920110286
 * Subject  : Data Structures Lab (BCS351)
 *
 * Question 14:
 *   Write a C program to Implement of Heapsort.
 *   Leetcode: Remove Duplicates from Sorted Array
 *   https://leetcode.com/problems/remove-duplicates-from-sorted-array/
 */

#include <stdio.h>
#define MAX 100

void swap(int *a, int *b) { int t = *a; *a = *b; *b = t; }

void heapify(int a[], int n, int i) {
    int largest = i, l = 2 * i + 1, r = 2 * i + 2;
    if (l < n && a[l] > a[largest]) largest = l;
    if (r < n && a[r] > a[largest]) largest = r;
    if (largest != i) {
        swap(&a[i], &a[largest]);
        heapify(a, n, largest);
    }
}

void heapSort(int a[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--) heapify(a, n, i);   /* build max heap */
    for (int i = n - 1; i > 0; i--) {
        swap(&a[0], &a[i]);
        heapify(a, i, 0);
    }
}

/* LeetCode 26 : Remove Duplicates from Sorted Array */
int removeDuplicates(int nums[], int n) {
    if (n == 0) return 0;
    int k = 1;
    for (int i = 1; i < n; i++)
        if (nums[i] != nums[i - 1]) nums[k++] = nums[i];
    return k;
}

int main() {
    int a[MAX], n, ch;
    while (1) {
        printf("\n1. Heap Sort\n2. Remove Duplicates from Sorted Array (LeetCode)\n3. Exit\nEnter choice: ");
        if (scanf("%d", &ch) != 1 || ch == 3) break;
        if (ch != 1 && ch != 2) { printf("Invalid choice\n"); continue; }
        printf("Enter number of elements: ");
        scanf("%d", &n);
        if (ch == 1) printf("Enter %d elements: ", n);
        else printf("Enter %d elements in sorted order: ", n);
        for (int i = 0; i < n; i++) scanf("%d", &a[i]);
        if (ch == 1) {
            heapSort(a, n);
            printf("Sorted array: ");
            for (int i = 0; i < n; i++) printf("%d ", a[i]);
            printf("\n");
        } else {
            int k = removeDuplicates(a, n);
            printf("k = %d, array: ", k);
            for (int i = 0; i < k; i++) printf("%d ", a[i]);
            printf("\n");
        }
    }
    return 0;
}
