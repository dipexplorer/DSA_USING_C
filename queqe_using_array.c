#include <stdio.h>
#include <stdlib.h>

struct Queue
{
    int front, rear;
    int size;
    int *arr;
};

int isFull(struct Queue *q){
    if(q->rear == q->size-1){
        return 1;
    }
    return 0;
}

int isEmpty(struct Queue *q){
    if(q->front == -1 && q->rear == -1){
        return 1;
    }
    return 0;
}

void enqueue(struct Queue * q, int data){
    if(isFull(q)){
        printf("Queue is full. Cannot enqueue\n");
        return;
    }
    q->rear ++;
    q->arr[q->rear] = data;
}

struct Queue * deQueue(struct Queue * q){
    if(isEmpty(q)){
        printf("Queue is empty. Cannot dequeue\n");
        return NULL;
    }
    int data = q->arr[q->front];
    q->front++;
    return q;
}

void front(struct Queue * q){
    if(isEmpty(q)){
        printf("Queue is empty. Cannot get front\n");
        return;
    }
    printf("Front element is: %d\n", q->arr[q->front]);
}

void rear(struct Queue * q){
    if(isEmpty(q)){
        printf("Queue is empty. Cannot get rear\n");
        return;
    }
    printf("Rear element is: %d\n", q->arr[q->rear]);
}

void print_queue(struct Queue * q){
    if(isEmpty(q)){
        printf("Queue is empty. No elements to print\n");
        return;
    }
    for(int i=q->front+1; i<=q->rear; i++){
        printf("Queqe element %d\n", q->arr[i]);
    }
    printf("\n");
}

int main()
{
    struct Queue *q = (struct Queue *)malloc(sizeof(struct Queue));
    q->front = q->rear = -1;
    printf("Enter queue size:\n");
    scanf("%d", &q->size);
    q->arr = (int *)malloc(q->size * sizeof(int));
    int operation;
    char choice;
    do
    {
        int data;
        printf("\n1. Enqueue\n2. Dequeue\n3. Front\n4. Rear\n5. Print\nEnter Ur Choice:\n");
        scanf("%d", &operation);
        switch (operation)
        {
        case 1:
            printf("Enter value to enqueue: ");
            scanf("%d", &data);
            enqueue(q, data);
            break;
        case 2:
            deQueue(q);
            break;
        case 3:
            front(q);
            break;
        case 4:
            rear(q);
            break;
        case 5:
            print_queue(q);
            break;
        default:
            printf("Invalid Choice\n");
            break;
        }
        printf("Would you like to continue(y|n):\n");
        scanf(" %c", &choice);
    } while (choice == 'Y' || choice == 'y');

    return 0;
}