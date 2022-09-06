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

// t_bool      hit_sphere(t_sphere *sp, t_ray *ray, t_hit_record *rec)
t_bool      hit_sphere(t_object *world, t_ray *ray, t_hit_record *rec)
{
    t_vec3  oc; //방향벡터로 나타낸 구의 중심.
    //a, b, c는 각각 t에 관한 2차 방정식의 계수
    double  a;
    double  half_b;
    double  c;
    double  discriminant; //판별식
    double  sqrtd;
    double  root;
    t_sphere *sp;

    sp = world->element;
    
    oc = vminus(ray->orig, sp->center); //center
    a = vlength2(ray->dir);
    half_b = vdot(oc, ray->dir);
    c = vlength2(oc) - sp->radius2;//radius2
    discriminant = half_b * half_b - a * c;

    if (discriminant < 0)
        return (FALSE);
    sqrtd = sqrt(discriminant);
    //두 실근(t) 중 tmin과 tmax 사이에 있는 근이 있는지 체크, 작은 근부터 체크.
    root = (-half_b - sqrtd) / a;
    if (root < rec->tmin || rec->tmax < root)
    {
        root = (-half_b + sqrtd) / a;
        if (root < rec->tmin || rec->tmax < root)
            return (FALSE);
    }
    rec->t = root;
    rec->p = ray_at(ray, root);
    rec->normal = vdivide(vminus(rec->p, sp->center), sp->radius); // 정규화된 법선 벡터.
    set_face_normal(ray, rec); // rec의 법선벡터와 광선의 방향벡터를 비교해서 앞면인지 뒷면인지 t_bool 값으로 저장.
    rec->albedo = world->albedo;
    return (TRUE);
  /* * * * 수정 끝 * * * */
}

// t_bool      hit_sphere(t_object *world, t_ray *ray, t_hit_record *rec)
// {
    // t_vec3  oc; //방향벡터로 나타낸 구의 중심.
    // //a, b, c는 각각 t에 관한 2차 방정식의 계수
    // double  a;
    // // double  b;
    // double half_b;
    // double  c;
    // double  discriminant; //판별식
    // double  sqrtd;
    // double  root;

    // oc = vminus(ray->orig, sp->center);
    // /*a = vdot(ray->dir, ray->dir);
    // b = 2.0 * vdot(oc, ray->dir);
    // c = vdot(oc, oc) - sp->radius2;
    // // discriminant 는 판별식
    // discriminant = b * b - 4 * a * c;

    // // 판별식이 0보다 크다면 광선이 구를 hit한 것!
    // if (discriminant < 0)≠≠ // 판별식이 0보다 작을 때 : 실근 없을 때,
    //     return (-1.0);
    // else
    //     return ((-b - sqrt(discriminant)) / (2.0 * a)); // 두 근 중 작은 근
    // */
    // a = vlength2(ray->dir);
    // half_b = vdot(oc, ray->dir);
    // c = vlength2(oc) - sp->radius2;
    // discriminant = half_b * half_b - a * c;

    // if (discriminant < 0)
    //     return (FALSE);
    // sqrtd = sqrt(discriminant);
    // //두 실근(t) 중 tmin과 tmax 사이에 있는 근이 있는지 체크, 작은 근부터 체크.
    // root = (-half_b - sqrtd) / a;
    // if (root < rec->tmin || rec->tmax < root)
    // {
    //     root = (-half_b + sqrtd) / a;
    //     if (root < rec->tmin || rec->tmax < root)
    //         return (FALSE);
    // }
    // rec->t = root;
    // rec->p = ray_at(ray, root);
    // rec->normal = vdivide(vminus(rec->p, sp->center), sp->radius); // 정규화된 법선 벡터.
    // set_face_normal(ray, rec); // rec의 법선벡터와 광선의 방향벡터를 비교해서 앞면인지 뒷면인지 t_bool 값으로 저장.
    // return (TRUE);
    // return (discriminant > 0);
// }

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
