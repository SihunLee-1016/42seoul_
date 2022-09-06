#include "../../include/trace.h"
#include "../../include/structures.h"

//ray 생성자(정규화 된 ray)
t_ray       ray(t_point3 orig, t_vec3 dir)
{
    t_ray ray;

    ray.orig = orig;
    ray.dir = vunit(dir);
    return (ray);
}

//ray origin point 부터 방향벡터 ray dir * t 만큼 떨어진 점.
t_point3    ray_at(t_ray *ray, double t)
{
    t_point3 at;

    at = vplus(ray->orig, vmult(ray->dir, t));
    return (at);
}

t_ray       ray_primary(t_camera *cam, double u, double v)
{
    t_ray   ray;

    ray.orig = cam->orig;
    // left_bottom + u * horizontal + v * vertical - origin 의 단위 벡터.
    ray.dir = vunit(vminus(vplus(vplus(cam->left_bottom, vmult(cam->horizontal, u)), vmult(cam->vertical, v)), cam->orig));
    return (ray);
}

//광선이 최종적으로 얻게된 픽셀의 색상 값을 리턴.
t_color3    ray_color(t_ray *ray, t_object *world)
{
    double  t;
    t_vec3  n;
    t_hit_record    rec;

    rec.tmin = 0;
    rec.tmax = INFINITY;

    // t = hit_sphere(sphere, ray, &rec);
    // if (t > 0.0)
    // {
    //     //정규화 된 구 표면에서의 법선
    //     n = vunit(vminus(ray_at(ray, t), sphere->center));
    //     return (vmult(color3(n.x + 1, n.y + 1, n.z + 1), 0.5));
    // }
    if (hit(world, ray, &rec))
        return (vmult(vplus(rec.normal, color3(1, 1, 1)), 0.5));

    // if (hit_sphere(sphere, ray))
    //     return (color3(1, 0, 0));
    else
    {
        //ray의 방향벡터의 y 값을 기준으로 그라데이션을 주기 위한 계수.
        t = 0.5 * (ray->dir.y + 1.0);
        // (1-t) * 흰색 + t * 하늘색
        return (vplus(vmult(color3(1, 1, 1), 1.0 - t), vmult(color3(0.5, 0.7, 1.0),     t)));
    }
}

t_bool      hit(t_object *world, t_ray *ray, t_hit_record *rec)
{
    t_bool          hit_anything;
    t_hit_record    temp_rec;

    temp_rec = *rec; // temp_rec의 tmin, tmax 값 초기화를 위해.
    hit_anything = FALSE;
    while(world)
    {
        if (hit_obj(world, ray, &temp_rec))
        {
            hit_anything = TRUE;
            temp_rec.tmax = temp_rec.t;
            *rec = temp_rec;
        }
        world = world->next;
    }
    return (hit_anything);
}

// hit_obj는 오브젝트 타입에 맞는 hit함수로 연결해주는 관문
t_bool      hit_obj(t_object *world, t_ray *ray, t_hit_record *rec)
{
    t_bool  hit_result;

    hit_result = FALSE;
    if (world->type == SP)
        hit_result = hit_sphere(world, ray, rec); //hit_sphere의 첫번째 인자도 t_sphere *에서 t_object *로 수정해주자.
    return (hit_result);
}
