#include <stdio.h>

#define MAX 100

int graph[MAX][MAX];
int indegree[MAX];
int n;

// Function for Topological Sort using Source Removal (similar to BFS logic)
void topologicalSort() {
    int count = 0;
    int visited[MAX] = {0};

    while (count < n) {
        int found = 0;

        // Find a vertex with indegree 0 and not visited
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0 && !visited[i]) {
                printf("%d ", i);
                visited[i] = 1;
                found = 1;
                count++;

                // Reduce indegree of adjacent vertices
                for (int j = 0; j < n; j++) {
                    if (graph[i][j] == 1) {
                        indegree[j]--;
                    }
                }
                // Break to restart search for the next indegree 0 vertex
                break; 
            }
        }

        // If no vertex found with indegree 0 -> cycle exists
        if (!found) {
            printf("
Cycle detected! Topological sorting not possible.
");
            return;
        }
    }
    printf("
");
}

int main() {
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    // Initialize indegree array
    for (int i = 0; i < n; i++) {
        indegree[i] = 0;
    }

    printf("Enter adjacency matrix:
");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
            if (graph[i][j] == 1) {
                // Calculate indegree
                indegree[j]++;
            }
        }
    }

    printf("Topological Order:
");
    topologicalSort();

    return 0;
}
