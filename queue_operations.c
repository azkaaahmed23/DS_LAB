#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct queue {
    struct node *front, *rear;
};

void create_queue(struct queue *q) {
    q->front = q->rear = NULL;
}

void insert(struct queue *q, int val) {
    struct node *ptr = (struct node*)malloc(sizeof(struct node)); // Fix 1: Cast malloc
    ptr->data = val;
    ptr->next = NULL;

    if (q->rear == NULL)
        q->front = q->rear = ptr;
    else
        q->rear = q->rear->next = ptr;
    // Alternatively:
    // q->rear->next = ptr;
    // q->rear = ptr;
}

void delete_element(struct queue *q) {
    if (q->front == NULL) {
        printf("\nUNDERFLOW");
        return;
    }
    struct node *temp = q->front;
    printf("\nDeleted: %d", temp->data);
    q->front = q->front->next;
    if (q->front == NULL)
        q->rear = NULL;
    free(temp);
}

int peek(struct queue *q) {
    return (q->front) ? q->front->data : -1; // Fix 2: Corrected closing parenthesis
}

void display(struct queue *q) {
    if (q->front == NULL) {
        printf("\nQUEUE IS EMPTY");
        return;
    }
    struct node *temp = q->front;
    printf("\nQueue: ");
    while (temp) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

int main() {
    struct queue q;
    int val, option;

    create_queue(&q);

    do {
        printf("\n\n1.INSERT\n2.DELETE\n3.PEEK\n4.DISPLAY\n5.EXIT\n");
        scanf("%d", &option);

        switch (option) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &val);
                insert(&q, val);
                break;
            case 2:
                delete_element(&q);
                break;
            case 3:
                val = peek(&q);
                if (val != -1) // Fix 3: Should be -1 for empty queue
                    printf("\nFront: %d", val);
                else
                    printf("\nQUEUE IS EMPTY");
                break;
            case 4:
                display(&q);
                break;
        }
    } while (option != 5);
    return 0;
}


