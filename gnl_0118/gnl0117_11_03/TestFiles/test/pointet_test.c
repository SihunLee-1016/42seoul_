#include <stdio.h>
int sum(int **next1)
{
	printf("*next1 before 	  = %p\n",*next1);
	printf(" next1 before 	  = %p\n",next1);
	//printf("next val = %d\n",**next1);
	int b = 1;
	printf("value's adress = %p\n", &b);
	//**next1 = b; //ans = 2. main에서 주소값 변경 x
	//**next1 = &b; ko
	//*next1 = b ko
	*next1 = &b; //ans = 2. main 에서주소값 변경 o
	// next1 = b; ko
	// next1 = &b; ko
	printf("*next1 after	=	%p\n",*next1);
	printf(" next1 after	=	%p\n",next1);

	return (**next1 + **next1);
}

int main()
{
	int a = 3;
	int b;
	int *next2;
	next2 = &a;
	printf("next2 before	=	%p\n\n",next2);
	b = sum(&next2);
	printf("\nnext2 after	=	%p\n",next2);
	printf("%d\n",b);

}

