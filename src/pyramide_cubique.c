/*
** EPITECH PROJECT, 2022
** 3d-projection
** File description:
** pyramide_cubique.c
*/
#include "my.h"

shape_4d *pyramide_cubique(float size)
{
    shape_4d *cube_res = malloc(sizeof(shape));
    vect4f **res = malloc(sizeof(sfVector3f *) * 9);
    int x = -size/2;
    int y = -size/2;
    int z = 0;
    int w = 0;
    res[0] = set_4d_vect(x, y, -z, w);
    res[1] = set_4d_vect(size + x, y, -z, w);
    res[2] = set_4d_vect(size + x, size + y, -z, w);
    res[3] = set_4d_vect(x, size + y, -z, w);
    res[4] = set_4d_vect(x, size + y, -(size + z), w);
    res[5] = set_4d_vect(size + x, size + y, -(size + z), w);
    res[6] = set_4d_vect(size + x, y, -(size + z), w);
    res[7] = set_4d_vect(x, y, -(size + z), w);
    res[8] = set_4d_vect(y + size/2, x + size/2, z + size/2 , -(size + w));
    int **edge_table = malloc(sizeof(int *) * 9);
    edge_table[0] = associate_edges(0, 3, 7, 8);
    edge_table[1] = associate_edges(0, 2, 1, 8);
    edge_table[2] = associate_edges(2, 3, 2, 8);
    edge_table[3] = associate_edges(3, 4, 3, 8);
    edge_table[4] = associate_edges(4, 4, 7, 8);
    edge_table[5] = associate_edges(4, 6, 2, 8);
    edge_table[6] = associate_edges(6, 7, 1, 8);
    edge_table[7] = associate_edges(7, 7, 7, 8);
    edge_table[8] = associate_edges(8, 8, 8, 8);

    cube_res->points_4d = res;
    cube_res->edge_table = edge_table;
    return cube_res;
}