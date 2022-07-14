/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: silee <silee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 12:22:18 by silee             #+#    #+#             */
/*   Updated: 2022/07/14 16:57:35 by silee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <sys/time.h>
# include <string.h>
# include <limits.h>

typedef struct s_data{
    int				nop;
	int				nome;
    int				die_t;
    int				eat_t;
    int				nap_t;
	int				die;
    pthread_mutex_t	*fork;
    pthread_mutex_t msg;  
}					t_data;

typedef struct s_philo{
    pthread_mutex_t *left_f;
    pthread_mutex_t *right_f;
    pthread_t   	thr_id;
	int				idx;
    int         	eat_cnt;
    long long   	last_meal_time;
	t_data			*p_data;
}					t_philo;

typedef struct s_all{
	t_philo *philo;
	t_data	*data;
}			t_all;

int			ft_isspace(char sstr);
static int	ft_check_flow(long long num, int c, int minus);
int			ft_atoi(const char *str);

int 		ft_mutex_init (t_data *data);
int			ft_philo_init(t_all *all);
int 		ft_data_allocate(t_all *all, char **argv);

long long	get_time(void);
void		ft_eat_time(t_philo *philo, t_data *data);
void		ft_nap_time(t_data *data);


#endif
