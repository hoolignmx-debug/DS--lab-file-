/*
 * Name     : Priyanshu Yadav
 * Roll No. : 2501920110286
 * Subject  : Data Structures Lab (BCS351)
 *
 * Question 5:
 *   Write a C program to create a Circular linked list and perform various operations:
 *   a) Insertion at: i) Beg  ii) End  iii) Any position
 *   b) Deletion from: i) Beg  ii) End  iii) Any position
 */

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};
struct Node *head = NULL;

struct Node *newNode(int v) {
    struct Node *t = (struct Node *)malloc(sizeof(struct Node));
    t->data = v; t->next = NULL;
    return t;
}

int length() {
    if (!head) return 0;
    int c = 1;
    for (struct Node *t = head->next; t != head; t = t->next) c++;
    return c;
}

struct Node *lastNode() {
    struct Node *t = head;
    while (t->next != head) t = t->next;
    return t;
}

void insertBeg(int v) {
    struct Node *t = newNode(v);
    if (!head) { head = t; t->next = t; return; }
    t->next = head;
    lastNode()->next = t;
    head = t;
}

void insertEnd(int v) {
    struct Node *t = newNode(v);
    if (!head) { head = t; t->next = t; return; }
    struct Node *l = lastNode();
    l->next = t; t->next = head;
}

void insertPos(int v, int pos) {
    int len = length();
    if (pos < 1 || pos > len + 1) { printf("Invalid position\n"); return; }
    if (pos == 1) { insertBeg(v); return; }
    if (pos == len + 1) { insertEnd(v); return; }
    struct Node *p = head;
    for (int i = 1; i < pos - 1; i++) p = p->next;
    struct Node *t = newNode(v);
    t->next = p->next; p->next = t;
}

void deleteBeg() {
    if (!head) { printf("List is empty\n"); return; }
    struct Node *t = head;
    if (head->next == head) head = NULL;
    else { lastNode()->next = head->next; head = head->next; }
    printf("Deleted %d\n", t->data); free(t);
}

void deleteEnd() {
    if (!head) { printf("List is empty\n"); return; }
    if (head->next == head) { printf("Deleted %d\n", head->data); free(head); head = NULL; return; }
    struct Node *p = head;
    while (p->next->next != head) p = p->next;
    struct Node *t = p->next;
    p->next = head;
    printf("Deleted %d\n", t->data); free(t);
}

void deletePos(int pos) {
    int len = length();
    if (pos < 1 || pos > len) { printf("Invalid position\n"); return; }
    if (pos == 1) { deleteBeg(); return; }
    struct Node *p = head;
    for (int i = 1; i < pos - 1; i++) p = p->next;
    struct Node *t = p->next;
    p->next = t->next;
    printf("Deleted %d\n", t->data); free(t);
}

void display() {
    if (!head) { printf("List is empty\n"); return; }
    struct Node *t = head;
    do { printf("%d -> ", t->data); t = t->next; } while (t != head);
    printf("(back to head)\n");
}

int main() {
    int ch, v, p;
    while (1) {
        printf("\n--- CIRCULAR LINKED LIST ---\n");
        printf("1. Insert at Beginning\n2. Insert at End\n3. Insert at Any Position\n");
        printf("4. Delete from Beginning\n5. Delete from End\n6. Delete from Any Position\n");
        printf("7. Display\n8. Exit\nEnter choice: ");
        if (scanf("%d", &ch) != 1) break;
        switch (ch) {
            case 1: printf("Enter value: "); scanf("%d", &v); insertBeg(v); break;
            case 2: printf("Enter value: "); scanf("%d", &v); insertEnd(v); break;
            case 3: printf("Enter value and position: "); scanf("%d %d", &v, &p); insertPos(v, p); break;
            case 4: deleteBeg(); break;
            case 5: deleteEnd(); break;
            case 6: printf("Enter position: "); scanf("%d", &p); deletePos(p); break;
            case 7: display(); break;
            case 8: return 0;
            default: printf("Invalid choice\n");
        }
    }
    return 0;
}
