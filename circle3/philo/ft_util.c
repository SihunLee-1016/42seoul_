/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_util.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: silee <silee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 21:01:33 by silee             #+#    #+#             */
/*   Updated: 2022/07/15 15:49:26 by silee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_print(t_data *data, int n_time, int idx_of_p, char *str)
{
	pthread_mutex_lock(&data->msg);
	printf("%d %d %s", n_time, idx_of_p, str);
	pthread_mutex_unlock(&data->msg);
}

void	ft_philo_print(t_philo *philo, t_data *data, char *str)
{
	long long	n_time;

	n_time = get_time() - data->start_time;
	usleep(100);
	ft_print(data, n_time, philo->idx, str);
	usleep(100);
}

void	*ft_memset(void *dest, int c, size_t len)
{
	size_t			i;
	unsigned char	*tmp;

	tmp = (unsigned char *)dest;
	i = 0;
	while (i < len)
	{
		*(tmp + i) = (unsigned char)c;
		i++;
	}
	return (tmp);
}

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}
