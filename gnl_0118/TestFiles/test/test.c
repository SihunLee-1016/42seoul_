#include <stdio.h>
int main(){
    char a[] = "12346";
    char *b;
    b = a;

    printf("%p\n",a);
    char **p;
    
    printf("%p\n",p);

    *p = a;

    printf("%s",*p);
}
