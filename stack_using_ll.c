#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *createNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

int isEmpty(struct Node* head){
    if(head==NULL){
        return 1;
    }
    return 0;
}

struct Node *pushNode(struct Node *head, int data)
{
    struct Node *newNode = createNode(data);
    newNode->next = head;
    head = newNode;
    return head;
}

void pop_stack(struct Node **head) {
    if (isEmpty(*head)) {
        printf("Stack is empty. Nothing to pop.\n");
        return;
    }
    struct Node *ptr = *head;       // Pointer to the current head
    printf("Element popped from stack is %d\n", ptr->data);
    *head = (*head)->next;          // Update head to the next node
    free(ptr);                      // Free the old head
}

void peek(struct Node* head){
    if (isEmpty(head)) {
        printf("Stack is empty. No elements to peek.\n");
        return;
    }
    printf("Top element of stack is %d\n", head->data);
}

// Calculate the depth of the stack
void depth(struct Node* head) {
    if (isEmpty(head)) {
        printf("Stack is empty. Depth is 0.\n");
        return;
    }

    struct Node* ptr = head;
    while (ptr->next!= NULL) {
        ptr = ptr->next;
    }

    printf("Data at the first node is %d\n", ptr->data);
}

void print_stack(struct Node *head)
{
    struct Node *temp = head;
    while (temp != NULL)
    {
        printf("Element is stack is %d \n", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main()
{
    struct Node *head = NULL;
    int choice;
    int data;
    do
    {
        printf("\n1. Push\n2. Pop\n3. Display\n4. Top\n5. Depth\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter data to push: ");
            scanf("%d", &data);
            head = pushNode(head, data);
            break;
        case 2:
            pop_stack(&head); // Pass the address of 'head'
            break;
        case 3:
            print_stack(head);
            break;  
        case 4:
            peek(head);
            break;
        case 5:
            depth(head);
            break;
        default:
            break;
        }
        printf("Do you want to continue (Y/N): ");
        scanf(" %c", &choice);
    } while (choice == 'Y' || choice == 'y');
    return 0;
}