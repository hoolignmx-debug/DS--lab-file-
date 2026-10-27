/*
 * Name     : Priyanshu Yadav
 * Roll No. : 2501920110286
 * Subject  : Data Structures Lab (BCS351)
 *
 * Question 18:
 *   Write a program to implement Minimum spanning tree algorithms.
 *   Leetcode: Number of Islands
 *   https://leetcode.com/problems/number-of-islands/
 */

#include <stdio.h>
#include <stdlib.h>
#define MAX 20
#define INF 99999

int g[MAX][MAX], n;

void readGraph() {
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter weighted adjacency matrix (0 = no edge):\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) scanf("%d", &g[i][j]);
}

/* ---------- Prim's Algorithm ---------- */
void prim() {
    int key[MAX], parent[MAX], inMST[MAX], total = 0;
    for (int i = 0; i < n; i++) { key[i] = INF; inMST[i] = 0; }
    key[0] = 0; parent[0] = -1;
    for (int c = 0; c < n; c++) {
        int u = -1;
        for (int i = 0; i < n; i++)
            if (!inMST[i] && (u == -1 || key[i] < key[u])) u = i;
        if (key[u] == INF) { printf("Graph is not connected\n"); return; }
        inMST[u] = 1;
        for (int v = 0; v < n; v++)
            if (g[u][v] && !inMST[v] && g[u][v] < key[v]) { key[v] = g[u][v]; parent[v] = u; }
    }
    printf("Prim's MST edges:\nEdge\tWeight\n");
    for (int i = 1; i < n; i++) { printf("%d - %d\t%d\n", parent[i], i, g[i][parent[i]]); total += g[i][parent[i]]; }
    printf("Total weight = %d\n", total);
}

/* ---------- Kruskal's Algorithm ---------- */
struct Edge { int u, v, w; } edges[MAX * MAX];
int parentSet[MAX];

int find(int x) { return parentSet[x] == x ? x : (parentSet[x] = find(parentSet[x])); }

int cmp(const void *a, const void *b) { return ((struct Edge *)a)->w - ((struct Edge *)b)->w; }

void kruskal() {
    int e = 0, total = 0, count = 0;
    for (int i = 0; i < n; i++) {
        parentSet[i] = i;
        for (int j = i + 1; j < n; j++)
            if (g[i][j]) { edges[e].u = i; edges[e].v = j; edges[e].w = g[i][j]; e++; }
    }
    qsort(edges, e, sizeof(struct Edge), cmp);
    printf("Kruskal's MST edges:\nEdge\tWeight\n");
    for (int i = 0; i < e && count < n - 1; i++) {
        int a = find(edges[i].u), b = find(edges[i].v);
        if (a != b) {
            parentSet[a] = b;
            printf("%d - %d\t%d\n", edges[i].u, edges[i].v, edges[i].w);
            total += edges[i].w; count++;
        }
    }
    if (count != n - 1) printf("Graph is not connected\n");
    else printf("Total weight = %d\n", total);
}

/* ---------- LeetCode 200 : Number of Islands ---------- */
char grid[MAX][MAX];
int R, C;

void sink(int i, int j) {
    if (i < 0 || j < 0 || i >= R || j >= C || grid[i][j] != '1') return;
    grid[i][j] = '0';
    sink(i + 1, j); sink(i - 1, j); sink(i, j + 1); sink(i, j - 1);
}

int numIslands() {
    int count = 0;
    for (int i = 0; i < R; i++)
        for (int j = 0; j < C; j++)
            if (grid[i][j] == '1') { count++; sink(i, j); }
    return count;
}

int main() {
    int ch;
    while (1) {
        printf("\n1. Prim's MST\n2. Kruskal's MST\n3. Number of Islands (LeetCode)\n4. Exit\nEnter choice: ");
        if (scanf("%d", &ch) != 1) break;
        switch (ch) {
            case 1: readGraph(); prim(); break;
            case 2: readGraph(); kruskal(); break;
            case 3:
                printf("Enter rows and columns: "); scanf("%d %d", &R, &C);
                printf("Enter grid (rows of 0/1 without spaces):\n");
                for (int i = 0; i < R; i++) scanf("%s", grid[i]);
                printf("Number of islands = %d\n", numIslands());
                break;
            case 4: return 0;
            default: printf("Invalid choice\n");
        }
    }
    return 0;
}
