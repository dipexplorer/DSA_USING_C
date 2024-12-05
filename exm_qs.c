#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *createNode(int data)
{
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    return node;
}

struct Node *createList(int nodes)
{
    struct Node *head = NULL;
    struct Node *last = NULL;
    for (int i = 0; i < nodes; i++)
    {
        int data;
        if (i == 0)
        {
            printf("Enter the first node data: ");
        }
        else
        {
            printf("Enter the next node data: ");
        }
        scanf("%d", &data);
        struct Node *newNode = createNode(data);
        if (head == NULL)
        {
            head = newNode;
            last = newNode;
        }
        else
        {
            last->next = newNode;
            last = newNode;
        }
    }
    return head;
}

void findPosition(struct Node *head, int value, int nodes)
{
    struct Node *ptr = head;
    int pos = 0;
    while (ptr != NULL)
    {
        if (value == ptr->data)
        {
            printf("%d found at position %d from start. \n", value, pos);
            printf("%d found at position %d from end. \n", value, nodes - pos);
        }
        ptr = ptr->next;
        pos++;
    }
}

void printList(struct Node *head)
{
    struct Node *current = head;
    while (current != NULL)
    {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int main()
{
    int nodes;
    printf("Enter the number of nodes: ");
    scanf("%d", &nodes);
    struct Node *head = createList(nodes);
    printf("Original List: ");
    printList(head);
    printf("finding positions: \n");
    findPosition(head, 2, nodes);
    return 0;
}