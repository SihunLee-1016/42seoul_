/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   philo.h											:+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: silee <silee@student.42seoul.kr>		   +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2022/07/13 12:22:18 by silee			 #+#	#+#			 */
/*   Updated: 2022/07/14 19:33:36 by silee			###   ########.fr	   */
/*																			*/
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
	long long		start_time;
	pthread_mutex_t	*fork;
	pthread_mutex_t	msg;
}					t_data;

typedef struct s_philo{
	pthread_mutex_t	*left_f;
	pthread_mutex_t	*right_f;
	pthread_t		thr_id;
	int				idx;
	int				eat_cnt;
	long long		last_meal_time;
	t_data			*p_data;
}					t_philo;

typedef struct s_all{
	t_philo	*philo;
	t_data	*data;
}			t_all;

// ft_atoi.c
int			ft_isspace(char sstr);
int			ft_atoi(const char *str);

// ft_itoa.c
int			len_of_int(int n);
int			plus_minus(int n);
char		*ft_itoa(int n);

// ft_calloc.c
void		*ft_calloc(size_t count, size_t size);

// ft_mutex_init.c
int			ft_mutex_init(t_data *data);
int			ft_philo_init(t_all *all);
int			ft_data_allocate(t_all *all, char **argv);

// ft_check_time.c
long long	get_time(void);
void		ft_eat_time(t_data *data);
void		ft_nap_time(t_data *data);

// ft_philo.c
int			ft_philo_dead(t_all *all, int j);
void		ft_try_2_eat(t_philo *philo, t_data *data);
void		*ft_action_start(void *philo);
int			ft_philo_start(t_all *all);
int			ft_is_live(t_all *all);

// ft_util.c
void		ft_philo_print(t_philo *philo, t_data *data, char *str);
void		ft_detach(t_all *all);
void		ft_putstr_fd(char *s, int fd);
void		*ft_memset(void *dest, int c, size_t len);
void		ft_bzero(void *s, size_t n);

#endif
