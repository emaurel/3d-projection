/*
** EPITECH PROJECT, 2022
** 3d_projection
** File description:
** change_edges.c
*/
#include "my.h"

void change_edges(sfVertexArray *array, sfVector2f **point_list, int **edge_table, int list_size)
{
    sfVertexArray_clear(array);
    for (int i = 0; i < list_size; i++) {
        for (int j = 0; j < 3; j++) {
            sfVertexArray_append(array, *create_vertex(point_list[i]->x, point_list[i]->y));
            sfVertexArray_append(array, *create_vertex(point_list[edge_table[i][j]]->x, point_list[edge_table[i][j]]->y));
            sfVertexArray_append(array, *create_vertex(point_list[i]->x, point_list[i]->y));
        }
    }
}