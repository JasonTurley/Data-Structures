// Implement stack data structure as an array
#include <stdio.h>
#include <stdlib.h>

// Strcuture to represent a stack
struct Stack 
{
    int top;
    int num_items;      // keep track of number of items in stack
    int *array;
    unsigned max_size;   // The maximun number of elements stack can hold. Unsigned to force to positive value

};

// Stack constructor.
struct Stack *constructor(unsigned max_size)
{
    struct Stack *stack = (struct Stack*) malloc(sizeof(struct Stack));
    stack->top = -1;   
    stack->num_items = 0;
    stack->array = (int*) malloc(stack->max_size * sizeof(int));
    stack->max_size = max_size;

    return stack;
}

int isFull(struct Stack *stack)
{
    return stack->max_size == - 1;
}

void push(struct Stack *stack, int x)
{
    if (isFull(stack))
        return;
    stack->array[++stack->top] = x;
    stack->num_items++;
    printf("%d pushed to stack\n", x);
}

void printStack(struct Stack *stack, int num_items)
{
    while (num_items)
        printf("%d\n", *stack->array);
}
    
int main(int argc, char **argv[])
{
    struct Stack* stack = constructor(10);
    push(stack, 10);
    push(stack, 20);
    push(stack, 30);

    //printStack(stack, stack->num_items);
}