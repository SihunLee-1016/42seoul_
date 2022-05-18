#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
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
    Stack_Node *new;
    Stack_Node *tmp;
    new = create_node(val);

    if (!obj)
    {
        obj = new;
        obj->top = new;
    }
    else
    {
        tmp = obj->top;
        obj->top = new;
        new->next = tmp;
    }
}

int minStackPop(MinStack* obj)
{
    if (!obj)
        return (-1);
    Stack_Node *node;
    int        re_data;

    node = obj->top;
    while (node->next != 0)
        node = node->next;

    re_data = node->data;
    printf("POP  re_data : %d\n",re_data);
    free(node);
    return (re_data);
}

int check_par(char *s)
{
    if (*s = '(')
        return (1);
    else if(*s ='{')
        return (2);
    else if(*s ='[')
        return (3);
    else if(*s =')')
        return (4);
    else if(*s ='}')
        return (5);
    else if(*s =']')
        return (6);
    else
        return (0);
}

bool isValid(char *s)
{
    MinStack    *stack;
    int         val;
    int         noe = 0;
    char        pre_val;

    while (*s)
    {
        val = check_par(s);
        if (val >= 1 && val <= 3)
        {
            minStackPush(stack, val);
            noe += 1;
        }
        else if (val >= 4 && val <= 6)
        {
            pre_val = minStackPop(stack);
            printf("pre_val = %d\n",pre_val);
            if (pre_val != val - 3)
                return (false);
            noe = noe - 1;
        }
        s++;
    }
    if (noe != 0)
        return (false);
    return (true);
}