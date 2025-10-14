#include <stdio.h>

#define MAX 100

struct Queue {
    int queue[MAX];
    int front;
    int rear;
    int count;
};

struct Queue q = { .front = 0, .rear = -1, .count = 0 };

void enqueue(int value) {
    if (q.count == MAX) {
        printf("Queue is full\n");
        return;
    }
    q.rear = (q.rear + 1) % MAX;
    q.queue[q.rear] = value;
    q.count++;
    printf("Enqueued: %d\n", value);
}

void dequeue() {
    if (q.count == 0) {
        printf("Queue is empty\n");
        return;
    }
    int val = q.queue[q.front];
    q.front = (q.front + 1) % MAX;
    q.count--;
    printf("Deleted item is: %d\n", val);
}

void display() {
    if (q.count == 0) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue elements: ");
    int i = q.front;
    for (int j = 0; j < q.count; j++) {
        printf("%d ", q.queue[i]);
        i = (i + 1) % MAX;
    }
    printf("\n");
}

int main() {
    int choice, value;
    
    while (1) {
        printf("\n--- Circular Queue Menu ---\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &value);
                enqueue(value);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }
}