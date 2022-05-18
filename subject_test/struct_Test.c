#include <stdio.h>
typedef struct s_test
{
    int a;
    int b;
    int c;
}   t_test;

int main()
{
    t_test t;
    printf("bf %d %d %d\n",t.a,t.b,t.c);


    printf("af %d %d %d\n",t.a,t.b,t.c);
}