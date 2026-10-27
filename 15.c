/*
 * Name     : Priyanshu Yadav
 * Roll No. : 2501920110286
 * Subject  : Data Structures Lab (BCS351)
 *
 * Question 15:
 *   Write a C program to implement Binary search tree (BST) and its traversal operations.
 *   In order traversal, Pre order traversal, Post order traversal
 *   leetcode: Diameter of Binary Tree
 *   https://leetcode.com/problems/diameter-of-binary-tree/
 */

#include <stdio.h>
#include <stdlib.h>

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

void inorder(struct Node *r)   { if (r) { inorder(r->left); printf("%d ", r->data); inorder(r->right); } }
void preorder(struct Node *r)  { if (r) { printf("%d ", r->data); preorder(r->left); preorder(r->right); } }
void postorder(struct Node *r) { if (r) { postorder(r->left); postorder(r->right); printf("%d ", r->data); } }

/* LeetCode 543 : Diameter of Binary Tree */
int diameter;
int height(struct Node *r) {
    if (!r) return 0;
    int l = height(r->left), rt = height(r->right);
    if (l + rt > diameter) diameter = l + rt;      /* longest path (in edges) through this node */
    return 1 + (l > rt ? l : rt);
}
int diameterOfBinaryTree(struct Node *root) {
    diameter = 0;
    height(root);
    return diameter;
}

int main() {
    struct Node *root = NULL;
    int ch, v;
    while (1) {
        printf("\n--- BINARY SEARCH TREE ---\n1. Insert\n2. Inorder Traversal\n3. Preorder Traversal\n");
        printf("4. Postorder Traversal\n5. Diameter of Binary Tree (LeetCode)\n6. Exit\nEnter choice: ");
        if (scanf("%d", &ch) != 1) break;
        switch (ch) {
            case 1: printf("Enter value: "); scanf("%d", &v); root = insert(root, v); break;
            case 2: printf("Inorder  : "); inorder(root); printf("\n"); break;
            case 3: printf("Preorder : "); preorder(root); printf("\n"); break;
            case 4: printf("Postorder: "); postorder(root); printf("\n"); break;
            case 5: printf("Diameter = %d\n", diameterOfBinaryTree(root)); break;
            case 6: return 0;
            default: printf("Invalid choice\n");
        }
    }
    return 0;
}
