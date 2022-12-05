/*
** EPITECH PROJECT, 2022
** 3d_projection
** File description:
** destroy_3d.c
*/

#include "my.h"

void destroy_3d(object_3d *object, int nb_points)
{
    for (int i = 0; i < nb_points; i++) {
        free(object->forme->edge_table[i]);
        free(object->projection[i]);
    }
    free(object->forme->edge_table);
    sfVertexArray_destroy(object->array);
    free(object->projection);
    free(object);
}