#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *num;
    int i;

    i = 0;
    num = malloc(sizeof(int) * 10);
    while (i < 10)
    {
        num[i] = i;
        i++;
    }

    i = 0;
    // while (i < 10)
    //     printf("%d ,",num[i++]);
    printf("%d ,",num[12]);
}