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

t_bool      hit_sphere(t_sphere *sp, t_ray *ray, t_hit_record *rec)
{
    t_vec3  oc; //방향벡터로 나타낸 구의 중심.
    //a, b, c는 각각 t에 관한 2차 방정식의 계수
    double  a;
    double  half_b;
    double  c;
    double  discriminant; //판별식
    double  sqrtd;
    double  root;
    
    oc = vminus(ray->orig, sp->center);
    a = vlength2(ray->dir);
    half_b = vdot(oc, ray->dir);
    c = vlength2(oc) - sp->radius2;
    discriminant = half_b * half_b - a * c;

    //실근이 존재하지 않으면 obj와 닿지 않는다.
    if (discriminant < 0)
        return (FALSE);
    sqrtd = sqrt(discriminant);
    //두 실근(t) 중 tmin과 tmax 사이에 있는 근이 있는지 체크, 작은 근(root)부터 체크.
    root = (-half_b - sqrtd) / a;
    //  root < 0 || root > t_max -> 카메라가 물체의 내부에 존재하는 경우가 고려되어야함.
    if (root < rec->tmin || rec->tmax < root)
    {
        // 새로운 root (큰 근)
        root = (-half_b + sqrtd) / a;
        // root < 0 || root > t_max 인 경우, 큰 근의 경우에도 물체에 닿지 않았다. 
        if (root < rec->tmin || rec->tmax < root)
            return (FALSE);
    }
    rec->t = root;
    rec->p = ray_at(ray, root);
    rec->normal = vdivide(vminus(rec->p, sp->center), sp->radius); // 정규화된 법선 벡터.
    set_face_normal(ray, rec); // rec의 법선벡터와 광선의 방향벡터를 비교해서 앞면인지 뒷면인지 t_bool 값으로 저장.
    return (TRUE);
}

