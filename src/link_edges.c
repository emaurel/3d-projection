/*
** EPITECH PROJECT, 2022
** 3d_projection
** File description:
** link_edges.c
*/
#include "my.h"

sfVertexArray *link_edges(sfVector2f **point_list, int **edge_table, int list_size)
{
    sfVertexArray *array = sfVertexArray_create();
    sfVertexArray_setPrimitiveType(array, sfLines);
    for (int i = 0; i < list_size; i++) {
        for (int j = 0; j < 3; j++) {
            if(j == 0) {
            }
            sfVertexArray_append(array, *create_vertex(point_list[i]->x, point_list[i]->y));
            sfVertexArray_append(array, *create_vertex(point_list[edge_table[i][j]]->x, point_list[edge_table[i][j]]->y));
            sfVertexArray_append(array, *create_vertex(point_list[i]->x, point_list[i]->y));
        }
    }
    return array;
}