/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: silee <silee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 12:22:38 by silee             #+#    #+#             */
/*   Updated: 2022/07/14 17:05:41 by silee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_try_2_eat(t_philo *philo, t_data *data)
{
	pthread_mutex_lock(philo->left_f);
	printf("%d has taken a fork\n", philo->idx);
	pthread_mutex_lock(philo->right_f);
	printf("%d has taken a fork\n", philo->idx);
	
	pthread_mutex_lock(data->msg);
	printf("%d is eating\n",philo->idx);
	pthread_mutex_unlock(data->msg);

	pthread_mutex_unlock(philo->left_f);
	pthread_mutex_unlock(philo->right_f);

	philo->last_meal_time = get_time();
	ft_eat_time(philo, data);

	
	pthread_mutex_lock(data->msg);
	printf("%d is sleeping\n",philo->idx);
	pthread_mutex_unlock(data->msg);
	ft_nap_time(data);

	philo->eat_cnt += 1;
}
// 최소로 먹어야 하는 경우가 7인데, 한놈만 7번 먹고, 다른놈이 6번 먹었을 때 종료하는 경우가 있다.
// BUT cnt 중 최소값을 찾아서 그것을 반복문의 종료조건으로 주게 된다면 문제가 없을 것.

void	*ft_function(void *philo)
{
	t_philo *c_philo;
	t_data	*data;

	c_philo = (t_philo *)philo;
	data = c_philo->p_data;
	// 먹는 횟수 를 반복문의 조건으로.
	while (1)
	{
		if (data->die == 1)
			return ;
		ft_try_2_eat(c_philo, data);
		pthread_mutex_lock(data->msg);
		printf("%d is thinking\n", c_philo->idx);
		pthread_mutex_unlock(data->msg);
	
		// 생각해. 시간 고려.
	}
}


//pthread return value : function pointers return val.
int	ft_philo_start(t_all *all)
{
	int		i;
	void	*v_philo;

	i = 0;
	while (i < all->data->nop)
	{
		philo[i].last_meal_time = get_time();
		v_philo = (void *)&(all->philo[i]);
		if (pthread_create(&(all->philo[i].thr_id), NULL, ft_function, &v_philo))
			return (1);
		usleep(20);
		i++;
	}
	return (0);
}

void	ft_detach(t_all *all)
{
	int	i;

	i = 0;
	while (i < all->data->nop)
	{
		pthread_detach(all->philo[i]->thr_id);
		i++;
	}
}

void	ft_is_live(t_all *all)
{
	int			i;
	int			min;
	long long	n_time;

	while (1)
	{
		i = 0;
		min = all->philo[i]->eat_cnt;
		while (i < all->data->nop)
		{
			n_time = get_time();
			if (n_time - all->philo[i]->last_meal_time >= all->data->die_t)
				return (printf("%d  died\n",i));
			if (min >= all->philo[i].eat_cnt)
				min = all->philo[i].eat_cnt;
			i++;
		}
		if (min >= all->data->nome)
			return (/*모든 철학자가 최소 횟수이상 먹었다*/);
	}
}


//philo 전용 메세지 출력하기 ㅎㅎ.. write로.
int main(int argc, char **argv)
{
	t_all all;
    if (argc < 5 || argc > 6)
        return (1); // error msg
    if (ft_data_allocate (&all, argv) == 1)
        return (1); //error msg
	ft_philo_start(&all);
	ft_detach(&all);
	ft_is_live(&all);
}