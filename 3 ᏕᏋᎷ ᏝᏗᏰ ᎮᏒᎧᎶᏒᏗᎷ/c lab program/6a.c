#include <stdio.h>
#include <stdlib.h>
#define maxsize 5 // [cite: 238]
int queue[maxsize], front = 0, rear = -1, count = 0; // [cite: 239]

void insert(int item) { // [cite: 240]
    if (count == maxsize) { // [cite: 241]
        printf("Queue overflow"); // [cite: 243]
        return; // [cite: 244]
    }
    rear = (rear + 1) % maxsize; // [cite: 245]
    queue[rear] = item; // [cite: 246]
    count++; // [cite: 247]
}

void delete() { // [cite: 249]
    int item; // [cite: 272]
    if (count == 0) { // [cite: 273]
        printf("Queue underflow"); // [cite: 274]
    } else { // [cite: 275]
        item = queue[front]; // [cite: 276]
        printf(" The value deleted is: %d", item); // [cite: 277]
        front = (front + 1) % maxsize; // [cite: 278]
        count--; // [cite: 279]
    }
}

void display() { // [cite: 282]
    int i, temp_front = front; // temp_front not in original, but needed for non-destructive display.
    // NOTE: Your original lab code [cite: 289] modifies the global 'front' variable
    // in the display function, which is destructive. I have preserved this.
    // A non-destructive display would use a temporary variable.
    
    if (count == 0) { // [cite: 285]
        printf("Queue underflow"); // [cite: 287]
    } else { // [cite: 286]
        for (i = 1; i <= count; i++) { // [cite: 288]
            printf("%d\t", queue[front]); // [cite: 289]
            front = (front + 1) % maxsize; // [cite: 289]
        }
    }
}

int main() { // [cite: 293]
    int value, choice; // [cite: 295]
    while (1) { // [cite: 296]
        printf("\n-MENU-----\n"); // [cite: 314]
        printf(" 1. Insertion\n 2. Deletion\n 3. Display\n4. Exit"); // [cite: 315]
        printf("\nEnter your choice: "); // [cite: 316]
        scanf("%d", &choice); // [cite: 317]
        switch (choice) { // [cite: 318]
            case 1:
                printf("Enter the value to be inserted: "); // [cite: 320]
                scanf("%d", &value); // [cite: 321]
                insert(value); // [cite: 322]
                break; // [cite: 323]
            case 2:
                delete(); // [cite: 324]
                break; // [cite: 325]
            case 3:
                printf("Queue elements: "); // [cite: 326]
                display(); // [cite: 327]
                break; // [cite: 328]
            case 4:
                exit(0); // [cite: 329]
            default:
                printf("Enter valid choice"); // [cite: 330]
                // Note: The original code [cite: 331] places 'return 0' here.
                // This is kept, though 'case 4: exit(0);' is the intended exit.
                return 0; // [cite: 331]
        }
    }
}