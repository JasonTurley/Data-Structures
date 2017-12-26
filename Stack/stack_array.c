// C implementation of a stack using an array
#include <stdio.h>
#include <stdlib.h>

struct Stack {
    int top;
    unsigned capacity;
    int *array;
};

// Function to initialize a stack
struct Stack* createStack(unsigned capacity)
{
    struct Stack *stack = (struct Stack*) malloc(sizeof(stack));
    stack->capacity = capacity;
    stack->array = (int*) malloc(stack->capacity * sizeof((stack->array)));
    stack->top = -1;
    return stack;
}

// Checks if stack is empty
int isEmpty(struct Stack *stack)
{
    return (stack->top == -1);
}

// Checks if stack is full
int isFull(struct Stack *stack)
{
    if (stack->top == stack->capacity - 1) {
        printf("WARNING: Stack Overflow on next push");
        return 1;
    }

    return (stack->top >= stack->capacity);
}

// Add new element to top of stack
void push(struct Stack *stack, int data)
{
    if (isFull(stack))
        return;

    stack->array[++stack->top] = data;
    printf("%d added to stack\n", data);
}

// Removes and returns top of stack
int pop(struct Stack *stack)
{
    int temp = stack->array[--stack->top];
    printf("%d removed from stack\n", temp);
    return temp;
}

// Returns top element of stack
int peek(struct Stack *stack)
{
    return stack->array[stack->top];
}

void printStack(struct Stack *stack)
{
    int i = stack->top;
    puts("top: ");
    while (i != -1)
    {
        printf("%d\n", stack->array[i]); 
        i--;  
    }
}

int main()
{
    struct Stack *s = createStack(10);
    //printf("%d\n", isEmpty(s));
    push(s, 1);
    push(s, 2);
    push(s, 3);
    push(s, 4);
    push(s, 5);
    push(s, 6);
    push(s, 7);
    push(s, 8);
    push(s, 9);
    push(s, 10);
    push(s, 11);
    //printStack(s);
    //printf("capacity: %d", s->capacity);
    

}