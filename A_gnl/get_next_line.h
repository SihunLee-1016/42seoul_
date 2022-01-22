#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# define ALLFIN 3
# define FINISH 2
# define RREAD 1
# define ERROR -1

char	*get_next_line(int fd);
int	loc_of_next(char *s, char c, int *signal);
int	    ft_strlen(char *str);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strcat(char *res, char *buffer);
char    *find_out_line(char **str, int *signal, int byte);
char	*ft_substr(char *s, int start, int len, int *signal);
int loc_of_null(char *s);

#endif
