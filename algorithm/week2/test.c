#include <stdio.h>
#include <stdlib.h>
int n_of_num(int num)
{
    if (num == 0)
        return (1);

    int len  = 0;
    while (num > 0)
    {
        num = num / 10;
        len++;
    }
    return (len);
}

int sum_of_num(int first, int second)
{
    // a + b > b + a --> 1 
    // b + a > a+ b --> 0
    int fir_n = n_of_num(first);
    int sec_n = n_of_num(second); 

    int fs = first;
    int sf = second;

    while (sec_n-- > 0)
        fs = fs * 10;
    while (fir_n-- > 0)
        sf = sf * 10;

    printf("fs = %d",fs+second);
    printf("sf = %d",sf+first );
    
    if (fs + second > sf + first)
        return (1);
    else
        return (0);
}
int main (){
    int a = 70;
    int b = 2;
    int result;

    result = sum_of_num(a,b);
}