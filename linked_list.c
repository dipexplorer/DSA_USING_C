#include <stdio.h>
#include <stdlib.h>

//define node structure
struct Node
{
    int data;
    struct Node *next;
};

//Function to print the linked list
void printNode(struct Node *ptr)
{
    while (ptr != NULL)
    {
        printf("element: %d \n", ptr->data);
        ptr = ptr->next;
    }
}

//Function to insert a node at the beginning of the linked list
struct Node *insertAtFirst(struct Node *head, int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    ptr->next = head;
    return ptr;
}

//Function to insert a node at the end of the linked list
struct Node *insertATIndex(struct Node *head, int data, int index)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    struct Node *p = head;
    int i = 0;
    while (i != index - 1)
    {
        p = p->next;
        i++;
    }
    newNode->data = data;
    newNode->next = p->next;
    p->next = newNode;

    return head;
}

//Function to insert a node at a given position in the linked list
struct Node* insertAtEnd(struct Node* head, int data){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    struct Node* ptr = head;

    while(ptr->next != NULL){
        ptr = ptr->next;
    }
    newNode->data = data;
    ptr->next = newNode;
    newNode->next = NULL;
    return head;
}

//Function to insert a node after a given node in the linked list
struct Node* insertAfterNode(struct Node* head, struct Node* pre, int data){
    if(pre->next == NULL){
        printf("The given previous node cannot be NULL\n");
        return head;
    }

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = pre->next;
    pre->next = newNode;
    return head;
}

//Main function to test the above functions
int main()
{
    // Create a linked list: 10 -> 20 -> 30
    struct Node *head;
    struct Node *second;
    struct Node *third;

    // Allocate memory for the nodes and link them together
    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));

    // Link nodes together
    head->data = 10;
    head->next = second;

    second->data = 20;
    second->next = third;

    third->data = 30;
    third->next = NULL;

    printf("Linked List:\n");
    printNode(head);

    head = insertAtFirst(head, 40);
    printf("\nLinked List after inserting at the beginning:\n");
    printNode(head);

    head = insertATIndex(head, 50, 2);
    printf("\nLinked List after inserting at index 2:\n");
    printNode(head);

    head = insertAtEnd(head, 60);
    printf("\nLinked List after inserting at the end:\n");
    printNode(head);

    head = insertAfterNode(head, second, 70);
    printf("\nLinked List after inserting after node 20:\n");
    printNode(head);

    return 0;
}