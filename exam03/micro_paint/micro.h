#ifndef MICRO_H
# define MICRO_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

# define OUT 1
# define BORDER 2
# define IN 3

typedef struct s_info{
    int     b_wid;
    int     b_hei;
    char    back_ground;
    char    type;
    float   start_x;
    float   start_y;
    float   s_wid;
    float   s_hei;
    char    color;
    char    *matrix;
}           t_info;

int	get_info(t_info *info, FILE *file);
int	execute(t_info *info, FILE *file);
void	execute_one(t_info *info);
void	draw(t_info *info, int x, int y);
int	check_valid(t_info *info);
int	check_border(t_info *info, float x, float y);

#endif