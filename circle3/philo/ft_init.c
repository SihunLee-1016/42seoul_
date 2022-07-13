/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: silee <silee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 15:22:50 by silee             #+#    #+#             */
/*   Updated: 2022/07/13 16:40:28 by silee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
int ft_mutex_init (t_data *data)
{
    int i;

    i = -1;
    if (pthread_mutex_init(&(data->msg), NULL))
        return (1);
    if (pthread_mutex_init(&(data->sleep), NULL))
        return (1);
    data->fork = malloc(sizeof(pthread_mutex_t) * data->nop);
    if (!(data->fork))
        return (1);
    while (++i < data->nop)
    {
        if (pthread_mutex_init(&(data->fork[i]), NULL))
            return (1);
		pthread_mutex_lock(&(data->fork[i]));
    }
    return (0);
}

int	ft_philo_init(t_philo *philo, t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->nop)
	{
		philo->idx = i;
		philo->left_f = i;
		philo->right_f = (i + 1) % data->nop;
		philo->d_time = 0;
		philo->eat_cnt = 0;
        printf("idx : %d, left_i : %d, right_f : %d\n",philo->idx, philo->left_f, philo->right_f);
	}
	return (0);
}

int ft_data_allocate(t_philo *philo, t_data *data, char **argv)
{
    data->nop = ft_atoi(argv[1]);
    data->die_t = ft_atoi(argv[2]);
    data->eat_t = ft_atoi(argv[3]);
    data->nap_t = ft_atoi(argv[4]);
    if (argv[5])
        data->nome = ft_atoi(argv[5]);
    else
        data->nome = INT_MAX;
	if (data->nop < 0 || data->die_t < 0 || data->eat_t < 0 /
		data->nap_t < 0 || data->nome < 0)
			return (1);
    printf ("\nnop : %d, die_t : %d, eat_t : %d, nap_t : %d, nome : %d\n", data->nop, data->die_t, data->eat_t, data->nap_t, data->nome);
    if (ft_mutex_init(data) == 1)
        return (1);
	philo = malloc(sizeof(t_philo) * (data->nop));
	if (!philo)
		return (1);
	if (ft_philo_init(philo, data) == 1)
		return (1);
	return (0);
}