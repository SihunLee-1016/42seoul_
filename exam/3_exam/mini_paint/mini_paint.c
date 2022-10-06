#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct map{
    int     w;
    int     h;
    char    background;
    char    *martix;
}           t_map;


typedef struct rect
{
    float   x;
    float   y;
    float   rect_w;
    float   rect_h;
    char    type;
	char	fill;
}			t_rect;

int	is_in(float x, float y, t_rect *data)
{
	if ((x < data->x) || (data->x + data->rect_w < x) || (y < data->y) || (data->y + data->rect_h < y))
		return (0);
	else if ((x - data->x < 1.00000000) || (data->x + data->rect_w - x) < 1.00000000 || (y - data->y < 1.00000000) || (data->y +data->rect_h - y) < 1.00000000)
		return (1); //경계
	else
		return (2);

}

void	execute(t_rect *data, t_map *map, int x, int y)
{
	int	in;

	in = is_in((float)x, (float)y, data);
	if (in == 0)
		return ;
	else if ((in == 1) || (in == 2 && (data->type == 'R')))
		map->martix[x + y * data->rect_w] = data->fill;
	return ;
}


int	check_data_n_fill(t_rect *data, t_map *map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;

	if (data->rect_h < 1.00000000 || data->rect_w < 1.00000000)
		return (1);
	while (i < data->rect_w)
	{
		j = 0;
		while (j < data->rect_h)
		{
			execute(data, map, i, j);
			j++;
		}
		i++;
	}
}


int main(int argc, char **argv)
{
	FILE	*file;
	t_map	map;
	t_rect	rect;

    if (argc != 2)
        return (1);
	int	sn;
	int	i = 0;

	file = fopen(argv[1], "r");
	sn = fscanf(file, "%d %d %c\n", &map.w, &map.h, &map.background);
	if (map.w < 1 || map.w > 300 || map.h < 1 || map.h > 300)
		return (1);
	map.martix = malloc (sizeof(char*) * (map.w * map.h));
	if (!(map.martix))
		return (0);
	while (i < map.w * map.h)
		map.martix[i] = map.background;
	if (sn == -1)
		return (1);
	sn = fscanf(file, "%c %f %f %f %f %c\n", &rect.type, &rect.x, &rect.y, &rect.rect_w, &rect.rect_h, &rect.fill);
	while (sn == 6)
	{
		check_data_n_fill(&rect, &map);
		sn = fscanf(file, "%c %f %f %f %f %c\n", &rect.type, &rect.x, &rect.y, &rect.rect_w, &rect.rect_h, &rect.fill);
	}
	i = 0;
	if (sn == -1)
	{
		while (i < map.w)
		{
			printf("%.*s\n", map.w, map.martix + i * map.w);
			i++;
		}
	}
	return (0);
}
