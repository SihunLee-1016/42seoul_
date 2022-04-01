#include <stdio.h>
#include <stdlib.h>

# define ERROR -1


typedef struct Stack_node_type{
    int   data;
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

void minStackPush(MinStack* obj, int val)
{
    if (!obj)
        return ;
    Stack_Node *new;
    Stack_Node *tmp;
    new = create_node(val);

    if (!obj->top)
        obj->top = new;
    else
    {
        tmp = obj->top;
        obj->top = new;
        new->next = tmp;
    }
}

void minStackPop(MinStack* obj)
{
    if (!obj)
        return ;
    Stack_Node *tmp;

    tmp = obj->top;
    obj->top = tmp->next;
    free(tmp);
}

int minStackTop(MinStack* obj)
{
    if (!obj)
        return (ERROR);
    int data;

    data = obj->top->data;
    return (data);
}

int minStackGetMin(MinStack* obj)
{
    int min;
    Stack_Node *node;

    if (!obj)
        return (ERROR);
    node = obj->top;
    min = obj->top->data;
    while (node != NULL)
    {
        if (min > node->data)
            min = node->data;
        node = node->next;
    }
    return (min);
}

void minStackFree(MinStack* obj)
{
    Stack_Node *node;
    Stack_Node *tmp;

    node = obj->top;
    while (!node)
    {
        tmp = node;
        node = node->next;
        free (tmp);
    }
}