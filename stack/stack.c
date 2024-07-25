#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct
{

    int *collection; // Pointer to a  array of int
    int capacity;    // capacity of values a stack can hold'
    int size;        // current capacity of stack

} Stack;

// func Declearation
Stack *create_stack(int capacity); // return a pointer to a stack
void destroy_stack(Stack *stack);
bool is_full(Stack *stack);         // return true if stack is full
bool is_empty(Stack *stack);        // return true if stack is empty
bool pop(Stack *stack, int *item);  // pop an item from the stack
bool push(Stack *stack, int item);  // push an item into the stack
bool peek(Stack *stack, int *item); // return item on top of the stack

int main(void)
{
    Stack *stack = create_stack(5);

    if (stack == NULL)
    {
        printf("Error creating stack.\n");
        return 1;
    }
    if (is_empty(stack))
        printf("Stack is empty.\n");

    push(stack, 2);
    push(stack, 3);
    push(stack, 4);
    push(stack, 5);
    push(stack, 6);

    if (is_full(stack))
        printf("stack is full");

    printf("stack size %d\n", stack->size);

    bool try_push = push(stack, 7);
    if (try_push == false)
        printf("Push failed.\n");

    destroy_stack(stack);

    return 0;
}

Stack *create_stack(int capacity)
{

    if (capacity <= 0)
        return NULL;

    Stack *stack = (Stack *)malloc(sizeof(Stack));
    if (stack == NULL)
        return NULL;

    stack->collection = (int *)malloc(sizeof(int) * capacity); // allocate space to accomudate the data
    if (stack->collection == NULL)
    {
        free(stack);
        return NULL;
    }
    stack->capacity = capacity;
    stack->size = 0;

    return stack;
}

void destroy_stack(Stack *stack)
{
    free(stack->collection);
    free(stack);
}

bool is_full(Stack *stack)
{
    return stack->capacity == stack->size;
}

bool is_empty(Stack *stack)
{
    return stack->size == 0;
}

bool push(Stack *stack, int item)
{
    if (is_full(stack))
        return false;

    stack->collection[stack->size] = item;
    stack->size++;

    return true;
}

bool peek(Stack *stack, int *item)
{
    /**
     * To peek at the top value of the stack
     * without popping it off
     */
    if (is_empty(stack))
        return false;

    *item = stack->collection[stack->size - 1];

    return true;
}

bool pop(Stack *stack, int *item)
{

    if (is_empty(stack))
        return false;

    /*
     * By reducing the size of the stack
     * You can pop items from the stack
     * as you can only add one time to the stack
     */
    stack->size--; // reducing the size has pop out the last item from the stack

    // returning the popped value  on the stack
    *item = stack->collection[stack->size];

    return true;
}
