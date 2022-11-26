/*
** EPITECH PROJECT, 2022
** 3d_projection
** File description:
** rotate_cube.c
*/

#include "my.h"

void rotate(shape *cube, sfVector3f *angle, int nb_edges)
{
    float a;
    float b;
    float c;
    float angle_x = angle->x;
    float angle_y = angle->y;
    float angle_z = angle->z;
    if (angle_x != 0) {
        for (int i = 0; i < nb_edges; i++) {
            a = cube->points_3d[i]->x;
            b = cube->points_3d[i]->y;
            c = cube->points_3d[i]->z;
            cube->points_3d[i]->y = b * cos(angle_x) - c * sin(angle_x);
            cube->points_3d[i]->z = b * sin(angle_x) + c * cos(angle_x);
        }
    }
    if (angle_y != 0) {
        for (int i = 0; i < nb_edges; i++) {
            a = cube->points_3d[i]->x;
            b = cube->points_3d[i]->y;
            c = cube->points_3d[i]->z;
            cube->points_3d[i]->x = a * cos(angle_y) + c * sin(angle_y);
            cube->points_3d[i]->z = -a * sin(angle_y) + c * cos(angle_y);
        }
    }
    if (angle_z != 0) {
        for (int i = 0; i < nb_edges; i++) {
            a = cube->points_3d[i]->x;
            b = cube->points_3d[i]->y;
            c = cube->points_3d[i]->z;
            cube->points_3d[i]->x = a * cos(angle_z) - b * sin(angle_z);
            cube->points_3d[i]->y = a * sin(angle_z) + b * cos(angle_z);
        }
    }
}