/*
** EPITECH PROJECT, 2022
** 3d_projection
** File description:
** pyramid.c
*/
#include "my.h"

shape *pyramid(float size)
{
    shape *pyramid_res = malloc(sizeof(shape));
    sfVector3f **res = malloc(sizeof(sfVector3f *) * 8);
    int x = -size/2;
    int y = -size/2;
    int z = 0;
    res[0] = set_3d_vect(x, y, -z);
    res[1] = set_3d_vect(size + x, y, -z);
    res[2] = set_3d_vect(size + x, size + y, -z);
    res[3] = set_3d_vect(x, size + y, -z);
    res[4] = set_3d_vect(y + size/2, x + size/2, -(size + z));
    int **edge_table = malloc(sizeof(int *) * 8);
    edge_table[0] = associate_edges(4, 1, 3, 0);
    edge_table[1] = associate_edges(4, 2, 1, 1);
    edge_table[2] = associate_edges(4, 3, 2, 2);
    edge_table[3] = associate_edges(4, 3, 3, 3);
    edge_table[4] = associate_edges(4, 4, 4, 4);

    pyramid_res->points_3d = res;
    pyramid_res->edge_table = edge_table;
    return pyramid_res;
}