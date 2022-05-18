/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dd_list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: silee <silee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 19:45:02 by silee             #+#    #+#             */
/*   Updated: 2022/05/10 14:27:02 by silee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
t_node  make_node(int value)
{
    t_node  n_node;

    n_node = (t_node *)malloc(sizeof(t_node));
    n_node->left = NULL:
    n_node->right = NULL;
    n_node->data = value;
    return (n_node);
}

t_stack stack_init (void)
{
    t_stack *tmp_stack;

    tmp_stack = malloc(sizeof(t_stack));
    tmp_stack->head = NULL;
    tmp_stack->noe = 0;
    return (tmp_stack);
}

void	insert(t_stack *list, int value)
{
	t_node	*n_node;

	n_node = malloc(sizeof(t_node));
	n_node->data = value;
	if (list->head == NULL)
	{
		n_node->next = NULL;
		n_node->prev = NULL;
		list->head = n_node;
	}
	else
	{
		n_node->next = list->head;
		list->head->prev = n_node;
		n_node->prev = NULL;
		list->head = n_node
	}
	list->noe += 1;
}

void	make_stack_n_push(t_data_list *data, int argc, char **argv)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	data->stack_a = stack_init();
	while (++i < argc)
	{
		j = 0;
		while (argv[i][j] != '\0')
		{
			if (argv[i][j] >= '0' && argv[i][j] <= '9')
			{
				tmp = ft_atoi(argv[i][j]);
				insert (data->stack_a, tmp);
			}
			else if (ft_isspace(argv[i][j]) == 0)
				exit (1);
			j++;
		}
	}
	data->stack_b = stack_init();
}
