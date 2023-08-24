#include "monty.h"

extern unsigned int line_number;


/**
 * initializeStack - Initialize the stack structure
 * @stack: Pointer to the stack structure
 */
void initializeStack(stack_t **stack)
{
    *stack = NULL;
}

/**
 * push - Pushes an element onto the stack
 * @stack: Pointer to the stack structure
 * @value: Integer to be pushed onto the stack
 */
void push(stack_t **stack, int value)
{
    stack_t *new_node = malloc(sizeof(stack_t));
    if (!new_node)
    {
        fprintf(stderr, "Error: malloc failed\n");
        exit(EXIT_FAILURE);
    }

    new_node->n = value;
    new_node->prev = NULL;
    new_node->next = *stack;

    if (*stack)
        (*stack)->prev = new_node;

    *stack = new_node;
}

/**
 * pop - Pops an element from the stack
 * @stack: Pointer to the stack structure
 * Return: Popped element
 */
int pop(stack_t **stack)
{
  int value = (*stack)->n;
    stack_t *temp = *stack;
    if (!*stack)
    {
        fprintf(stderr, "L%d: Error: can't pop an empty stack\n", line_number);
        exit(EXIT_FAILURE);
    }

    *stack = (*stack)->next;
    if (*stack)
        (*stack)->prev = NULL;
    free(temp);

    return value;
}

/**
 * printStack - Prints all elements in the stack
 * @stack: Pointer to the stack structure
 */
void printStack(stack_t **stack)
{
    stack_t *current = *stack;
    while (current)
    {
        printf("%d\n", current->n);
        current = current->next;
    }
}
