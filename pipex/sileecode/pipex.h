/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: silee <silee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 18:05:18 by silee             #+#    #+#             */
/*   Updated: 2022/05/04 20:43:13 by silee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <string.h>
# include <sys/wait.h>

# define STDIN 0
# define STDOUT 1
# define STDERR 2

void			ft_putstr_fd(char *s, int fd);
char			*make_path(char *tmp, char *cmd);
char			*find_path(char *cmd, char **envp);
void			cmd_start(char *cmd, char **envp);
void			pipe_n_fork(char *cmd, char **envp);
int				ft_file_1(char *file1);
int				ft_file_2(char *file2);
void			ft_make_exit(int status, char *message);
size_t			num_of_split(char const *s, char c);
size_t			len_of_str(char const *s, char c);
char			**free_all(char **s);
char			**ft_split(char const *s, char c);
int				ft_strncmp(const char *s1, const char *s2, unsigned int n);
int				idx_of_c(char *s, char c);
char			*ft_strndup(char *src, int n);
void			*ft_calloc(size_t count, size_t size);
void			ft_bzero(void *s, size_t n);
void			*ft_memset(void *dest, int c, size_t len);
unsigned int	ft_strlcpy(char *dest, const char *src, size_t size);

#endif
