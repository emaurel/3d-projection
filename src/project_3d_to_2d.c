/*
** EPITECH PROJECT, 2022
** 3d_projection
** File description:
** project_3d_to_2d.c
*/
#include "my.h"

sfVector2f **project3d_to_2d(sfVector3f **pointlist, int list_size, sfVector3f cam)
{
    sfVector2f **list_res = malloc(sizeof(sfVector2f *) * list_size);
    float focal_length = cam.z;
    for (int i = 0; i < list_size; i++) {
        list_res[i] = malloc(sizeof(sfVector2f));
        list_res[i]->x = (focal_length * pointlist[i]->x) / (focal_length + pointlist[i]->z) - cam.x;
        list_res[i]->y = (focal_length * pointlist[i]->y) / (focal_length + pointlist[i]->z) - cam.y;
    }
    return list_res;
}