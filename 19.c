/*
 * Name     : Priyanshu Yadav
 * Roll No. : 2501920110286
 * Subject  : Data Structures Lab (BCS351)
 *
 * Question 19:
 *   Write a C program to implement Shortest path algorithm.
 *   Leetcode: Find Center of Star Graph
 *   https://leetcode.com/problems/find-center-of-star-graph/
 */

#include <stdio.h>
#define MAX 20
#define INF 99999

int g[MAX][MAX], n;

/* Dijkstra's shortest path algorithm */
void dijkstra(int src) {
    int dist[MAX], visited[MAX], parent[MAX];
    for (int i = 0; i < n; i++) { dist[i] = INF; visited[i] = 0; parent[i] = -1; }
    dist[src] = 0;
    for (int c = 0; c < n - 1; c++) {
        int u = -1;
        for (int i = 0; i < n; i++)
            if (!visited[i] && (u == -1 || dist[i] < dist[u])) u = i;
        if (dist[u] == INF) break;
        visited[u] = 1;
        for (int v = 0; v < n; v++)
            if (g[u][v] && !visited[v] && dist[u] + g[u][v] < dist[v]) {
                dist[v] = dist[u] + g[u][v];
                parent[v] = u;
            }
    }
    printf("\nShortest distances from vertex %d:\nVertex\tDistance\tPath\n", src);
    for (int i = 0; i < n; i++) {
        printf("%d\t", i);
        if (dist[i] == INF) { printf("INF\t\t-\n"); continue; }
        printf("%d\t\t", dist[i]);
        int path[MAX], len = 0;
        for (int x = i; x != -1; x = parent[x]) path[len++] = x;
        for (int k = len - 1; k >= 0; k--) printf("%d%s", path[k], k ? " -> " : "");
        printf("\n");
    }
}

/* LeetCode 1791 : Find Center of Star Graph
   In a star graph the center appears in every edge, so it is the common
   vertex of any two edges. */
int findCenter(int edges[][2]) {
    if (edges[0][0] == edges[1][0] || edges[0][0] == edges[1][1]) return edges[0][0];
    return edges[0][1];
}

int main() {
    int ch, src;
    while (1) {
        printf("\n1. Shortest Path (Dijkstra)\n2. Find Center of Star Graph (LeetCode)\n3. Exit\nEnter choice: ");
        if (scanf("%d", &ch) != 1 || ch == 3) break;
        if (ch == 1) {
            printf("Enter number of vertices: "); scanf("%d", &n);
            printf("Enter weighted adjacency matrix (0 = no edge):\n");
            for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) scanf("%d", &g[i][j]);
            printf("Enter source vertex: "); scanf("%d", &src);
            dijkstra(src);
        } else if (ch == 2) {
            int nodes, edges[MAX][2];
            printf("Enter number of nodes (n >= 3): "); scanf("%d", &nodes);
            printf("Enter %d edges as 'u v':\n", nodes - 1);
            for (int i = 0; i < nodes - 1; i++) scanf("%d %d", &edges[i][0], &edges[i][1]);
            printf("Center of the star graph = %d\n", findCenter(edges));
        } else printf("Invalid choice\n");
    }
    return 0;
}
