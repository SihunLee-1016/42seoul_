#include <stdio.h>
# define SUCCESS 1
# define END 0

int input(int *p)
{
    int input_num = 0;
    int noe = 0;

    while (1)
    {
        scanf("%d", &input_num);
        if (input_num < 0)
            return (noe);
        *p = input_num;
        noe += 1;
        p++;
    }
    return (noe);
}

int *sel_next(int *p)
{    
    //증,감이 있는 경우에 if문에 들어가 반복하게됨.
    //증가
    if (*(p + 1) > *p)
	{
		while (*(p + 1) > *p)
			p++;
	}
    //감th
    else if (*(p + 1) < *p)
	{
        while (*(p + 1) < *p)
		{
			if (*(p + 1) < 0)
				return (p);
			p++;
		}
	}
    return (p);
}

int number(int *p, int *q)
{
	int	repeat;
	int ret = 0;
	int i = 0;

	repeat = (int)(q - p);
	// 0이 맨 앞에 오는 경우엔 0을 제외하고 출력.
	//0이 맨 앞이 아닌 경우엔 그냥 출력. *10을 해주기

	if (*p == 0)
	{
		p++;
		i++;
	}
	while (i <= repeat)
	{
		ret = ret * 10 + *p;
		i++;
		p++;
	}
	return (ret);
}

int main ()
{
    int num[100];
    int noe;
    int *numbers;
    int *end;
    int i = 0;
	int result;


    noe = input(num); //입력이 종료됨.
    numbers = num;
    while (i < noe + 1 && )
    {
	    end = sel_next(numbers);
		printf("end value = %d\n",*end);
		if (*end < 0)
			return (0);
		if (end == numbers)
		{
			numbers++;
			i++;
			continue ;
		}
		result = number(numbers, end);
		i += (int)(end - numbers);
		numbers += (int)(end - numbers);
		printf("%d\n",result);
    }
	return (0);
}

//뭔가...이상함...
