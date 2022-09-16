#include <stdio.h>
#include "include/trace.h"
#include "include/structures.h"
#include "include/scene.h"
#include "include/utils.h"
#include "include/print.h"

t_scene *scene_init(void)
{
    t_scene     *scene;
    t_object    *world;
    t_object    *lights;
    double      ka; // 8.4 에서 설명

    if(!(scene = (t_scene *)malloc(sizeof(t_scene))))
        return (NULL);
    scene->canvas = canvas(1000, 800);
    scene->camera = camera(&scene->canvas, point3(0, 0, 0));
    // world = object(SP, sphere(point3(-2, 0, -5), 1.5), color3(0.5, 0, 0)); // 적색 구

    world = object(PL, plane(point3(-1, -1, -1), vec3(0, 2, 0)), color3(0.2, 0.5, 0.3));

    oadd (&world, object(PL, plane(point3(0, 0, 0), vec3(1, 0, 0)), color3(0.2, 0.3, 0.3)));

    oadd(&world, object(SP, sphere(point3(-2, 0, -3), 1), color3(0.5, 0.5, 0))); // 노랑색 구
    oadd(&world, object(SP, sphere(point3(0, 2, -4), 1), color3(0.5, 0, 0))); // 노랑색 구
    oadd(&world, object(SP, sphere(point3(2, 0, -4), 1), color3(0, 0.5, 0))); // 노랑색 구
    // oadd(&world, object(SP, sphere(point3(2, 0, -5), 1.5), color3(0, 0.5, 0))); // 녹색 구
    // oadd(&world, object(SP, sphere(point3(0, 0, -4), 0.5), color3(0, 1, 1))); // 옥색 구
    // oadd(&world, object(SP, sphere(point3(0, 2, -5), 1), color3(0, 1, 1))); // 옥색 구
    // oadd (&world, object(PL, plane(point3(0, 3, 5), vec3(3, 1, 0)), color3(20, 0, 0)));
    // oadd (&world, object(PL, plane(point3(0, 2, 0), vec3(1, 6,0)), color3(0, 20, 0)));
    // oadd (&world, object(PL, plane(point3(0, -1, 0), vec3(1, 0.6, -1)), color3(20, 0, 0)));
    // oadd (&world, object(PL, plane(point3(0, 2, 5), vec3(-1, 1,0)), color3(0, 0, 20)));

    scene->world = world;
    lights = object(LIGHT_POINT, light_point(point3(0, 5, 0), color3(1, 1, 1), 0.5), color3(0, 0, 0)); // 더미 albedo
    scene->light = lights;
    ka = 0.1; // 8.4 에서 설명
    scene->ambient = vmult(color3(1,1,1), ka); // 8.4 에서 설명
    return (scene);
}

int main(void)
{
    int         i;
    int         j;
    double      u;
    double      v;

    t_color3    pixel_color;
    t_canvas    canv;
    t_camera    cam;
    t_ray       ray;
    t_sphere    sp;
    t_object    *world;
    t_scene     *scene;

    scene = scene_init();
    printf("P3\n%d %d\n255\n", scene->canvas.width, scene->canvas.height);
    j = scene->canvas.height - 1;
    while (j >= 0)
    {
        i = 0;
        while (i < scene->canvas.width)
        {
            u = (double)i / (scene->canvas.width - 1);
            v = (double)j / (scene->canvas.height - 1);
            scene->ray = ray_primary(&scene->camera, u, v);
            pixel_color = ray_color(scene);
            write_color(pixel_color);
            ++i;
        }
        --j;
    }
}