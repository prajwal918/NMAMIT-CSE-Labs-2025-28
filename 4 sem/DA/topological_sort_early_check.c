#include <stdio.h>

#define MAX 100

int graph[MAX][MAX];
int indegree[MAX];
int n;

// Check if graph is acyclic
int isAcyclic() {
    for (int i = 0; i < n; i++) {
        if (indegree[i] == 0) {
            return 1;   // at least one source exists
        }
    }
    return 0;           // no source → cycle
}

// Topological Sort using Source Removal
void topologicalSort() {
    int visited[MAX] = {0};
    int count = 0;

    while (count < n) {
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0 && !visited[i]) {
                printf("%d ", i);
                visited[i] = 1;
                count++;

                // Remove outgoing edges
                for (int j = 0; j < n; j++) {
                    if (graph[i][j] == 1) {
                        indegree[j]--;
                    }
                }
                break;
            }
        }
    }
    printf("\n");
}

int main() {
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
        indegree[i] = 0;

    printf("Enter adjacency matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
            if (graph[i][j] == 1)
                indegree[j]++;
        }
    }

    // 🔴 EARLY CHECK
    if (!isAcyclic()) {
        printf("Graph is CYCLIC. Topological sort not possible.\n");
        return 0;
    }

    printf("Graph is ACYCLIC\n");
    printf("Topological Order:\n");
    topologicalSort();

    return 0;
}
