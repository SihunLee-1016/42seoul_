/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: silee <silee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 21:00:55 by silee             #+#    #+#             */
/*   Updated: 2022/08/31 16:47:38 by silee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_philo_dead(t_all *all)
{	
	int	i;

	i = 0;
	while (i < all->data->nop)
	{
		pthread_join(all->philo[i++].thr_id, NULL);
		usleep(100);
	}
	i = 0;
	while (i < all->data->nop)
	{
		pthread_mutex_unlock(&all->data->fork[i]);
		pthread_mutex_destroy(&all->data->fork[i++]);
	}
	pthread_mutex_unlock(&all->data->msg);
	pthread_mutex_destroy(&all->data->msg);
	i = 0;
	free (all->data->fork);
	free (all->data);
	free (all->philo);
}

void	ft_try_2_eat(t_philo *philo, t_data *data)
{
	if (data->die_flag == 1)
		return ;
	pthread_mutex_lock(philo->left_f);
	pthread_mutex_lock(philo->right_f);
	if (data->die_flag == 1)
	{
		pthread_mutex_unlock(philo->left_f);
		pthread_mutex_unlock(philo->right_f);
		return ;
	}
	
	if (data->die_flag == 1)
		return ;
	ft_philo_print(philo, data, "has taken a fork\n");
	ft_philo_print(philo, data, "is eating\n");
	ft_eat_time(data);
	pthread_mutex_unlock(philo->left_f);
	pthread_mutex_unlock(philo->right_f);
	philo->last_meal_time = get_time();
	if (data->die_flag == 1)
		return ;
	ft_philo_print(philo, data, "is sleeping\n");
	if (data->die_flag == 1)
		return ;
	ft_nap_time(data);
	philo->eat_cnt += 1;
}

void	*ft_action_start(void *philo)
{
	t_philo	*c_philo;
	t_data	*data;

	c_philo = (t_philo *)philo;
	data = c_philo->p_data;
	while (1)
	{
		if (data->die_flag == 1)
			break ;
		ft_try_2_eat(c_philo, data);
		if (data->die_flag == 1)
			break ;
		ft_philo_print(c_philo, data, "is thinking\n");
		usleep(100);
	}
	return (0);
}

int	ft_philo_start(t_all *all)
{
	int		i;
	void	*v_philo;

	i = 0;
	all->data->start_time = get_time();
	while (i < all->data->nop)
	{
		all->philo[i].last_meal_time = get_time();
		v_philo = (void *)&(all->philo[i]);
		if (pthread_create(&(all->philo[i].thr_id), NULL, \
			ft_action_start, v_philo))
			return (1);
		usleep(100);
		i++;
	}
	return (0);
}

int	ft_is_live(t_all *all)
{
	int			i;
	int			min;
	long long	n_time;

	while (all->data->die_flag != 1)
	{
		i = 0;
		min = all->data->nome;
		while (i < all->data->nop && all->data->die_flag != 1)
		{
			n_time = get_time();
			if (n_time - all->philo[i].last_meal_time >= all->data->die_t)
			{
				// pthread_mutex_lock(&all->data->msg);
				ft_philo_print(all->philo, all->data, "is died\n");
				all->data->die_flag = 1;
			}
			if (min > all->philo[i].eat_cnt)
				min = all->philo[i].eat_cnt;
			i++;
		}
		if (min >= all->data->nome || all->data->die_flag == 1)
			all->data->die_flag = 1;
		usleep(100);
	}
	return (0);
}
