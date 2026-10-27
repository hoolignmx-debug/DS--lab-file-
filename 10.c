/*
 * Name     : Priyanshu Yadav
 * Roll No. : 2501920110286
 * Subject  : Data Structures Lab (BCS351)
 *
 * Question 10:
 *   Write a C program to Implement Queue using Array and linked list.
 *   Leetcode: Implement Queue using Stacks
 *   https://leetcode.com/problems/implement-queue-using-stacks/
 */

#include <stdio.h>
#include <stdlib.h>
#define MAX 5

/* ---------- Queue using Array (circular) ---------- */
int q[MAX], front = -1, rear = -1;

void enqA(int v) {
    if ((rear + 1) % MAX == front) { printf("Queue Overflow\n"); return; }
    if (front == -1) front = 0;
    rear = (rear + 1) % MAX;
    q[rear] = v;
}
void deqA() {
    if (front == -1) { printf("Queue Underflow\n"); return; }
    printf("Dequeued: %d\n", q[front]);
    if (front == rear) front = rear = -1;
    else front = (front + 1) % MAX;
}
void displayA() {
    if (front == -1) { printf("Queue is empty\n"); return; }
    printf("Queue: ");
    for (int i = front; ; i = (i + 1) % MAX) {
        printf("%d ", q[i]);
        if (i == rear) break;
    }
    printf("\n");
}

/* ---------- Queue using Linked List ---------- */
struct Node {
    int data;
    struct Node *next;
};
struct Node *f = NULL, *r = NULL;

void enqL(int v) {
    struct Node *t = (struct Node *)malloc(sizeof(struct Node));
    t->data = v; t->next = NULL;
    if (!r) f = r = t;
    else { r->next = t; r = t; }
}
void deqL() {
    if (!f) { printf("Queue Underflow\n"); return; }
    struct Node *t = f;
    printf("Dequeued: %d\n", t->data);
    f = f->next;
    if (!f) r = NULL;
    free(t);
}
void displayL() {
    if (!f) { printf("Queue is empty\n"); return; }
    printf("Queue: ");
    for (struct Node *t = f; t; t = t->next) printf("%d ", t->data);
    printf("\n");
}

/* ---------- LeetCode 232 : Implement Queue using Stacks ---------- */
typedef struct {
    int in[100], out[100];
    int inTop, outTop;
} MyQueue;

void myQueueInit(MyQueue *q) { q->inTop = q->outTop = -1; }
void myQueuePush(MyQueue *q, int x) { q->in[++q->inTop] = x; }
static void transfer(MyQueue *q) {
    if (q->outTop == -1)
        while (q->inTop != -1) q->out[++q->outTop] = q->in[q->inTop--];
}
int myQueuePop(MyQueue *q) { transfer(q); return q->out[q->outTop--]; }
int myQueuePeek(MyQueue *q) { transfer(q); return q->out[q->outTop]; }
int myQueueEmpty(MyQueue *q) { return q->inTop == -1 && q->outTop == -1; }

int main() {
    int type, ch, v;
    MyQueue mq; myQueueInit(&mq);
    while (1) {
        printf("\n--- QUEUE ---\n1. Using Array (circular, size %d)\n2. Using Linked List\n3. Using Two Stacks (LeetCode)\n4. Exit\nEnter choice: ", MAX);
        if (scanf("%d", &type) != 1 || type == 4) break;
        if (type < 1 || type > 3) { printf("Invalid choice\n"); continue; }
        do {
            printf("\n[%s] 1.Enqueue 2.Dequeue 3.Display/Peek 4.Back : ",
                   type == 1 ? "ARRAY" : type == 2 ? "LINKED LIST" : "TWO STACKS");
            if (scanf("%d", &ch) != 1) return 0;
            switch (ch) {
                case 1:
                    printf("Enter value: "); scanf("%d", &v);
                    if (type == 1) enqA(v); else if (type == 2) enqL(v); else myQueuePush(&mq, v);
                    break;
                case 2:
                    if (type == 1) deqA();
                    else if (type == 2) deqL();
                    else if (myQueueEmpty(&mq)) printf("Queue Underflow\n");
                    else printf("Dequeued: %d\n", myQueuePop(&mq));
                    break;
                case 3:
                    if (type == 1) displayA();
                    else if (type == 2) displayL();
                    else if (myQueueEmpty(&mq)) printf("Queue is empty\n");
                    else printf("Front element: %d\n", myQueuePeek(&mq));
                    break;
                case 4: break;
                default: printf("Invalid choice\n");
            }
        } while (ch != 4);
    }
    return 0;
}
