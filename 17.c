/*
 * Name     : Priyanshu Yadav
 * Roll No. : 2501920110286
 * Subject  : Data Structures Lab (BCS351)
 *
 * Question 17:
 *   Write a C Program to create a Graph, and implement Traversal algorithms.
 *   Leetcode: Find if Path Exists in Graph
 *   https://leetcode.com/problems/find-if-path-exists-in-graph/
 */

#include <stdio.h>
#include <stdlib.h>
#define MAX 20

int adj[MAX][MAX], n;
int visited[MAX];

void createGraph() {
    int e, u, v;
    printf("Enter number of vertices (0 to %d-1 numbering): ", MAX);
    scanf("%d", &n);
    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) adj[i][j] = 0;
    printf("Enter number of edges: ");
    scanf("%d", &e);
    printf("Enter each edge as 'u v' (undirected):\n");
    for (int i = 0; i < e; i++) {
        scanf("%d %d", &u, &v);
        if (u >= 0 && u < n && v >= 0 && v < n) adj[u][v] = adj[v][u] = 1;
        else { printf("Invalid edge, re-enter\n"); i--; }
    }
}

void displayMatrix() {
    printf("Adjacency matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) printf("%d ", adj[i][j]);
        printf("\n");
    }
}

/* Breadth First Search */
void bfs(int start) {
    int queue[MAX], front = 0, rear = 0;
    for (int i = 0; i < n; i++) visited[i] = 0;
    visited[start] = 1; queue[rear++] = start;
    printf("BFS: ");
    while (front < rear) {
        int u = queue[front++];
        printf("%d ", u);
        for (int v = 0; v < n; v++)
            if (adj[u][v] && !visited[v]) { visited[v] = 1; queue[rear++] = v; }
    }
    printf("\n");
}

/* Depth First Search */
void dfsUtil(int u) {
    visited[u] = 1;
    printf("%d ", u);
    for (int v = 0; v < n; v++)
        if (adj[u][v] && !visited[v]) dfsUtil(v);
}
void dfs(int start) {
    for (int i = 0; i < n; i++) visited[i] = 0;
    printf("DFS: ");
    dfsUtil(start);
    printf("\n");
}

/* LeetCode 1971 : Find if Path Exists in Graph */
int validPath(int source, int destination) {
    int queue[MAX], front = 0, rear = 0;
    for (int i = 0; i < n; i++) visited[i] = 0;
    visited[source] = 1; queue[rear++] = source;
    while (front < rear) {
        int u = queue[front++];
        if (u == destination) return 1;
        for (int v = 0; v < n; v++)
            if (adj[u][v] && !visited[v]) { visited[v] = 1; queue[rear++] = v; }
    }
    return 0;
}

int main() {
    int ch, s, d;
    createGraph();
    while (1) {
        printf("\n--- GRAPH ---\n1. Display adjacency matrix\n2. BFS Traversal\n3. DFS Traversal\n");
        printf("4. Find if Path Exists (LeetCode)\n5. Exit\nEnter choice: ");
        if (scanf("%d", &ch) != 1) break;
        switch (ch) {
            case 1: displayMatrix(); break;
            case 2: printf("Enter start vertex: "); scanf("%d", &s); bfs(s); break;
            case 3: printf("Enter start vertex: "); scanf("%d", &s); dfs(s); break;
            case 4: printf("Enter source and destination: "); scanf("%d %d", &s, &d);
                    printf(validPath(s, d) ? "true - a path exists\n" : "false - no path\n");
                    break;
            case 5: return 0;
            default: printf("Invalid choice\n");
        }
    }
    return 0;
}
