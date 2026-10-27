/*
 * Name     : Priyanshu Yadav
 * Roll No. : 2501920110286
 * Subject  : Data Structures Lab (BCS351)
 *
 * Question 16:
 *   Write a C program to implement Binary search tree (BST) and its traversal operations: Insertion, Deletion, Searching
 *   Leetcode: Maximum Node in Binary Tree (GFG)
 *   https://www.geeksforgeeks.org/find-maximum-or-minimum-in-binary-tree/
 */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct Node {
    int data;
    struct Node *left, *right;
};

struct Node *newNode(int v) {
    struct Node *t = (struct Node *)malloc(sizeof(struct Node));
    t->data = v; t->left = t->right = NULL;
    return t;
}

struct Node *insert(struct Node *root, int v) {
    if (!root) return newNode(v);
    if (v < root->data) root->left = insert(root->left, v);
    else if (v > root->data) root->right = insert(root->right, v);
    else printf("Duplicate %d ignored\n", v);
    return root;
}

struct Node *search(struct Node *root, int key) {
    if (!root || root->data == key) return root;
    return key < root->data ? search(root->left, key) : search(root->right, key);
}

struct Node *minNode(struct Node *r) {
    while (r->left) r = r->left;
    return r;
}

struct Node *deleteNode(struct Node *root, int key) {
    if (!root) { printf("Key %d not found\n", key); return NULL; }
    if (key < root->data) root->left = deleteNode(root->left, key);
    else if (key > root->data) root->right = deleteNode(root->right, key);
    else {
        if (!root->left) { struct Node *t = root->right; free(root); return t; }
        if (!root->right) { struct Node *t = root->left; free(root); return t; }
        struct Node *s = minNode(root->right);      /* inorder successor */
        root->data = s->data;
        root->right = deleteNode(root->right, s->data);
    }
    return root;
}

void inorder(struct Node *r) { if (r) { inorder(r->left); printf("%d ", r->data); inorder(r->right); } }

/* GFG : Find maximum node in a Binary Tree (works for any binary tree) */
int findMax(struct Node *root) {
    if (!root) return INT_MIN;
    int res = root->data;
    int l = findMax(root->left), r = findMax(root->right);
    if (l > res) res = l;
    if (r > res) res = r;
    return res;
}

int main() {
    struct Node *root = NULL, *f;
    int ch, v;
    while (1) {
        printf("\n--- BST OPERATIONS ---\n1. Insert\n2. Delete\n3. Search\n4. Inorder Display\n");
        printf("5. Maximum Node in Binary Tree (GFG)\n6. Exit\nEnter choice: ");
        if (scanf("%d", &ch) != 1) break;
        switch (ch) {
            case 1: printf("Enter value: "); scanf("%d", &v); root = insert(root, v); break;
            case 2: printf("Enter value to delete: "); scanf("%d", &v); root = deleteNode(root, v); break;
            case 3: printf("Enter value to search: "); scanf("%d", &v);
                    f = search(root, v);
                    printf(f ? "Found %d in the tree\n" : "%d not found\n", v);
                    break;
            case 4: printf("Inorder: "); inorder(root); printf("\n"); break;
            case 5: if (!root) printf("Tree is empty\n");
                    else printf("Maximum node = %d\n", findMax(root));
                    break;
            case 6: return 0;
            default: printf("Invalid choice\n");
        }
    }
    return 0;
}
