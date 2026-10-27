/*
 * Name     : Priyanshu Yadav
 * Roll No. : 2501920110286
 * Subject  : Data Structures Lab (BCS351)
 *
 * Question 8:
 *   Write a C program to implement stack for expression conversion.
 *   Leetcode: Valid Parentheses
 *   https://leetcode.com/problems/valid-parentheses/
 */

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAX 200

char stk[MAX];
int top = -1;

void push(char c) { stk[++top] = c; }
char pop() { return stk[top--]; }
char peek() { return stk[top]; }
int isEmpty() { return top == -1; }

int precedence(char c) {
    switch (c) {
        case '^': return 3;
        case '*': case '/': case '%': return 2;
        case '+': case '-': return 1;
    }
    return 0;
}

/* Stack based infix -> postfix conversion */
void infixToPostfix(char infix[], char postfix[]) {
    int k = 0;
    top = -1;
    for (int i = 0; infix[i]; i++) {
        char c = infix[i];
        if (isspace((unsigned char)c)) continue;
        if (isalnum((unsigned char)c)) postfix[k++] = c;
        else if (c == '(') push(c);
        else if (c == ')') {
            while (!isEmpty() && peek() != '(') postfix[k++] = pop();
            if (!isEmpty()) pop();            /* remove '(' */
        } else {
            while (!isEmpty() && peek() != '(' &&
                   (precedence(peek()) > precedence(c) ||
                    (precedence(peek()) == precedence(c) && c != '^')))
                postfix[k++] = pop();
            push(c);
        }
    }
    while (!isEmpty()) postfix[k++] = pop();
    postfix[k] = '\0';
}

/* LeetCode 20 : Valid Parentheses */
int isValid(char *s) {
    top = -1;
    for (int i = 0; s[i]; i++) {
        char c = s[i];
        if (c == '(' || c == '{' || c == '[') push(c);
        else {
            if (isEmpty()) return 0;
            char t = pop();
            if ((c == ')' && t != '(') || (c == '}' && t != '{') || (c == ']' && t != '[')) return 0;
        }
    }
    return isEmpty();
}

int main() {
    int ch;
    char s[MAX], out[MAX];
    while (1) {
        printf("\n1. Infix to Postfix conversion\n2. Valid Parentheses (LeetCode)\n3. Exit\nEnter choice: ");
        if (scanf("%d", &ch) != 1) break;
        if (ch == 1) {
            printf("Enter infix expression (no spaces): ");
            scanf("%s", s);
            infixToPostfix(s, out);
            printf("Postfix expression: %s\n", out);
        } else if (ch == 2) {
            printf("Enter string of brackets: ");
            scanf("%s", s);
            printf(isValid(s) ? "Valid\n" : "Not Valid\n");
        } else if (ch == 3) break;
        else printf("Invalid choice\n");
    }
    return 0;
}
