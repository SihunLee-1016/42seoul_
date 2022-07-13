/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: silee <silee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 12:22:18 by silee             #+#    #+#             */
/*   Updated: 2022/07/13 16:36:52 by silee            ###   ########.fr       */
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
    pthread_mutex_t	*fork;
    pthread_mutex_t msg;
    pthread_mutex_t sleep;
}					t_data;

typedef struct s_philo{
    int         left_f;
    int         right_f;
    int         eat_cnt;
	int			idx;
    long long   d_time;
    pthread_t   thr_id;
}				t_philo;

typedef struct s_all{
	t_philo *philo;
	t_data	data;
}			t_all;

int			ft_isspace(char sstr);
static int	ft_check_flow(long long num, int c, int minus);
int			ft_atoi(const char *str);

int ft_mutex_init (t_data *data);
int	ft_philo_init(t_philo *philo, t_data *data);
int ft_data_allocate(t_philo *philo, t_data *data, char **argv);

long long	get_time(void);


#endif
