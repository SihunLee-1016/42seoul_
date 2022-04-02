#include <stdio.h>
int main(){
    int a[4] = {1,2,3,-1};
    int *p;
    int *q;
    p = a;
    q = p + 1;

    printf("%d ", (int)(q - p));
}