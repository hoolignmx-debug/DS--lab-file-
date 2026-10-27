/*
 * Name     : Priyanshu Yadav
 * Roll No. : 2501920110286
 * Subject  : Data Structures Lab (BCS351)
 *
 * Question 13:
 *   Write a non-recursive C program to implement:
 *   a) Bubble sort  b) Selection sort  c) Insertion sort  d) Quick sort
 *   e) Shell sort  f) Radix sort  g) Merge Sort
 */

#include <stdio.h>
#include <string.h>
#define MAX 100

void swap(int *a, int *b) { int t = *a; *a = *b; *b = t; }

void bubbleSort(int a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int swapped = 0;
        for (int j = 0; j < n - i - 1; j++)
            if (a[j] > a[j + 1]) { swap(&a[j], &a[j + 1]); swapped = 1; }
        if (!swapped) break;
    }
}

void selectionSort(int a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min = i;
        for (int j = i + 1; j < n; j++)
            if (a[j] < a[min]) min = j;
        if (min != i) swap(&a[i], &a[min]);
    }
}

void insertionSort(int a[], int n) {
    for (int i = 1; i < n; i++) {
        int key = a[i], j = i - 1;
        while (j >= 0 && a[j] > key) { a[j + 1] = a[j]; j--; }
        a[j + 1] = key;
    }
}

/* Non-recursive Quick Sort using an explicit stack */
int partition(int a[], int low, int high) {
    int pivot = a[high], i = low - 1;
    for (int j = low; j < high; j++)
        if (a[j] <= pivot) { i++; swap(&a[i], &a[j]); }
    swap(&a[i + 1], &a[high]);
    return i + 1;
}

void quickSort(int a[], int n) {
    int stack[2 * MAX], top = -1;
    stack[++top] = 0;
    stack[++top] = n - 1;
    while (top >= 0) {
        int high = stack[top--];
        int low = stack[top--];
        if (low < high) {
            int p = partition(a, low, high);
            stack[++top] = low;  stack[++top] = p - 1;
            stack[++top] = p + 1; stack[++top] = high;
        }
    }
}

void shellSort(int a[], int n) {
    for (int gap = n / 2; gap > 0; gap /= 2)
        for (int i = gap; i < n; i++) {
            int temp = a[i], j;
            for (j = i; j >= gap && a[j - gap] > temp; j -= gap) a[j] = a[j - gap];
            a[j] = temp;
        }
}

/* Radix sort (LSD) - for non-negative integers */
void radixSort(int a[], int n) {
    int max = a[0];
    for (int i = 1; i < n; i++) if (a[i] > max) max = a[i];
    for (int exp = 1; max / exp > 0; exp *= 10) {
        int out[MAX], count[10] = {0};
        for (int i = 0; i < n; i++) count[(a[i] / exp) % 10]++;
        for (int i = 1; i < 10; i++) count[i] += count[i - 1];
        for (int i = n - 1; i >= 0; i--) out[--count[(a[i] / exp) % 10]] = a[i];
        for (int i = 0; i < n; i++) a[i] = out[i];
    }
}

/* Non-recursive (bottom-up) Merge Sort */
void mergeSort(int a[], int n) {
    int temp[MAX];
    for (int size = 1; size < n; size *= 2)
        for (int left = 0; left < n - size; left += 2 * size) {
            int mid = left + size - 1;
            int right = (left + 2 * size - 1 < n - 1) ? left + 2 * size - 1 : n - 1;
            int i = left, j = mid + 1, k = left;
            while (i <= mid && j <= right) temp[k++] = (a[i] <= a[j]) ? a[i++] : a[j++];
            while (i <= mid) temp[k++] = a[i++];
            while (j <= right) temp[k++] = a[j++];
            for (k = left; k <= right; k++) a[k] = temp[k];
        }
}

void display(int a[], int n) {
    for (int i = 0; i < n; i++) printf("%d ", a[i]);
    printf("\n");
}

int main() {
    int orig[MAX], a[MAX], n, ch;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter %d (non-negative) elements: ", n);
    for (int i = 0; i < n; i++) scanf("%d", &orig[i]);

    while (1) {
        printf("\n--- SORTING (non-recursive) ---\n");
        printf("1. Bubble Sort\n2. Selection Sort\n3. Insertion Sort\n4. Quick Sort\n");
        printf("5. Shell Sort\n6. Radix Sort\n7. Merge Sort\n8. Exit\nEnter choice: ");
        if (scanf("%d", &ch) != 1 || ch == 8) break;
        memcpy(a, orig, sizeof(int) * n);
        printf("Before sorting: "); display(a, n);
        switch (ch) {
            case 1: bubbleSort(a, n); break;
            case 2: selectionSort(a, n); break;
            case 3: insertionSort(a, n); break;
            case 4: quickSort(a, n); break;
            case 5: shellSort(a, n); break;
            case 6: radixSort(a, n); break;
            case 7: mergeSort(a, n); break;
            default: printf("Invalid choice\n"); continue;
        }
        printf("After sorting : "); display(a, n);
    }
    return 0;
}
