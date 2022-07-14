/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_util.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: silee <silee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 21:01:33 by silee             #+#    #+#             */
/*   Updated: 2022/07/14 21:01:38 by silee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	if (s == 0)
		return ;
	while (s[i] != '\0')
		write (fd, &s[i++], 1);
}

void	ft_detach(t_all *all)
{
	int	i;

	i = 0;
	while (i < all->data->nop)
	{
		pthread_detach(all->philo[i].thr_id);
		i++;
	}
}	

void	ft_philo_print(t_philo *philo, t_data *data, char *str)
{
	long long	n_time;
	char		*time;
	char		*idx_of_p;

	n_time = get_time() - data->start_time;
	time = ft_itoa((int)n_time);
	idx_of_p = ft_itoa(philo->idx);
	pthread_mutex_lock(&data->msg);
	ft_putstr_fd(time, 1);
	write(1, " ", 1);
	ft_putstr_fd(idx_of_p, 1);
	write(1, " ", 1);
	ft_putstr_fd(str, 1);
	pthread_mutex_unlock(&data->msg);
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
