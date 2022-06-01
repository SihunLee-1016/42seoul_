/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: silee <silee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 16:00:39 by silee             #+#    #+#             */
/*   Updated: 2022/06/01 18:17:13 by silee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>

# include "./mlx/mlx.h"
#define BUFFER_SIZE 100

typedef struct s_img
{
    void    *coin;
    void    *player;
    void    *ground;
    void    *wall;
    void    *exit;
}   t_img;

typedef struct s_data
{
    int     map_height;
    int     map_width;
    char    *map_line;
    t_img   img;
    void    *mlx;
    void    *win;
}   t_data;

typedef struct s_cnt
{
    int coin;
    int exit;
    int start;
}   t_cnt;


char	*get_next_line(int fd);
char	*txt_read(int fd, char *str, int *is_end);
int	    find_next(char *s, char c);
int		ft_strlen(char *str);
char	*ft_strjoin(char *str, char *buffer);
char	*ft_strcat(char *s1, char *s2);
char	*dup_loc(char *str, int loc_of_next);
char	*ft_substr(char *str, int start, int str_len);
char	*ret_line(char **str);

char	*ft_strcpy(char *dest, char *src);
char	*ft_strdup_without_nl(char *src);
char	*ft_join_without_nl(char *s1, char *s2);
char	*ft_strcat_without_nl(char *s1, char *s2);
char	*ft_strcpy_wo_nl(char *dest, char *src);

void    map_2_array(t_data *game_data, char *file);
// void    map_2_array(t_data *game_data);

void	error_exit(void);
void	is_wall(t_data *g_data, int flag);

// void	count_init(t_cnt *count);
t_cnt	*count_init(void);


void	map_parameter_check(t_cnt *count);

void	check_valid_map(t_data *g_data, char *file);


void    map_draw(t_data *g);
t_img   img_input(void *mlx);



#endif
