/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   so_long.h										  :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: silee <silee@student.42seoul.kr>		   +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2022/05/28 16:00:39 by silee			 #+#	#+#			 */
/*   Updated: 2022/06/02 18:26:26 by silee			###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>

# include "./mlx/mlx.h"

# define BUFFER_SIZE 100

# define X_EVENT_KEY_PRESS  2
# define X_EVENT_KEY_RELEASE 3
# define X_EVENT_KEY_EXIT 17
# define KEY_ESC		53
# define KEY_W			13
# define KEY_A			0
# define KEY_S			1
# define KEY_D			2

typedef struct s_img
{
	void	*coin;
	void	*player;
	void	*ground;
	void	*wall;
	void	*exit;
	void	*monster;
}	t_img;

typedef struct s_data
{
	int		height;
	int		width;
	char	*line;
	int		noc;
	int		move;
	t_img	img;
	void	*mlx;
	void	*win;
}	t_data;

typedef struct s_cnt
{
	int	coin;
	int	exit;
	int	start;
}	t_cnt;

//gnl
char	*get_next_line(int fd);
char	*txt_read(int fd, char *str, int *is_end);
int		find_next(char *s, char c);
int		ft_strlen(char *str);
char	*ft_strjoin(char *str, char *buffer);
char	*ft_strcat(char *s1, char *s2);
char	*dup_loc(char *str, int loc_of_next);
char	*ft_substr(char *str, int start, int str_len);
char	*ret_line(char **str);
//ft_strdup_without_nl.c
char	*ft_strcpy_wo_nl(char *dest, char *src);
char	*ft_strdup_without_nl(char *src);
//ft_join_without_nl.c
char	*ft_strcat_without_nl(char *s1, char *s2);
char	*ft_join_without_nl(char *s1, char *s2);
//map_check.c
void	map_2_array(t_data *game_data, char *file);
void	is_wall(t_data *g_data, int flag);
t_cnt	*count_init(void);
void	parameter_check(t_cnt *count);
void	check_valid_map(t_data *g_data, char *file);
int	ft_strlen_wo_nl(char *str);
//map_draw.c
t_img	img_input(void *mlx);
void	img_2_window(t_data *g, int w, int h);
void	map_draw(t_data *g);
//key.c
void	game_exit(t_data *g_data);
void	key_w(t_data *g_data);
void	key_a(t_data *g_data);
void	key_s(t_data *g_data);
void	key_d(t_data *g_data);
//utils.c
void	error_exit(int  flag);
//so_long.c
int		destroy_game(t_data *g_data);
int		key_press(int key, t_data *g_data);
#endif
