/*
** EPITECH PROJECT, 2022
** 3d_projection
** File description:
** cube.c
*/
#include "my.h"

shape *cube(float size)
{
    shape *cube_res = malloc(sizeof(shape));
    sfVector3f **res = malloc(sizeof(sfVector3f *) * 8);
    int x = -size/2;
    int y = -size/2;
    int z = 0;
    res[0] = set_3d_vect(x, y, -z);
    res[1] = set_3d_vect(size + x, y, -z);
    res[2] = set_3d_vect(size + x, size + y, -z);
    res[3] = set_3d_vect(x, size + y, -z);
    res[4] = set_3d_vect(x, size + y, -(size + z));
    res[5] = set_3d_vect(size + x, size + y, -(size + z));
    res[6] = set_3d_vect(size + x, y, -(size + z));
    res[7] = set_3d_vect(x, y, -(size + z));
    int **edge_table = malloc(sizeof(int *) * 8);
    edge_table[0] = associate_edges(0, 3, 7, 0);
    edge_table[1] = associate_edges(0, 2, 1, 1);
    edge_table[2] = associate_edges(2, 3, 2, 3);
    edge_table[3] = associate_edges(3, 4, 3, 4);
    edge_table[4] = associate_edges(4, 4, 7, 5);
    edge_table[5] = associate_edges(4, 6, 2, 6);
    edge_table[6] = associate_edges(6, 7, 1, 7);
    edge_table[7] = associate_edges(7, 7, 7, 8);

    cube_res->points_3d = res;
    cube_res->edge_table = edge_table;
    return cube_res;
}