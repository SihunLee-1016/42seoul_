/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: silee <silee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 16:00:39 by silee             #+#    #+#             */
/*   Updated: 2022/05/30 20:23:48 by silee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

#define BUFFER_SIZE 100
typedef struct s_data
{
    int fd;
    int map_height;
    int map_width;
    char    *map_line;
}   t_data;

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

void    map_2_array(char *file, t_data *game_data);


#endif
