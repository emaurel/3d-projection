/*
** EPITECH PROJECT, 2022
** 3d_projection
** File description:
** create_vertex.c
*/
#include "my.h"

sfVertex *create_vertex(float x, float y)
{
    sfVertex *line = malloc(sizeof(sfVertex));
    sfVector2f pos = {x, y};
    line->color = sfBlack;
    line->position = pos;
    return line;
}