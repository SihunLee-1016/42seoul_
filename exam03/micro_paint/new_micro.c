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

int check_valid(t_info *info)
{
	if (info->s_wid <= 0.00000000 || info->s_hei <= 0.00000000 
		|| (info->type != 'R' && info->type != 'r'))
		return (1);
	return (0);
}
int	check_border(t_info *info, float x, float y)
{
	if (x < info->start_x || x > info->start_x + info->s_wid 
		|| y < info->start_y || y > info->start_y + info->s_hei)
		return (OUT);
	else if (x - info->start_x < 1.00000000 || (info->start_x + info->s_wid) - x < 1.00000000
		|| y - info->start_y < 1.00000000 || (info->start_y + info->s_hei) - y < 1.00000000)
		return (BORDER);
	else
		return (IN);
}

void	draw(t_info *info, int x, int y)
{
	int	is_in;

	is_in = check_border(info, (float)x, (float)y);
	if (is_in == BORDER || (is_in == IN && info->type == 'R'))
		info->matrix[x + y * info->b_wid] = info->color;
	return ;
}

void	execute_one (t_info *info)
{
	int	x;
	int	y;

	x = 0;
	printf("in excuteone\n");
	while (x < info->b_wid)
	{
		y = 0 ;
		while (y < info->b_hei)
		{
			draw(info, x, y);
			y++;
		}
		x++;
	}
}

int		execute (t_info *info, FILE *file)
{
	int	scan_ret;

	scan_ret = fscanf(file, "%c %f %f %f %f %c\n", &info->type, &info->start_x, &info->start_y, &info->s_wid, &info->s_hei, &info->color);
	printf("scan ret = %d\n",scan_ret);
	printf ("bf e_o\n");
	while (scan_ret == 6)
	{
		if (check_valid(info) == 1)
			return (1);
		execute_one(info);
		scan_ret = fscanf(file, "%c %f %f %f %f %c\n", &info->type, &info->start_x, &info->start_y, &info->s_wid, &info->s_hei, &info->color);
	}
	int	i = 0;
	if (scan_ret == -1)
	{
		while ( i < info->b_hei)
			printf("%.*s\n", info->b_wid, info->matrix + i++ * info->b_wid);

	}
	return (0);
}

int	get_info(t_info *info, FILE *file)
{
	int	i;

	i = -1;
	fscanf(file, "%d %d %c\n", &info->b_wid, &info->b_hei, &info->back_ground);
	if (info->b_wid < 1 || info->b_wid > 300 || info->b_hei < 1 || info->b_hei > 300)
		return (1);
	info->matrix = malloc (sizeof(char *) * (info->b_hei * info->b_wid));
	if (!info->matrix)
		return (1);
	while (++i < info->b_wid * info->b_hei)
		info->matrix[i] = info->back_ground;
	return (0);
}

int main(int ac, char **av)
{
    t_info info;
    FILE    *file;
    
	if (ac == 2)
    {
		file = fopen(av[1], "r");
		if (!file)
			return (1);
		if (get_info(&info, file) == 1)
			return (1);
		if (execute(&info, file) == 1)
			return (1);
    }
}