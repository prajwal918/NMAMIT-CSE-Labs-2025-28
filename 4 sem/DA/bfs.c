#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int graph[MAX][MAX], visited[MAX], n;
int queue[MAX], front = -1, rear = -1;

void enqueue(int v) {
    if (rear == MAX - 1)
        return;
    if (front == -1)
        front = 0;
    queue[++rear] = v;
}

int dequeue() {
    if (front == -1 || front > rear)
        return -1;
    return queue[front++];
}

void bfs(int start) {
    enqueue(start);
    visited[start] = 1;

    printf("BFS traversal starting from vertex %d: ", start);

    while (front != -1 && front <= rear) {
        int v = dequeue();
        printf("%d ", v);

        for (int i = 0; i < n; i++) {
            if (graph[v][i] == 1 && !visited[i]) {
                enqueue(i);
                visited[i] = 1;
            }
        }
    }
    printf("\n");
}

int main() {
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    int start_node;
    printf("Enter starting vertex: ");
    scanf("%d", &start_node);

    bfs(start_node);

    return 0;
}
