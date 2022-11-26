/*
** EPITECH PROJECT, 2022
** 3d_projection
** File description:
** draw_line.c
*/
#include "my.h"

void draw_line(line_t *line, sfRenderWindow *window)
{
    sfRenderWindow_drawRectangleShape(window, line->rect, NULL);
}
