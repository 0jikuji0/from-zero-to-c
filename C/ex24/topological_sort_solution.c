/**
 * Exercise 24: Topological Sort (DAG)
 * Difficulty: ***** (5/5)
 * 
 * Implement topological sorting for a directed acyclic graph (DAG).
 * Use Kahn's algorithm for in-degree based ordering.
 * 
 * Input:
 * - First line: number of vertices (n) and edges (m)
 * - Next m lines: edges (u v)
 * 
 * Output:
 * - Print topological order (space-separated)
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VERTICES 100
#define MAX_EDGES 1000

typedef struct {
    int* adj[MAX_VERTICES];
    int adjCount[MAX_VERTICES];
    int adjCapacity[MAX_VERTICES];
} AdjacencyList;

typedef struct {
    int* items;
    int front;
    int rear;
    int size;
} Queue;

Queue* createQueue(int size) {
    Queue* q = malloc(sizeof(Queue));
    q->items = malloc(sizeof(int) * size);
    q->front = 0;
    q->rear = -1;
    q->size = size;
    return q;
}

void enqueue(Queue* q, int value) {
    if (q->rear < q->size - 1) {
        q->items[++q->rear] = value;
    }
}

int dequeue(Queue* q) {
    if (q->front <= q->rear) {
        return q->items[q->front++];
    }
    return -1;
}

int isEmpty(Queue* q) {
    return q->front > q->rear;
}

void topologicalSort(int n, AdjacencyList* graph) {
    int inDegree[MAX_VERTICES] = {0};
    
    // Calculate in-degree for each vertex
    for (int u = 0; u < n; u++) {
        for (int i = 0; i < graph->adjCount[u]; i++) {
            inDegree[graph->adj[u][i]]++;
        }
    }
    
    Queue* q = createQueue(n);
    
    // Add all vertices with in-degree 0 to queue
    for (int i = 0; i < n; i++) {
        if (inDegree[i] == 0) {
            enqueue(q, i);
        }
    }
    
    int count = 0;
    while (!isEmpty(q)) {
        int u = dequeue(q);
        printf("%d", u);
        if (count < n - 1) printf(" ");
        count++;
        
        // For each adjacent vertex
        for (int i = 0; i < graph->adjCount[u]; i++) {
            int v = graph->adj[u][i];
            inDegree[v]--;
            
            if (inDegree[v] == 0) {
                enqueue(q, v);
            }
        }
    }
    printf("\n");
    
    free(q->items);
    free(q);
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    
    AdjacencyList graph;
    for (int i = 0; i < n; i++) {
        graph.adj[i] = malloc(sizeof(int) * MAX_EDGES);
        graph.adjCount[i] = 0;
        graph.adjCapacity[i] = MAX_EDGES;
    }
    
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        
        if (graph.adjCount[u] < graph.adjCapacity[u]) {
            graph.adj[u][graph.adjCount[u]++] = v;
        }
    }
    
    topologicalSort(n, &graph);
    
    // Free memory
    for (int i = 0; i < n; i++) {
        free(graph.adj[i]);
    }
    
    return 0;
}
