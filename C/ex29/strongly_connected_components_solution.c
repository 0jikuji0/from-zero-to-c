/**
 * Exercise 29: Strongly Connected Components (Kosaraju Algorithm)
 * Difficulty: ***** (5/5)
 * 
 * Find all strongly connected components in a directed graph using Kosaraju algorithm.
 * A strongly connected component is a maximal set of vertices where every vertex
 * is reachable from every other vertex.
 * 
 * Input:
 * - First line: number of vertices (n) and edges (m)
 * - Next m lines: edges (u v) representing directed edges
 * 
 * Output:
 * - Print the number of strongly connected components
 * - Print vertices in each component
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct {
    int* vertices;
    int size;
} Adjacency;

typedef struct {
    int* data;
    int top;
} Stack;

Stack* createStack(int capacity) {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->data = (int*)malloc(sizeof(int) * capacity);
    stack->top = -1;
    return stack;
}

void push(Stack* stack, int value) {
    stack->data[++stack->top] = value;
}

int pop(Stack* stack) {
    return stack->data[stack->top--];
}

bool isEmptyStack(Stack* stack) {
    return stack->top == -1;
}

void dfs1(int u, Adjacency* adj, bool* visited, Stack* st) {
    visited[u] = true;
    
    for (int i = 0; i < adj[u].size; i++) {
        int v = adj[u].vertices[i];
        if (!visited[v]) {
            dfs1(v, adj, visited, st);
        }
    }
    
    push(st, u);
}

void dfs2(int u, Adjacency* adj_transpose, bool* visited, int* component, int* comp_size) {
    visited[u] = true;
    component[(*comp_size)++] = u;
    
    for (int i = 0; i < adj_transpose[u].size; i++) {
        int v = adj_transpose[u].vertices[i];
        if (!visited[v]) {
            dfs2(v, adj_transpose, visited, component, comp_size);
        }
    }
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    
    Adjacency* adj = (Adjacency*)malloc(sizeof(Adjacency) * n);
    Adjacency* adj_transpose = (Adjacency*)malloc(sizeof(Adjacency) * n);
    
    for (int i = 0; i < n; i++) {
        adj[i].vertices = (int*)malloc(sizeof(int) * n);
        adj[i].size = 0;
        adj_transpose[i].vertices = (int*)malloc(sizeof(int) * n);
        adj_transpose[i].size = 0;
    }
    
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u].vertices[adj[u].size++] = v;
        adj_transpose[v].vertices[adj_transpose[v].size++] = u;
    }
    
    bool* visited = (bool*)malloc(sizeof(bool) * n);
    memset(visited, false, sizeof(bool) * n);
    
    Stack* st = createStack(n);
    
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs1(i, adj, visited, st);
        }
    }
    
    memset(visited, false, sizeof(bool) * n);
    
    int* sccs[n];
    int scc_count = 0;
    
    while (!isEmptyStack(st)) {
        int u = pop(st);
        
        if (!visited[u]) {
            int* component = (int*)malloc(sizeof(int) * n);
            int comp_size = 0;
            dfs2(u, adj_transpose, visited, component, &comp_size);
            sccs[scc_count] = component;
            scc_count++;
        }
    }
    
    printf("Number of SCCs: %d\n", scc_count);
    
    for (int i = 0; i < scc_count; i++) {
        printf("SCC %d: ", i + 1);
        for (int j = 0; j < n; j++) {
            if (sccs[i][j] != -1) {
                printf("%d ", sccs[i][j]);
            }
        }
        printf("\n");
    }
    
    for (int i = 0; i < n; i++) {
        free(adj[i].vertices);
        free(adj_transpose[i].vertices);
    }
    free(adj);
    free(adj_transpose);
    free(visited);
    free(st->data);
    free(st);
    
    return 0;
}
