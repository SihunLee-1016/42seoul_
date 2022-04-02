#include <stdio.h>
#include <stdlib.h>
#include <stdboolh>

typedef struct Stack_node_type{
    char   data;
    struct Stack_node_type *next;
}Stack_Node;


typedef struct MinStack
{
    Stack_Node    *top;
}MinStack;

MinStack* minStackCreate()
{
    MinStack *stack;

    stack = (MinStack *)malloc(sizeof(MinStack));
    if (!stack)
        return (NULL);
    stack->top = NULL;
    return (stack);
}

Stack_Node *create_node(int data)
{
    Stack_Node *Node;

    Node = (Stack_Node *)malloc(sizeof(Stack_Node));
    if (!Node)
        return (NULL);
    Node->data = data;
    Node->next = NULL;
    return (Node);
}

int check_par(char *s)
{
    if (*s = '(')
        return 
    else if(*s =')')

    else if(*s ='{')

    else if(*s ='}')

    else if(*s ='[')

    else if(*s =']')


}

bool isValid(char *s)
{
    MinStack    *stack;
    int         valid;

    while (*s)
    {

    }

}
//( { [ } ])