/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: silee <silee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 15:06:57 by silee             #+#    #+#             */
/*   Updated: 2022/06/01 15:30:33 by silee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>
# define BUFFER_SIZE 100
char	*get_next_line(int fd);
char	*txt_read(int fd, char *str, int *is_end);
int	    find_next(char *s, char c);
int		ft_strlen(char *str);
char	*ft_strjoin(char *str, char *buffer);
char	*ft_strcat(char *s1, char *s2);
char	*dup_loc(char *str, int loc_of_next);
char	*ft_substr(char *str, int start, int str_len);
char	*ret_line(char **str);
#endif
