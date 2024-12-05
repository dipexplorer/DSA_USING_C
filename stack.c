#include<stdio.h>
#include<stdlib.h>

struct Stack{
    int size;
    int top;
    int *arr;
};

int is_full(struct Stack *s){
    if(s->top == s->size){
        return 1;
    }
    return 0;
}

int is_empty(struct Stack *s){
    if(s->top==-1){
        return 1;
    }
    return 0;
}

void push(struct Stack *s, int value){
    if(is_full(s)){
        printf("Stack Overflow\n");
    }
    s->top++;
    s->arr[s->top]=value;
}

void print_stack(struct Stack *s){
    for(int i=s->top;i>=0;i--){
        printf("Element in stact is %d\n", s->arr[i]);
    }
}

int main(){
    struct Stack *s=(struct Stack *)malloc(sizeof(struct Stack));
    printf("Enter the stack size:\n");
    scanf("%d", s->size);
    s->arr=(int *)malloc(s->size*sizeof(int));
    s->top=-1;

    int choice=0;
    do{
        int value;
        printf("Enter element: ");
        scanf("%d", &value);
        push(s, value);
        printf("Do you want to continue (1/0): ");
        scanf("%d", &choice);
    }while (choice != 0);

    print_stack(s);

    return 0;
}