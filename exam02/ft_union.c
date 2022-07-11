#include <stdio.h>
#include <unistd.h>
#include <string.h>
int ft_check_dup(char *s1, char c, int i)
{
    while (s1[--i])
    {
        if (s1[i] == c)
            return (1);
    }
    return (0);
}


int main(int ac, char **argv)
{
    int i = -1;

    while (argv[1][++i])
    {
        if (ft_check_dup(argv[1], argv[1][i], i) == 0)
            printf("%c", argv[1][i]);
    }
    i = -1;
    while (argv[2][++i])
    {
        if (ft_check_dup(argv[2], argv[2][i], i) == 0)
        {
            if (ft_check_dup(argv[1], argv[2][i], (int)strlen(argv[1])) == 0)
                printf("%c", argv[2][i]);
        }
    }
    printf("%d", (int)strlen(argv[1]));
}