/*
** EPITECH PROJECT, 2022
** 3d_projection
** File description:
** draw_2dshape.c
*/

#include "my.h"

void draw_2dshape(line_t **line_list, sfRenderWindow *window)
{
    for (int i = 0; line_list[i] != NULL; i++) {
        draw_line(line_list[i], window);
    }
}