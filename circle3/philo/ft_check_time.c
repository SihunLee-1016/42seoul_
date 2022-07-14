/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_time.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: silee <silee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 15:57:22 by silee             #+#    #+#             */
/*   Updated: 2022/07/14 16:02:28 by silee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "philo.h"
long long	get_time(void)
{
	struct timeval	time;
	long long		ms;

	gettimeofday(&time, NULL);
	ms = (time.tv_sec * 1000) + (time.tv_usec / 1000);
	return (ms);
}

void	ft_eat_time(t_philo *philo, t_data *data)
{
	long long	start_time;
	long long	now_time;
	
	start_time = get_time();
	while (data->die != 1)
	{
		now_time = get_time();
		if (now_time - start_time >= (long long)data->eat_t)
			break;
		usleep (10);
	}
    philo->d_time += data->die_t;
}

void	ft_nap_time(t_data *data)
{
	long long	start_time;
	long long	now_time;
	
	start_time = get_time();
	while (data->die != 1)
	{
		now_time = get_time();
		if (now_time - start_time >= (long long)data->nap_t)
			break;
		usleep (10);
	}
}
