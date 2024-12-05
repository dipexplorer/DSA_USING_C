#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void printList(struct Node *head)
{
    struct Node *ptr = head;
    while (ptr != NULL)
    {
        printf("element: %d\n ", ptr->data);
        ptr = ptr->next;
    }
}

struct Node* deleteFirst(struct Node *head)
{
    if (head == NULL)
    {
        printf("The linked list is empty.\n");
        return head;
    }
    struct Node *temp = head;
    head = head->next;
    free(temp);
    return head;
}

struct Node* deleteIndex(struct Node* head, int idx){
    struct Node* p=head;
    struct Node* q=head->next;
    for(int i=0;i<idx-1;i++){
        p=p->next;
        q=q->next;
    }
    p->next=q->next;
    free(q);
    return head;
}

struct Node* deleteLast(struct Node* head){
    struct Node* p = head;
    struct Node* q = head->next;
    while(q->next!=NULL){
        p=p->next;
        q=q->next;
    }
    p->next=NULL;
    free(q);
    return head;
}

struct Node* deleteValue(struct Node* head, int value){
    struct Node* p = head;
    struct Node* q = head->next;
    while(q->data != value && q->next != NULL){
        p=p->next;
        q=q->next;
    }
    if(q->data == value){
        p->next=q->next;
        free(q);
    }
    else{
        printf("Value not found in the linked list.\n");
    }
    return head;
}

int main()
{
    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;


    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    fourth = (struct Node *)malloc(sizeof(struct Node));

    head->data = 1;
    head->next = second;

    second->data = 2;
    second->next = third;

    third->data = 3;
    third->next = fourth;

    fourth->data = 4;
    fourth->next = NULL;

    printf("Original linked list:\n");
    printList(head);

    // head = deleteFirst(head);

    // printf("linked list after deletion:\n");
    // printList(head);

    // head = deleteIndex(head, 2);
    // printf("Linked list after deletion at index 2:\n");
    // printList(head);


    // head = deleteLast(head);
    // printf("Linked list after deletion at last:\n");
    // printList(head);

    head = deleteValue(head, 2);
    printf("Linked list after deletion of value 2:\n");
    printList(head);
    return 0;
}