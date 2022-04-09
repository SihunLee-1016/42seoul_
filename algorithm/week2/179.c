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
// char	*ft_itoa(int n)
// {
// 	int	len;
// 	char			*p;

// 	len = num_len(n);
// 	p = calloc(len + 1, sizeof(char));
// 	if (!p)
// 		return (0);
// 	while (len-- > 0)
// 	{
// 		p[len] = n % 10 + '0';
// 		n = n / 10;
// 	}
// 	return (p);
// }

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
    
    if (fs + second > sf + first)
        return (1);
    else
        return (0);

}

// a+b vs b+a 값 비교. (70 5 -> 705 && 570) 7 500 7500 5007
// 700 + 5 (1자리수이므로 70에 10을 한번 곱해줌.)
// 500 + 70 (2자리수이므로 5에 10을 2번 곱해줌)
// a+b 가 값이 크다면 a,b로 정렬.
void largestNumber(int* nums, int numsSize){
    int out = 0;
    int in;
    int tmp = 0;
    int result;
    int i = 0;

    while (out < numsSize)
    {
        in = 0;
        while (in < numsSize)
        {
            //0이면 in + 1이 앞으로 이동.
            if (sum_of_num(nums[in],nums[in + 1]) == 0)
            {
                tmp = nums[in];
                nums[in] = nums[in + 1];
                nums[in + 1] = tmp;
            }
            in++;
        }
        out++;
    }
    while (i < numsSize +1)
    {
        printf("%d ",nums[i]);
        i++;
    }
    printf("result = %d", result);
}

int main()
{
    int *nums;
    int num[] ={9,4,1,2,78,4,1,2};
    nums = num;
    largestNumber(nums,5);
}
//버블? 퀵?
//일단 버블로 구현.