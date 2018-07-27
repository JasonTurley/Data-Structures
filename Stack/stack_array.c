// C implementation of a stack using an array
#include <stdio.h>
#include <stdlib.h>

struct Stack {
    int top;
    unsigned int capacity;
    int *array;
};

// Returns a heap allocated stack structure with a max size
// of `capacity`
struct Stack* createStack(unsigned capacity)
{
    struct Stack *stack = malloc(sizeof(stack));
    if (stack == NULL) {
        perror("Failed to create new stack.\n");
        exit(-1);
    }

    stack->capacity = capacity;
    stack->array = malloc(stack->capacity * sizeof(int));
    if (stack->array == NULL) {
        perror("Failed to create internal stack array.\n");
        exit(-1);
    }

    stack->top = -1;
    return stack;
}

// Checks if stack is empty
int isEmpty(struct Stack *stack)
{
    if (stack) {
        return (stack->top == -1);
    }
}

// Checks if stack is full
int isFull(struct Stack *stack)
{
    if (stack) {
        return (stack->top == stack->capacity - 1);
    }
}

// Adds new element to the top of the stack
void push(struct Stack *stack, int data)
{
    if (stack) {
        // Ensure stack isn't at max capacity
        if (isFull(stack)) {
            printf("WARNING: Stack Overflow when attempting to push: %d\n", data);
            return;
        }

        stack->array[++stack->top] = data;
        printf("%d added to stack\n", data);
    }
}

// Removes and returns the top element on the stack
int pop(struct Stack *stack)
{
    int temp = stack->array[--stack->top];
    printf("%d removed from stack\n", temp);
    return temp;
}

// Returns the top element of the stack, without removing it
int peek(struct Stack *stack)
{
    return stack->array[stack->top];
}

void printStack(struct Stack *stack)
{
    if (stack) {
        int i = stack->top;
        puts("top: ");
        while (i != -1)
        {
            printf("%d\n", stack->array[i]);
            i--;
        }
    }
}

// Driver function
int main()
{
    struct Stack *s = createStack(10);

    // add items
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

    printStack(s);
    printf("capacity: %d", s->capacity);


}
