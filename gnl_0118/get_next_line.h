/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: silee <silee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 16:38:59 by silee             #+#    #+#             */
/*   Updated: 2022/01/19 16:35:40 by silee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
char	*get_next_line(int fd);
char    *gnl_next(char *next, char **tmp, int *signal);
char	*ft_substr(char *s, int start, int len, int *signal);
char	*ft_strjoin(char *s1, char *s2, int *signal);
char	*ft_strcat(char *res, char *buffer);
int     ft_strlen(char *str);


#endif
