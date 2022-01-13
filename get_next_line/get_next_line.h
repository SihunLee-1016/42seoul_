/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: silee <silee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 16:38:59 by silee             #+#    #+#             */
/*   Updated: 2022/01/13 15:35:17 by silee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
char	*get_next_line(int fd);
char	*ft_strdup(char *buffer, int *line_len);
char	*ft_strncpy(char *ret, char *buffer, int len);
char	*gnl_next(char **next);

#endif
