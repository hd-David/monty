#include "monty.h"
#include <string.h>

unsigned int line_number = 1;

int main(void)
{
  char opcode[10];
  int argument;
  stack_t *stack = NULL;
    initializeStack(&stack);

    while (scanf("%9s", opcode) == 1)
    {
        if (strcmp(opcode, "push") == 0)
        {
            if (scanf("%d", &argument) != 1)
            {
                fprintf(stderr, "L%d: Error: usage: push integer\n", line_number);
                exit(EXIT_FAILURE);
            }
            push(&stack, argument);
        }
        else if (strcmp(opcode, "pall") == 0)
        {
            printStack(&stack);
        }
        else
        {
            fprintf(stderr, "L%d: Error: unknown instruction %s\n", line_number, opcode);
            exit(EXIT_FAILURE);
        }
        line_number++;
    }

    return 0;
}
