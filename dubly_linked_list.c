#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* prev;
    struct Node* next;
};

struct Node* createNode(int data){
    struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data=data;
    newNode->prev=NULL;
    newNode->next=NULL;
    return newNode;
}

struct Node* createDoublyList(int nodes){
    struct Node* head=NULL;
    struct Node* last=NULL;
    for(int i=0;i<nodes;i++){
        int data;
        printf("Enter the node %d data: ", i+1);
        scanf("%d", &data);
        struct Node* newNode=createNode(data);
        if(head==NULL){
            head=newNode;
            last=newNode;
        }else{
            newNode->prev=last;
            last->next=newNode;
            last=newNode;
        }
    }
    return head;
}

void printDoublyList(struct Node* head){
    struct Node* current=head;
    while(current!=NULL){
        printf("%d <-> ", current->data);
        current=current->next;
    }
}

void reversePrint(struct Node* head){
    struct Node* last=head;
    while(last->next!=NULL){
        last=last->next;
    }
    do{
        printf("%d <-> ", last->data);
        last=last->prev;
    }while(last!=head);
    printf("%d <-> ", last->data);
}

int main(){
    int nodes;
    printf("Enter the number of nodes: ");
    scanf("%d", &nodes);
    struct Node* head=createDoublyList(nodes);
    printDoublyList(head);

    printf("\nReversed Doubly Linked List: ");
    reversePrint(head);

    return 0;
}