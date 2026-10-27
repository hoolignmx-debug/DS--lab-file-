/*
 * Name     : Priyanshu Yadav
 * Roll No. : 2501920110286
 * Subject  : Data Structures Lab (BCS351)
 *
 * Question 7:
 *   Write a C program to Implement Stack using Array and Linked List.
 */

#include <stdio.h>
#include <stdlib.h>
#define MAX 100

/* ---------- Stack using Array ---------- */
int arr[MAX], top = -1;

void pushA(int v) {
    if (top == MAX - 1) { printf("Stack Overflow\n"); return; }
    arr[++top] = v;
}
void popA() {
    if (top == -1) { printf("Stack Underflow\n"); return; }
    printf("Popped: %d\n", arr[top--]);
}
void peekA() {
    if (top == -1) printf("Stack is empty\n");
    else printf("Top element: %d\n", arr[top]);
}
void displayA() {
    if (top == -1) { printf("Stack is empty\n"); return; }
    printf("Stack (top to bottom): ");
    for (int i = top; i >= 0; i--) printf("%d ", arr[i]);
    printf("\n");
}

/* ---------- Stack using Linked List ---------- */
struct Node {
    int data;
    struct Node *next;
};
struct Node *topL = NULL;

void pushL(int v) {
    struct Node *t = (struct Node *)malloc(sizeof(struct Node));
    t->data = v; t->next = topL; topL = t;
}
void popL() {
    if (!topL) { printf("Stack Underflow\n"); return; }
    struct Node *t = topL;
    printf("Popped: %d\n", t->data);
    topL = topL->next; free(t);
}
void peekL() {
    if (!topL) printf("Stack is empty\n");
    else printf("Top element: %d\n", topL->data);
}
void displayL() {
    if (!topL) { printf("Stack is empty\n"); return; }
    printf("Stack (top to bottom): ");
    for (struct Node *t = topL; t; t = t->next) printf("%d ", t->data);
    printf("\n");
}

int main() {
    int type, ch, v;
    while (1) {
        printf("\n--- STACK ---\n1. Using Array\n2. Using Linked List\n3. Exit\nEnter choice: ");
        if (scanf("%d", &type) != 1 || type == 3) break;
        if (type != 1 && type != 2) { printf("Invalid choice\n"); continue; }
        do {
            printf("\n[%s] 1.Push 2.Pop 3.Peek 4.Display 5.Back : ", type == 1 ? "ARRAY" : "LINKED LIST");
            if (scanf("%d", &ch) != 1) return 0;
            switch (ch) {
                case 1: printf("Enter value: "); scanf("%d", &v); type == 1 ? pushA(v) : pushL(v); break;
                case 2: type == 1 ? popA() : popL(); break;
                case 3: type == 1 ? peekA() : peekL(); break;
                case 4: type == 1 ? displayA() : displayL(); break;
                case 5: break;
                default: printf("Invalid choice\n");
            }
        } while (ch != 5);
    }
    return 0;
}
