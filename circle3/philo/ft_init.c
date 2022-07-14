/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   ft_init.c										  :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: silee <silee@student.42seoul.kr>		   +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2022/07/13 15:22:50 by silee			 #+#	#+#			 */
/*   Updated: 2022/07/14 19:31:15 by silee			###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "philo.h"

int	ft_mutex_init(t_data *data)
{
	int	i;

	i = -1;
	if (pthread_mutex_init(&(data->msg), NULL))
		return (1);
	data->fork = malloc(sizeof(pthread_mutex_t) * data->nop);
	if (!(data->fork))
		return (1);
	while (++i < data->nop)
	{
		if (pthread_mutex_init(&(data->fork[i]), NULL))
			return (1);
	}
	return (0);
}

int	ft_philo_init(t_all *all)
{
	int	i;

	i = 0;
	while (i < all->data->nop)
	{
		all->philo[i].idx = i + 1;
		all->philo[i].left_f = &all->data->fork[i];
		all->philo[i].right_f = &all->data->fork[(i + 1) % all->data->nop];
		all->philo[i].last_meal_time = 0;
		all->philo[i].eat_cnt = 0;
		all->philo[i].p_data = all->data;
		i++;
	}
	return (0);
}

int	ft_data_allocate(t_all *all, char **argv)
{
	all->data = malloc(sizeof(t_data));
	if (!(all->data))
		return (1);
	all->data->nop = ft_atoi(argv[1]);
	all->data->die_t = ft_atoi(argv[2]);
	all->data->eat_t = ft_atoi(argv[3]);
	all->data->nap_t = ft_atoi(argv[4]);
	if (argv[5])
		all->data->nome = ft_atoi(argv[5]);
	else
		all->data->nome = INT_MAX;
	all->data->start_time = 0;
	if (all->data->nop < 0 || all->data->die_t < 0 || all->data->eat_t < 0 || \
	all->data->nap_t < 0 || all->data->nome < 0)
		return (1);
	if (ft_mutex_init(all->data) == 1)
		return (1);
	all->philo = malloc(sizeof(t_philo) * (all->data->nop));
	if (!all->philo)
		return (1);
	if (ft_philo_init(all) == 1)
		return (1);
	return (0);
}
