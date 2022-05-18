
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <string.h>
# include <sys/wait.h>

typedef struct s_node
{
	int				data;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

typedef struct s_stack
{
    int             noe;
	struct s_node	*head;
}	t_stack;

typedef struct s_var
{
	int				max_size;
	int				*sorted_array;
	struct s_stack	*stack_a;
	struct s_stack	*stack_b;
	struct s_list	*list;
	int				a_size;
	int				b_size;
}	t_data_list;

void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int partition(int dataset[], int left, int right)
{
    int first;
    int pivot;

    first = left;
    pivot = dataset[first];
    left += 1;
    while (left <= right)
    {
        while (dataset[left] <= pivot && left < right)
            left++;
        while (dataset[right] > pivot && left <= right)
            right--;
        if (left < right)
            swap (&dataset[left], &dataset[right]);
        else
            break ;
    }
	swap (&dataset[first], &dataset[right]);
	return (right);
}

void quick_sort(int dataset[], int left, int right)
{
	if (left < right)
	{
		int idx;

		idx = partition (dataset, left, right);
		quick_sort (dataset, left, idx - 1);
		quick_sort (dataset, idx + 1, right);
	}
}
void	is_valid(char *sstr)
{
    int i;

    i = 0;
    while (sstr[i])
    {
        if (!(sstr[i] >= '0' && sstr[i] <= '9'))
        {
            write (1, "ERROR", 6);
            exit (1);
        }
        i++;
    }
    return ;
}

static int	ft_check_flow(long long num, int c, int minus)
{
	num = num * minus;
	c = c - '0';
	if (minus == 1)
		if (num * 10 + c < num)
			return (1);
	if (minus == -1)
		if (num * 10 - c > num)
			return (2);
	return (0);
}

int	ft_atoi(char *str)
{
	long long	num;
	int			p_m;
	int			i;

	num = 0;
	p_m = 1;
	i = 0;

    is_valid (str);
	if (str[i] == '-')
		p_m = -1;
	if (str[i] == '-' || str[i] == '+')
		i += 1;
	while ((str[i] >= '0' && str[i] <= '9') && str[i])
	{
		if (ft_check_flow(num, str[i], p_m) != 0)
			exit (1);
		num = (10 * num) + str[i] - 48;
		i++;
	}
	return ((int)(p_m * num));
}

int *make_sorted_array(int argc, char **argv)
{
    int i;
    int j;
    int *num_array;
    
    i = 1;
    j = 0;
    num_array = (int *)malloc(sizeof(int) * (argc - 1));
    if (num_array == 0)
        return (0);
    while (argv[i])
    {
        num_array[j] = ft_atoi(argv[i]);
        i++;
        j++;
    }
    num_array[i] = 0;
    i = 0;
    //quicksort로 정렬
    //qsort(num_array, argc, sizeof(int),)

    return (num_array);
}
void	check_duplicated(int argc, int *nums)
{
	int	check_idx;
	int	rotate_idx;

	check_idx = 0;
	while (check_idx < argc)
	{
		rotate_idx = 0;
		while (rotate_idx < argc)
		{
			if (check_idx == rotate_idx)
            {
                rotate_idx += 1;
				continue ;
            }
			if (nums[check_idx] == nums[rotate_idx])
			{
				write (1, "DUP ERROR", 10);
				exit (1);
			}
			rotate_idx +=1 ;
		}
		check_idx += 1;
	}
}

void displayDoublyList(t_stack* pList){
	if (pList->noe <= 0 )
	{
		fprintf(stderr, "No element in D_list to Display.\n");
		return ;
	}
	
	t_stack *head = pList->head.next;
	t_stack *tail = pList->head.prev;

	printf(" == Double_Linked_List == \n\n [Head] <-> ");
	
	while (head != tail){
		printf("%d <-> ",head->data);
		head = head->next;
	}
	printf("%d <-> [tail (A.K.A Head)]\n\n == Dispaly_End == \n\n\n",head->data);
}

int main(int argc, char **argv)
{
    t_data_list *data;


    make_stack_n_push(data, argc, argv);
    displayDoublyList(data->stack_a);

}