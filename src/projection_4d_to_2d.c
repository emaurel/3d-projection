/*
** EPITECH PROJECT, 2022
** 3d_projection
** File description:
** project_3d_to_2d.c
*/
#include "my.h"

sfVector3f **project4d_to_3d(vect4f **pointlist, int list_size, vect4f cam)
{
    sfVector3f **list_res = malloc(sizeof(sfVector3f *) * list_size);
    float focal_length = cam.w;
    for (int i = 0; i < list_size; i++) {
        list_res[i] = malloc(sizeof(sfVector3f));
        list_res[i]->x = (focal_length * pointlist[i]->x) / (focal_length + pointlist[i]->w) - cam.x;
        list_res[i]->y = (focal_length * pointlist[i]->y) / (focal_length + pointlist[i]->w) - cam.y;
        list_res[i]->z = (focal_length * pointlist[i]->z) / (focal_length + pointlist[i]->w) - cam.z;
    }
    return list_res;
}