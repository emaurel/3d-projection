/*
** EPITECH PROJECT, 2022
** 3d_projection
** File description:
** rotate_4d.c
*/
#include "my.h"

void rotate_4d(shape_4d *cube, vect4f *angle, int nb_edges)
{
    float a;
    float b;
    float c;
    float d;
    float angle_x = angle->x;
    float angle_y = angle->y;
    float angle_z = angle->z;
    float angle_w = angle->w;
    
    if (angle_x != 0) {
        /* if (angle_z != 0) {
            for (int i = 0; i < nb_edges; i++) {
                a = cube->points_4d[i]->x;
                b = cube->points_4d[i]->y;
                c = cube->points_4d[i]->z;
                d = cube->points_4d[i]->w;

                cube->points_4d[i]->y = b * cos(angle_x) - d * sin(angle_x);
                cube->points_4d[i]->w = b * sin(angle_x) + d * cos(angle_x);
            }
        } */
        if (angle_y != 0) {
            for (int i = 0; i < nb_edges; i++) {
                a = cube->points_4d[i]->x;
                b = cube->points_4d[i]->y;
                c = cube->points_4d[i]->z;
                d = cube->points_4d[i]->w;

                cube->points_4d[i]->z = c * cos(angle_y) - d * sin(angle_y);
                cube->points_4d[i]->w = c * sin(angle_y) + d * cos(angle_y);
            }
        }
        if (angle_w != 0) {
            for (int i = 0; i < nb_edges; i++) {
                a = cube->points_4d[i]->x;
                b = cube->points_4d[i]->y;
                c = cube->points_4d[i]->z;
                cube->points_4d[i]->y = b * cos(angle_w) - c * sin(angle_w);
                cube->points_4d[i]->z = b * sin(angle_w) + c * cos(angle_w);
            }
        }
    }

    if (angle_y != 0) {
        if (angle_z != 0) {
            for (int i = 0; i < nb_edges; i++) {
                a = cube->points_4d[i]->x;
                b = cube->points_4d[i]->y;
                c = cube->points_4d[i]->z;
                d = cube->points_4d[i]->w;

                cube->points_4d[i]->x = a * cos(angle_y) - d * sin(angle_y);
                cube->points_4d[i]->w = a * sin(angle_y) + d * cos(angle_y);
            }
        }

        if (angle_w != 0) {
            for (int i = 0; i < nb_edges; i++) {
                a = cube->points_4d[i]->x;
                b = cube->points_4d[i]->y;
                c = cube->points_4d[i]->z;
                cube->points_4d[i]->x = a * cos(angle_w) - c * sin(angle_w);
                cube->points_4d[i]->z = a * sin(angle_w) + c * cos(angle_w);
            }
        }
    }
    if (angle_z != 0) {
        if (angle_w != 0) {
            for (int i = 0; i < nb_edges; i++) {
                a = cube->points_4d[i]->x;
                b = cube->points_4d[i]->y;
                c = cube->points_4d[i]->z;
                cube->points_4d[i]->x = a * cos(angle_w) - b * sin(angle_w);
                cube->points_4d[i]->y = a * sin(angle_w) + b * cos(angle_w);
            }
        }
    }
}