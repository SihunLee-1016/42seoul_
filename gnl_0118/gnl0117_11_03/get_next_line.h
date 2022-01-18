/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: silee <silee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 16:38:59 by silee             #+#    #+#             */
/*   Updated: 2022/01/17 20:42:55 by silee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
char	*get_next_line(int fd);
char	*gnl_next(char **next, char *tmp);
void	ft_strjoin(char *s1, char *s2, int *line_len);
char	*ft_strdup(char *src,int *line_len);
char	*ft_strcat(char *res, char const *buffer);
int	ft_strlen(char *str);

#endif
