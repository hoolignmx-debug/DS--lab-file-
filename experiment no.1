/*
 * Name     : Priyanshu Yadav
 * Roll No. : 2501920110286
 * Subject  : Data Structures Lab (BCS351)
 *
 * Question 1:
 *   Write a C program to create array and perform various operations:
 *   a) Insertion at: i) Beg  ii) End  iii) Any position
 *   b) Deletion from: i) Beg  ii) End  iii) Any position
 *   Leet Code Problem: Two Sum
 *   https://leetcode.com/problems/two-sum/
 */

#include <stdio.h>
#define MAX 100

int a[MAX], n = 0;

void display() {
    if (n == 0) { printf("Array is empty\n"); return; }
    printf("Array: ");
    for (int i = 0; i < n; i++) printf("%d ", a[i]);
    printf("\n");
}

/* pos is 1-based */
void insertAt(int pos, int val) {
    if (n >= MAX) { printf("Array is full\n"); return; }
    if (pos < 1 || pos > n + 1) { printf("Invalid position\n"); return; }
    for (int i = n; i >= pos; i--) a[i] = a[i - 1];
    a[pos - 1] = val;
    n++;
}

void deleteAt(int pos) {
    if (n == 0) { printf("Array is empty\n"); return; }
    if (pos < 1 || pos > n) { printf("Invalid position\n"); return; }
    printf("Deleted element: %d\n", a[pos - 1]);
    for (int i = pos - 1; i < n - 1; i++) a[i] = a[i + 1];
    n--;
}

/* LeetCode 1 : Two Sum */
int twoSum(int nums[], int size, int target, int res[]) {
    for (int i = 0; i < size; i++)
        for (int j = i + 1; j < size; j++)
            if (nums[i] + nums[j] == target) {
                res[0] = i; res[1] = j;
                return 1;
            }
    return 0;
}

int main() {
    int ch, v, p;
    while (1) {
        printf("\n--- ARRAY OPERATIONS ---\n");
        printf("1. Insert at Beginning\n2. Insert at End\n3. Insert at Any Position\n");
        printf("4. Delete from Beginning\n5. Delete from End\n6. Delete from Any Position\n");
        printf("7. Display\n8. Two Sum (LeetCode)\n9. Exit\nEnter choice: ");
        if (scanf("%d", &ch) != 1) break;
        switch (ch) {
            case 1: printf("Enter value: "); scanf("%d", &v); insertAt(1, v); break;
            case 2: printf("Enter value: "); scanf("%d", &v); insertAt(n + 1, v); break;
            case 3: printf("Enter value and position: "); scanf("%d %d", &v, &p); insertAt(p, v); break;
            case 4: deleteAt(1); break;
            case 5: deleteAt(n); break;
            case 6: printf("Enter position: "); scanf("%d", &p); deleteAt(p); break;
            case 7: display(); break;
            case 8: {
                int target, res[2];
                printf("Enter target: "); scanf("%d", &target);
                if (twoSum(a, n, target, res))
                    printf("Indices: [%d, %d]\n", res[0], res[1]);
                else
                    printf("No two numbers add up to %d\n", target);
                break;
            }
            case 9: return 0;
            default: printf("Invalid choice\n");
        }
    }
    return 0;
}
