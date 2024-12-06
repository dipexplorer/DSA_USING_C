#include <stdio.h>
#include <stdlib.h>

struct Stack
{
    int size;
    int top;
    int *arr;
};

int is_full(struct Stack *s)
{
    if (s->top == s->size - 1)
    {
        return 1;
    }
    return 0;
}

int is_empty(struct Stack *s)
{
    if (s->top == -1)
    {
        return 1;
    }
    return 0;
}

void push_stack(struct Stack *s, int value)
{
    if (is_full(s))
    {
        printf("Stack Overflow\n");
        return; // Stop further execution if full
    }
    s->top++;
    s->arr[s->top] = value;
    printf("Pushed %d to the stack.\n", value);
}

void pop(struct Stack *s)
{
    if (is_empty(s))
    {
        printf("Stack Underflow\n");
        return; // Stop further execution if empty
    }
    printf("Element %d is poped.\n", s->top);
    s->top--;
}

void peek(struct Stack *s) {
    if(is_empty(s)){
        printf("Stack is empty.\n");
        return; // Stop further execution if empty
    }
    printf("Top element is %d\n", s->arr[s->top]);
}

void print_stack(struct Stack *s)
{
    for (int i = s->top; i >= 0; i--)
    {
        printf("Element in stact is %d\n", s->arr[i]);
    }
}

int main()
{
    struct Stack *s = (struct Stack *)malloc(sizeof(struct Stack));
    printf("Enter the stack size:\n");
    scanf("%d", s->size);
    s->arr = (int *)malloc(s->size * sizeof(int));
    s->top = -1;

    char choice;
    do
    {
        int operation;
        int value;
        printf("Choose operation (push(1), pop(0),peek(2) print(5)): ");
        scanf("%d", &operation);
        switch (operation)
        {
        case 1:
            printf("Enter the element to push: ");
            scanf("%d", &value);
            push_stack(s, value);
            break;
        case 0:
            pop(s);
            break;
        case 2:
            peek(s);
            break;
        case 5:
            print_stack(s);
            break;
        default:
            printf("Invalid operation\n");
            break;
        }
        printf("Do you want to continue (y/n): ");
        scanf(" %c", &choice); // Added space to handle newline character
    } while (choice == 'y' || choice == 'Y');

    free(s->arr);
    free(s);
    return 0;
}