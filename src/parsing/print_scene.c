#include "mini_rt.h"

void    print_objs(t_oitem *o_lst)
{
    t_oitem     *tmp;
    t_sphere    *sp;
    t_cylinder  *cy;
    t_plane     *pl;

    tmp = o_lst;
    while (tmp)
    {
        if (tmp->obj_type == SPHERE)
        {
            sp = (t_sphere *)tmp->obj_struct;
            printf("sp:\t\npos:\t[%f, %f, %f]\nrad:\t%f\ncolor:\t[%d, %d, %d]\nobj_id:\t%d\n\n",
                    sp->origin.x, sp->origin.y, sp->origin.z,
                    sp->radius,
                    get_red(tmp->material.color), get_green(tmp->material.color), get_blue(tmp->material.color),
                    tmp->obj_id);
        }
        if (tmp->obj_type == CYLINDER)
        {
            cy = (t_cylinder *)tmp->obj_struct;
            printf("cy:\t\npos:\t[%f, %f, %f]\nn:\t[%f, %f, %f]\ndiam:\t%f\nheight:\t%f\ncolor:\t[%d, %d, %d]\nobj_id:\t%d\n\n",
                    cy->origin.x, cy->origin.y, cy->origin.z,
                    cy->nrm_vector.x, cy->nrm_vector.y, cy->nrm_vector.z,
                    cy->diameter, cy->height,
                    get_red(tmp->material.color), get_green(tmp->material.color), get_blue(tmp->material.color),
                    tmp->obj_id);
        }
        if (tmp->obj_type == PLANE)
        {
            pl = (t_plane *)tmp->obj_struct;
            printf("pl:\t\npos:\t[%f, %f, %f]\nn:\t[%f, %f, %f]\ncolor:\t[%d, %d, %d]\nobj_id:\t%d\n\n",
                    pl->origin.x, pl->origin.y, pl->origin.z,
                    pl->nrm_vector.x, pl->nrm_vector.y, pl->nrm_vector.z,
                    get_red(tmp->material.color), get_green(tmp->material.color), get_blue(tmp->material.color),
                    tmp->obj_id);
        }
        tmp = tmp->next;
    }
}

void    print_scene(t_scene *scene)
{
    if (scene->ambient_light)
    {
        printf("A:\t\nratio:\t%f\ncolor:\t[%d, %d, %d]\n\n", 
                scene->ambient_light->ratio, 
                get_red(scene->ambient_light->color), 
                get_green(scene->ambient_light->color), 
                get_blue(scene->ambient_light->color));
    }
    if (scene->camera)
    {
        printf("C:\t\npos:\t[%f, %f, %f]\nn:\t[%f, %f, %f]\nfov:\t%d\n\n",
            scene->camera->position_p.x,
            scene->camera->position_p.y,
            scene->camera->position_p.z,
            scene->camera->orientation_v.x,
            scene->camera->orientation_v.y,
            scene->camera->orientation_v.z,
            scene->camera->fov);
    }
    if (scene->light)
    {
        printf("L:\t\npos:\t[%f, %f, %f]\nratio:\t%f\ncolor:\t[%d, %d, %d]\n\n",
            scene->light->position.x,
            scene->light->position.y,
            scene->light->position.z,
            scene->light->brightness,
            get_red(scene->light->color),
            get_green(scene->light->color),
            get_blue(scene->light->color));
    }
    if (scene->objs_list)
    {
        print_objs(scene->objs_list);
    }
}
