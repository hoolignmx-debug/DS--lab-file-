/*
 * Name     : Priyanshu Yadav
 * Roll No. : 2501920110286
 * Subject  : Data Structures Lab (BCS351)
 *
 * Question 12:
 *   Write a C program to implement Linear probe method for collision resolution.
 */

#include <stdio.h>
#define SIZE 10
#define EMPTY   -1
#define DELETED -2

int table[SIZE];

int hash(int key) { return key % SIZE; }

void insert(int key) {
    int idx = hash(key);
    for (int i = 0; i < SIZE; i++) {
        int p = (idx + i) % SIZE;                 /* linear probing */
        if (table[p] == EMPTY || table[p] == DELETED) {
            table[p] = key;
            printf("Inserted %d at index %d\n", key, p);
            return;
        }
    }
    printf("Hash table is full\n");
}

int search(int key) {
    int idx = hash(key);
    for (int i = 0; i < SIZE; i++) {
        int p = (idx + i) % SIZE;
        if (table[p] == EMPTY) return -1;
        if (table[p] == key) return p;
    }
    return -1;
}

void deleteKey(int key) {
    int p = search(key);
    if (p == -1) printf("Key %d not found\n", key);
    else { table[p] = DELETED; printf("Deleted %d from index %d\n", key, p); }
}

void display() {
    printf("\nIndex\tValue\n");
    for (int i = 0; i < SIZE; i++) {
        if (table[i] >= 0) printf("%d\t%d\n", i, table[i]);
        else printf("%d\t--\n", i);
    }
}

int main() {
    int ch, k, p;
    for (int i = 0; i < SIZE; i++) table[i] = EMPTY;
    while (1) {
        printf("\n--- HASHING (Linear Probing, size %d) ---\n1. Insert\n2. Search\n3. Delete\n4. Display\n5. Exit\nEnter choice: ", SIZE);
        if (scanf("%d", &ch) != 1) break;
        switch (ch) {
            case 1: printf("Enter key (non-negative): "); scanf("%d", &k); insert(k); break;
            case 2: printf("Enter key: "); scanf("%d", &k);
                    p = search(k);
                    if (p == -1) printf("Key %d not found\n", k);
                    else printf("Key %d found at index %d\n", k, p);
                    break;
            case 3: printf("Enter key: "); scanf("%d", &k); deleteKey(k); break;
            case 4: display(); break;
            case 5: return 0;
            default: printf("Invalid choice\n");
        }
    }
    return 0;
}
