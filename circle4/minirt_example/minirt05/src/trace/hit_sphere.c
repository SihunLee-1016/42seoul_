#include "../../include/structures.h"
#include "../../include/utils.h"
#include "../../include/trace.h"

void    set_face_normal(t_ray *r, t_hit_record *rec)
{
    // 광선의 방향벡터와 교점의 법선벡터의 내적이 음수이면 광선은 앞면(객체의)에 hit 한 것이다
    rec->front_face = vdot(r->dir, rec->normal) < 0;
    // 광선의 앞면에 hit 면 그대로 아니면 법선을 반대로 뒤집는다. (항상 광선 방향벡터와 법선 벡터를 반대인 상태로 사용하기위해)
    rec->normal = (rec->front_face) ? rec->normal : vmult(rec->normal, -1);
}

double      hit_sphere(t_sphere *sp, t_ray *ray)
{
    t_vec3  oc; //방향벡터로 나타낸 구의 중심.
    //a, b, c는 각각 t에 관한 2차 방정식의 계수
    double  a;
    double  b;
    double  c;
    double  discriminant; //판별식

    oc = vminus(ray->orig, sp->center);
    a = vdot(ray->dir, ray->dir);
    b = 2.0 * vdot(oc, ray->dir);
    c = vdot(oc, oc) - sp->radius2;
    // discriminant 는 판별식
    discriminant = b * b - 4 * a * c;

    // 판별식이 0보다 크다면 광선이 구를 hit한 것!
    // return (discriminant > 0);
    if (discriminant < 0) // 판별식이 0보다 작을 때 : 실근 없을 때,
        return (-1.0);
    else
        return ((-b - sqrt(discriminant)) / (2.0 * a)); // 두 근 중 작은 근
}
