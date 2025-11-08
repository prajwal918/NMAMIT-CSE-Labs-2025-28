#include <stdio.h>
#include <stdlib.h>

struct node {
    int info;
    struct node *link;
};

typedef struct node *NODE;

NODE getnode() {
    NODE x;
    x = (NODE)malloc(sizeof(struct node));
    if (x == NULL) {
        printf("Memory not available");
        return x;
    }
    return x;
}

void freenode(NODE x) {
    free(x);
}

NODE insert_front(NODE first, int item) {
    NODE temp;
    temp = getnode();
    temp->info = item;
    temp->link = first;
    return (temp);
}

NODE insert_rear(int item, NODE first) {
    NODE temp, cur;
    temp = getnode();
    temp->info = item;
    temp->link = NULL;
    if (first == NULL)
        return temp;
    cur = first;
    while (cur->link != NULL) {
        cur = cur->link;
    }
    cur->link = temp;
    return first;
}

NODE delete_front(NODE first) {
    NODE temp;
    if (first == NULL) {
        printf("List is empty\n");
        return first;
    }
    temp = first;
    temp = temp->link;
    printf("Deleted data is %d\n", first->info);
    freenode(first);
    return temp;
}

NODE display_front(NODE first) {
    NODE temp;
    int count = 0;
    if (first == NULL) {
        printf("List is empty\n");
        return first;
    }
    temp = first;
    while (temp != NULL) {
        printf("%d\t", temp->info);
        temp = temp->link;
        count++;
    }
    printf("\n");
    printf("Number of Nodes : %d", count);
}

int main() {
    NODE first = NULL;
    int option, value, choice;
    while (1) {
        printf("\n   MENU-----\n");
        printf("1. Insert front\n 2. Display\n 3. Stack\n4. Queue\n 5. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter the value to be inserted: ");
                scanf("%d", &value);
                first = insert_front(first, value);
                break;
            case 2:
                printf("Queue elements: ");
                display_front(first);
                break;
            case 3:
                option = 0;
                while (option != 4) {
                    printf("\n MENU STACK \n");
                    printf("1. Insert front\n 2. Delete front\n 3. Display\n 4. Exit");
                    printf("\nEnter your choice:");
                    scanf("%d", &option);
                    switch (option) {
                        case 1:
                            printf("Enter the value to be inserted: ");
                            scanf("%d", &value);
                            first = insert_front(first, value);
                            break;
                        case 2:
                            first = delete_front(first);
                            break;
                        case 3:
                            printf("Queue elements: ");
                            display_front(first);
                            break;
                        case 4:
                            break;
                        default:
                            printf("Enter valid choice");
                    }
                }
                break;
            case 4:
                option = 0;
                while (option != 4) {
                    printf("\n MENU QUEUE \n");
                    printf(" 1. Insert rear\n 2. Delete front\n 3. Display\n 4. Exit");
                    printf("\nEnter your choice: ");
                    scanf("%d", &option);
                    switch (option) {
                        case 1:
                            printf("Enter the value to be inserted: ");
                            scanf("%d", &value);
                            first = insert_rear(value, first);
                            break;
                        case 2:
                            first = delete_front(first);
                            break;
                        case 3:
                            printf(" Queue elements: ");
                            display_front(first);
                            break;
                        case 4:
                            break;
                        default:
                            printf("Enter valid choice");
                    }
                }
                break;
            case 5:
                exit(0);
            default:
                printf("Enter valid choice");
        }
    }
    return 0;
}