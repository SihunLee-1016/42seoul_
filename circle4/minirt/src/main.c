#include <stdio.h>
#include "../include/structures.h"
#include "../include/trace.h"
void    write_color(t_color3 pixel_color)
{
    printf("%d %d %d\n", (int)(255.999 * pixel_color.x),
                        (int)(255.999 * pixel_color.y),
                        (int)(255.999 * pixel_color.z));
}


int	main(void)
{
    int     i;
    int     j;
    double  r;
    double  g;
    double  b;
	
	double      u;
    double      v;

    int     canvas_width;
    int     canvas_height;
    t_color3    pixel_color;
    t_canvas    canv;
    t_camera    cam;
    t_ray       ray;


    //캔버스의 가로, 세로 픽셀값
    canvas_width = 256;
    canvas_height = 256;

	canv = canvas(400, 300);
    cam = camera(&canv, point3(0, 0, 0));


    // 랜더링
    // P3 는 색상값이 아스키코드라는 뜻, 그리고 다음 줄은 캔버스의 가로, 세로 픽셀 수, 마지막은 사용할 색상값
    printf("P3\n%d %d\n255\n", canvas_width, canvas_height);
    j = canvas_height - 1;
    while (j >= 0)
    {
        i = 0;
        while (i < canvas_width)
        {
			u = (double)i / (canv.width - 1);
            v = (double)j / (canv.height - 1);
            //ray from camera origin to pixel
            ray = ray_primary(&cam, u, v);
            pixel_color = ray_color(&ray);

		// 	pixel_color.x = (double)i / (canvas_width - 1);
        //     pixel_color.y = (double)j / (canvas_height - 1);
        //     pixel_color.z = 0.25;
            write_color(pixel_color);

            // r = (double)i / (canvas_width - 1);
            // g = (double)j / (canvas_height - 1);
            // b = 0.25;
            // printf("%d %d %d\n", (int)(255.999 * r), (int)(255.999 * g), (int)(255.999 * b));
        ++i;
        }
    --j;
    }
    return (0);
}
