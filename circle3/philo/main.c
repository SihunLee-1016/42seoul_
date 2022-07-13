/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: silee <silee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 12:22:38 by silee             #+#    #+#             */
/*   Updated: 2022/07/13 16:39:25 by silee            ###   ########.fr       */
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

void	ft_function(void *philo)
{
	printf("HI");
	// if(pthread_mutex_unlock())
}

int	ft_philo_start(t_philo *philo, t_data *data)
{
	int		i;
	void	*v_philo;

	i = -1;
	while (++i < data->nop)
	{
		philo[i].d_time = get_time();
		v_philo = (void *)&(philo[i]);
		if (pthread_create(&(philo[i].thr_id), NULL, ft_function, v_philo))
			return (1);
		usleep(10);
	}
}

int main(int argc, char **argv)
{
    // t_philo *philo;
    // t_data  data;

    // if (ac < 5 || ac > 6)
    //     return (1); // error msg
    // memset(&data, 0, sizeof(t_data));
    // if (ft_data_allocate (philo, &data, argv) == 1)
    //     return (1); //error msg
	// ft_philo_start();

	t_all all;

    if (argc < 5 || argc > 6)
        return (1); // error msg
    memset(&all.data, 0, sizeof(t_data));
 
    if (ft_data_allocate (all.philo, &(all.data), argv) == 1)
        return (1); //error msg

	// ft_philo_start();
}