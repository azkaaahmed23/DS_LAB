#include <stdio.h>
#include <stdlib.h>

struct stack {
    int data;
    struct stack *next;
};

// Global top pointer initialized to NULL
struct stack *top = NULL;

// Function declarations
struct stack *push(struct stack *, int);
struct stack *pop(struct stack *);
struct stack *display(struct stack *);
int peek(struct stack *);

int main() {
    int val, option;

    do {
        printf("\nMAIN MENU");
        printf("\n1. PUSH");
        printf("\n2. POP");
        printf("\n3. PEEK");
        printf("\n4. DISPLAY");
        printf("\n5. EXIT");
        printf("\nEnter your option: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                printf("Enter the number to be pushed on stack: ");
                scanf("%d", &val);
                top = push(top, val);
                break;

            case 2:
                top = pop(top);
                break;

            case 3:
                val = peek(top);
                if (val != -1)
                    printf("\nThe value on top of the stack is %d", val);
                else
                    printf("\nSTACK IS EMPTY");
                break;

            case 4:
                top = display(top);
                break;
        }
    } while (option != 5);

    return 0;
}

// Push operation
struct stack *push(struct stack *top, int val) {
    struct stack *ptr = (struct stack *)malloc(sizeof(struct stack));
    if (ptr == NULL) {
        printf("\nMemory allocation failed\n");
        return top;
    }
    ptr->data = val;
    ptr->next = top;
    top = ptr;
    return top;
}

// Pop operation
struct stack *pop(struct stack *top) {
    struct stack *ptr;
    if (top == NULL) {
        printf("\nSTACK UNDERFLOW");
    } else {
        ptr = top;
        top = top->next;
        printf("\nThe value being deleted is %d", ptr->data);
        free(ptr);
    }
    return top;
}

// Peek operation
int peek(struct stack *top) {
    if (top == NULL)
        return -1;
    else
        return top->data;
}

// Display operation
struct stack *display(struct stack *top) {
    struct stack *ptr = top;
    if (top == NULL) {
        printf("\nSTACK IS EMPTY");
    } else {
        printf("\nStack contents:");
        while (ptr != NULL) {
            printf("\n%d", ptr->data);
            ptr = ptr->next;
        }
    }
    return top;
}

