/**
 * Exercise 49: Lowest Common Ancestor (LCA) — Binary Lifting
 * Difficulty: ***** (5/5)
 *
 * Solution:
 * - Build adjacency list
 * - BFS from root=1 to compute depth[] and parent[0][]
 * - Build parent[k][] table
 * - Answer queries in O(log N)
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *head;
    int *to;
    int *next;
    int edgeCount;
} Graph;

static void graphInit(Graph *g, int n, int maxEdges)
{
    g->head = (int *)malloc((n + 1) * sizeof(int));
    g->to = (int *)malloc(maxEdges * sizeof(int));
    g->next = (int *)malloc(maxEdges * sizeof(int));
    g->edgeCount = 0;

    for (int i = 0; i <= n; i++)
        g->head[i] = -1;
}

static void graphAddEdge(Graph *g, int u, int v)
{
    int idx = g->edgeCount++;
    g->to[idx] = v;
    g->next[idx] = g->head[u];
    g->head[u] = idx;
}

static void graphFree(Graph *g)
{
    free(g->head);
    free(g->to);
    free(g->next);
}

static int computeLog(int n)
{
    int lg = 1;
    while ((1 << lg) <= n)
        lg++;
    return lg;
}

static int lca(int u, int v, int *parent, int logN, int n, int *depth)
{
    if (depth[u] < depth[v]) {
        int tmp = u;
        u = v;
        v = tmp;
    }

    int diff = depth[u] - depth[v];
    for (int k = 0; k < logN; k++) {
        if (diff & (1 << k)) {
            u = parent[k * (n + 1) + u];
        }
    }

    if (u == v)
        return u;

    for (int k = logN - 1; k >= 0; k--) {
        int pu = parent[k * (n + 1) + u];
        int pv = parent[k * (n + 1) + v];
        if (pu != pv) {
            u = pu;
            v = pv;
        }
    }

    return parent[0 * (n + 1) + u];
}

int main(void)
{
    int n, q;
    if (scanf("%d %d", &n, &q) != 2)
        return 0;

    Graph g;
    graphInit(&g, n, 2 * (n - 1));

    for (int i = 0; i < n - 1; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        graphAddEdge(&g, u, v);
        graphAddEdge(&g, v, u);
    }

    int logN = computeLog(n);

    int *depth = (int *)malloc((n + 1) * sizeof(int));
    int *visited = (int *)calloc((n + 1), sizeof(int));
    int *queue = (int *)malloc((n + 1) * sizeof(int));

    int *parent = (int *)malloc(logN * (n + 1) * sizeof(int));
    for (int k = 0; k < logN; k++) {
        for (int v = 0; v <= n; v++) {
            parent[k * (n + 1) + v] = 0;
        }
    }

    // BFS from root=1
    int root = 1;
    int front = 0, back = 0;
    queue[back++] = root;
    visited[root] = 1;
    depth[root] = 0;
    parent[0 * (n + 1) + root] = 0;

    while (front < back) {
        int u = queue[front++];
        for (int e = g.head[u]; e != -1; e = g.next[e]) {
            int v = g.to[e];
            if (!visited[v]) {
                visited[v] = 1;
                depth[v] = depth[u] + 1;
                parent[0 * (n + 1) + v] = u;
                queue[back++] = v;
            }
        }
    }

    // Build binary lifting table
    for (int k = 1; k < logN; k++) {
        for (int v = 1; v <= n; v++) {
            int mid = parent[(k - 1) * (n + 1) + v];
            parent[k * (n + 1) + v] = mid ? parent[(k - 1) * (n + 1) + mid] : 0;
        }
    }

    for (int i = 0; i < q; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        printf("%d\n", lca(u, v, parent, logN, n, depth));
    }

    free(depth);
    free(visited);
    free(queue);
    free(parent);
    graphFree(&g);

    return 0;
}
