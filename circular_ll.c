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

struct Node *NodeList(int nodes)
{
    struct Node *head = NULL;
    struct Node *last = NULL;

    for (int i = 0; i < nodes; i++)
    {
        int data;
        if (i == 0)
        {
            printf("enter the first node(head):\n");
        }
        else
        {
            printf("enter the next node:\n");
        }
        scanf("%d", &data);
        struct Node *newNode = createNode(data);
        if (head == NULL){
            head = newNode;
            last = newNode;
        }else{
            last->next = newNode;
            last = newNode;
        }
    }
    // making the last node point to the head for circular list
    last->next = head;
    return head;
}

struct Node* insertAtFirst(struct Node* head, int data){
    struct Node* newNode = createNode(data);
    struct Node* p=head->next;
    while(p->next != head){
        p=p->next;
    }
    p->next=newNode;
    newNode->next=head;
    head=newNode;

    return head;
}

void printList(struct Node *head)
{
    struct Node *current = head;
    printf("Circular list of nodes: ");
    do
    {
        printf("%d ", current->data);
        current = current->next;
    } while (current != head); // Stop when we loop back to the head
    printf("\n");
}

int main()
{
    int nodes;
    printf("Enter the number of nodes: ");
    scanf("%d", &nodes);

    struct Node *head = NodeList(nodes);
    printList(head);

    head = insertAtFirst(head, 100);
    printList(head);
    return 0;
}