/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: silee <silee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 21:02:02 by silee             #+#    #+#             */
/*   Updated: 2022/07/15 16:04:15 by silee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_all	all;

	if (argc < 5 || argc > 6)
	{
		printf("Argument number invalid.\n");
		return (1);
	}
	if (ft_data_allocate (&all, argv) == 1)
	{
		printf("Data allocate failed.\n");
		return (1);
	}
	if (all.data->nop == 1)
	{
		printf("0 1 is died\n");
		return (0);
	}
	ft_philo_start(&all);
	if (ft_is_live(&all) == 0)
		ft_philo_dead(&all);
	return (0);
}
