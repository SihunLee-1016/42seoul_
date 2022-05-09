/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: silee <silee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 16:16:19 by silee             #+#    #+#             */
/*   Updated: 2022/05/09 18:00:36 by silee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
		{
			write (1, "ERROR", 6);
			exit (1);
		}
		num = (10 * num) + str[i] - 48;
		i++;
	}
	return ((int)(p_m * num));
}