#include <stdio.h>
#define MAX 4

int queue[MAX];
int front = -1, rear = -1;

int isfull()
{
    if ((front == 0 && rear == MAX - 1) || (rear + 1 == front))
        return 1;
    return 0;
}

int isempty()
{
    if (front == -1)
        return 1;
    return 0;
}

void insert()
{
    int num;
    printf("\nEnter the no. to be inserted in the queue: ");
    scanf("%d", &num);

    if (isfull())
    {
        printf("OVERFLOW");
        return;
    }

    if (isempty())
    {
        front = rear = 0;
    }
    else if (rear == MAX - 1 && front != 0)
    {
        rear = 0;
    }
    else
    {
        rear++;
    }
    queue[rear] = num;
}

int delete_element()
{
    int val;

    if (isempty())
    {
        printf("UNDERFLOW");
        return -1;
    }

    val = queue[front]; // ?? FIXED: was `value=queue[front];`
    if (front == rear) // only one element
    {
        front = rear = -1;
    }
    else if (front == MAX - 1) // wrap around
    {
        front = 0;
    }
    else
    {
        front++;
    }
    return val;
}

int peek()
{
    if (isempty())
    {
        printf("\nQUEUE IS EMPTY");
        return -1;
    }
    else
    {
        return queue[front];
    }
}

void display()
{
    int i;

    if (isempty())
    {
        printf("\nQUEUE IS EMPTY");
        return;
    }

    printf("\nQueue elements are: ");
    if (front <= rear)
    {
        for (i = front; i <= rear; i++)
        {
            printf("\t%d", queue[i]);
        }
    }
    else
    {
        for (i = front; i < MAX; i++)
            printf("\t%d", queue[i]);
        for (i = 0; i <= rear; i++)
            printf("\t%d", queue[i]);
    }
}

int main()
{
    int option, val;

    do
    {
        printf("\n***MAIN MENU***");
        printf("\n1. INSERT AN ELEMENT");
        printf("\n2. DELETE AN ELEMENT");
        printf("\n3. PEEK");
        printf("\n4. DISPLAY THE QUEUE");
        printf("\n5. EXIT");
        printf("\nEnter your option: ");
        scanf("%d", &option);

        switch (option)
        {
        case 1:
            insert();
            break;
        case 2:
            val = delete_element();
            if (val != -1)
                printf("\nThe no. deleted is: %d", val);
            break;
        case 3:
            val = peek();
            if (val != -1)
                printf("\nThe 1st value in the queue is: %d", val);
            break;
        case 4:
            display();
            break;
        }
    } while (option != 5);

    return 0;
}

