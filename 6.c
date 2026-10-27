/*
 * Name     : Priyanshu Yadav
 * Roll No. : 2501920110286
 * Subject  : Data Structures Lab (BCS351)
 *
 * Question 6:
 *   Write a C program to create two polynomials and add them.
 *   Leet Code Problem: Merge Two Sorted Lists
 *   https://leetcode.com/problems/merge-two-sorted-lists/
 */

#include <stdio.h>
#include <stdlib.h>

/* ---------- Part A : Polynomial addition using linked lists ---------- */
struct Term {
    int coef, exp;
    struct Term *next;
};

/* inserts a term keeping exponents in descending order; combines equal exponents */
struct Term *insertTerm(struct Term *head, int coef, int exp) {
    if (coef == 0) return head;
    struct Term *t = (struct Term *)malloc(sizeof(struct Term));
    t->coef = coef; t->exp = exp; t->next = NULL;
    if (!head || exp > head->exp) { t->next = head; return t; }
    struct Term *p = head;
    while (p->next && p->next->exp > exp) p = p->next;
    if (p->exp == exp) { p->coef += coef; free(t); return head; }
    if (p->next && p->next->exp == exp) { p->next->coef += coef; free(t); return head; }
    t->next = p->next; p->next = t;
    return head;
}

struct Term *readPoly(const char *name) {
    int n, c, e;
    struct Term *h = NULL;
    printf("Enter number of terms in %s: ", name);
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("  term %d (coefficient exponent): ", i + 1);
        scanf("%d %d", &c, &e);
        h = insertTerm(h, c, e);
    }
    return h;
}

struct Term *addPoly(struct Term *a, struct Term *b) {
    struct Term *r = NULL;
    for (; a; a = a->next) r = insertTerm(r, a->coef, a->exp);
    for (; b; b = b->next) r = insertTerm(r, b->coef, b->exp);
    return r;
}

void printPoly(struct Term *p) {
    if (!p) { printf("0\n"); return; }
    for (; p; p = p->next) {
        printf("%d", p->coef);
        if (p->exp != 0) printf("x^%d", p->exp);
        if (p->next) printf(" + ");
    }
    printf("\n");
}

/* ---------- Part B : LeetCode 21 - Merge Two Sorted Lists ---------- */
struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode *mergeTwoLists(struct ListNode *l1, struct ListNode *l2) {
    struct ListNode dummy, *tail = &dummy;
    dummy.next = NULL;
    while (l1 && l2) {
        if (l1->val <= l2->val) { tail->next = l1; l1 = l1->next; }
        else { tail->next = l2; l2 = l2->next; }
        tail = tail->next;
    }
    tail->next = l1 ? l1 : l2;
    return dummy.next;
}

struct ListNode *readList(const char *name) {
    int n, v;
    struct ListNode *h = NULL, *t = NULL;
    printf("Enter number of nodes in %s: ", name);
    scanf("%d", &n);
    if (n > 0) printf("Enter %d values in sorted (ascending) order: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &v);
        struct ListNode *x = (struct ListNode *)malloc(sizeof(struct ListNode));
        x->val = v; x->next = NULL;
        if (!h) h = t = x; else { t->next = x; t = x; }
    }
    return h;
}

int main() {
    int ch;
    while (1) {
        printf("\n1. Add two polynomials\n2. Merge two sorted lists (LeetCode)\n3. Exit\nEnter choice: ");
        if (scanf("%d", &ch) != 1) break;
        if (ch == 1) {
            struct Term *p1 = readPoly("polynomial 1");
            struct Term *p2 = readPoly("polynomial 2");
            printf("Polynomial 1 : "); printPoly(p1);
            printf("Polynomial 2 : "); printPoly(p2);
            printf("Sum          : "); printPoly(addPoly(p1, p2));
        } else if (ch == 2) {
            struct ListNode *a = readList("list 1");
            struct ListNode *b = readList("list 2");
            struct ListNode *m = mergeTwoLists(a, b);
            printf("Merged list: ");
            for (; m; m = m->next) printf("%d ", m->val);
            printf("\n");
        } else if (ch == 3) break;
        else printf("Invalid choice\n");
    }
    return 0;
}
