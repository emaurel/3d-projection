/*
** EPITECH PROJECT, 2022
** 3d_projection
** File description:
** tesseract.c
*/
#include "my.h"

shape_4d *tesseract(float size)
{
    shape_4d *tesseract_res = malloc(sizeof(shape));
    vect4f **res = malloc(sizeof(sfVector2f *) * 16);
    int x = -size/2;
    int y = -size/2;
    int z = -size/2;
    int w = 0;
    res[0] = set_4d_vect(x, y, -z, w);
    res[1] = set_4d_vect(size + x, y, -z, w);
    res[2] = set_4d_vect(size + x, size + y, -z, w);
    res[3] = set_4d_vect(x, size + y, -z, w);
    res[4] = set_4d_vect(x, size + y, -(size + z), w);
    res[5] = set_4d_vect(size + x, size + y, -(size + z), w);
    res[6] = set_4d_vect(size + x, y, -(size + z), w);
    res[7] = set_4d_vect(x, y, -(size + z), w);

    res[15] = set_4d_vect(x, y, -z, w + size);
    res[14] = set_4d_vect(size + x, y, -z, w + size);
    res[13] = set_4d_vect(size + x, size + y, -z, w + size);
    res[12] = set_4d_vect(x, size + y, -z, w + size);
    res[11] = set_4d_vect(x, size + y, -(size + z), w + size);
    res[10] = set_4d_vect(size + x, size + y, -(size + z), w + size);
    res[9] = set_4d_vect(size + x, y, -(size + z), w + size);
    res[8] = set_4d_vect(x, y, -(size + z), w + size);

    int **edge_table = malloc(sizeof(int *) * 16);

    edge_table[0] = associate_edges(15, 3, 7, 0);
    edge_table[1] = associate_edges(0, 2, 14, 0);
    edge_table[2] = associate_edges(5, 3, 13, 0);
    edge_table[3] = associate_edges(3, 4, 12, 0);
    edge_table[4] = associate_edges(4, 11, 7, 0);
    edge_table[5] = associate_edges(4, 6, 10, 0);
    edge_table[6] = associate_edges(9, 7, 1, 0);
    edge_table[7] = associate_edges(7, 7, 8, 0);

    edge_table[8] = associate_edges(8, 11, 15, 0);
    edge_table[9] = associate_edges(8, 10, 9, 0);
    edge_table[10] = associate_edges(10, 11, 10, 0);
    edge_table[11] = associate_edges(11, 12, 11, 0);
    edge_table[12] = associate_edges(12, 12, 15, 0);
    edge_table[13] = associate_edges(12, 14, 10, 0);
    edge_table[14] = associate_edges(14, 15, 9, 0);
    edge_table[15] = associate_edges(15, 15, 15, 0);


    tesseract_res->points_4d = res;
    tesseract_res->edge_table = edge_table;
    return tesseract_res;
}