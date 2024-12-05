#include <stdio.h>
#include <stdlib.h>

struct Stack
{
    int size;
    int top;
    int *arr;
};

int isEmpty(struct Stack *ptr)
{
    if (ptr->top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
};

int isFull(struct Stack *ptr)
{
    if (ptr->top == ptr->size - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
};

struct Stack* pushStack(int value, struct Stack *s){
    if(isFull(s)){
        printf("Stack Overflow\n");
    }else{
        s->top++;
        s->arr[s->top] = value;
    }
    return s;
}

struct Stack* popStack(int value, struct Stack *s){
    if(isEmpty(s)){
        printf("Stack Underflow\n");
    }else{
        int idx=0;
        for(int i=0;i<s->top;i++){
            if(s->arr[i]==value){
                idx=i;
                break;
            }
        }
        for(int i=idx;i<s->top;i++){
            s->arr[i] = s->arr[i+1];
        }
    }
    s->top--;
    return s;
}

void printStack(struct Stack *s){
    for(int i=s->top; i>=0; i--){
        printf("%d \n", s->arr[i]);
    }
}

int main()
{
    // struct Stack s;
    // s.size=10;
    // s.top=-1;
    // s.arr=(int *)malloc(s.size*sizeof(int));

    struct Stack *s = (struct Stack *)malloc(sizeof(struct Stack));
    s->size = 10;
    s->top = -1;
    s->arr = (int *)malloc(s->size * sizeof(int));
    
    pushStack(10, s);
    pushStack(20, s);
    pushStack(30, s);
    pushStack(50,s);
    printStack(s);
printf("after pop");
    popStack(20,s);
    printStack(s);

    return 0;
}