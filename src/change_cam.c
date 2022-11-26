/*
** EPITECH PROJECT, 2022
** 3d_projection
** File description:
** change_cam.c
*/
#include "my.h"

void change_cam(sfVector2f **projection, sfVector3f **pointlist, sfVector3f cam, int list_size)
{
    float focal_length = cam.z;
    for (int i = 0; i < list_size; i++) {
        projection[i]->x = (focal_length * pointlist[i]->x) / (focal_length + pointlist[i]->z) - cam.x;
        projection[i]->y = (focal_length * pointlist[i]->y) / (focal_length + pointlist[i]->z) - cam.y;
    }
}

void change_cam_4d(sfVector2f **projection, sfVector3f **projection_3d, vect4f **pointlist, vect4f cam_4d, sfVector3f cam_3d, int list_size)
{
    float focal_length = cam_4d.w;
    for (int i = 0; i < list_size; i++) {
        projection_3d[i] = malloc(sizeof(sfVector3f));
        projection_3d[i]->x = (focal_length * pointlist[i]->x) / (focal_length + pointlist[i]->w) - cam_4d.x;
        projection_3d[i]->y = (focal_length * pointlist[i]->y) / (focal_length + pointlist[i]->w) - cam_4d.y;
        projection_3d[i]->z = (focal_length * pointlist[i]->z) / (focal_length + pointlist[i]->w) - cam_4d.z;
    }
    change_cam(projection, projection_3d, cam_3d, list_size);
}