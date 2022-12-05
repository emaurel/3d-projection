/*
** EPITECH PROJECT, 2022
** 3d_projection
** File description:
** create_3d.c
*/

#include "my.h"

object_3d *create_3d(char *object_type, int size, int resolution, sfVector3f *cam)
{
    object_3d *res = malloc(sizeof(object_3d));
    if (is_str_eq(object_type, "cube")) {
        res->forme = cube(size);
        res->projection = project3d_to_2d(res->forme->points_3d, 8, *cam);
        res->array = link_edges(res->projection, res->forme->edge_table, 8);
        res->nb_points = 8;
    }
    if (is_str_eq(object_type, "sphere")) {
        res->forme = create_sphere(size, resolution, resolution);
        res->projection = project3d_to_2d(res->forme->points_3d, resolution * resolution, *cam);
        res->array = link_edges(res->projection, res->forme->edge_table, resolution * resolution);
        res->nb_points = resolution * resolution;
    }
    if (is_str_eq(object_type, "pyramide")) {
        res->forme = pyramid(size);
        res->projection = project3d_to_2d(res->forme->points_3d, 5, *cam);
        res->array = link_edges(res->projection, res->forme->edge_table, 5);
        res->nb_points = 5;
    }
    return res;
}