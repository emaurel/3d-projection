/*
** EPITECH PROJECT, 2022
** 3d-projection
** File description:
** change_color.c
*/
#include "my.h"

void change_color(sfVertexArray *array, sfColor color)
{
    int len = sfVertexArray_getVertexCount(array);
    sfVertex *vx;
    for (int i = 0; i < len; i++) {
        sfVertexArray_getVertex(array, i)->color = sfWhite;
        if (i % 2)
            sfVertexArray_getVertex(array, i)->color = sfBlack;

    }
}