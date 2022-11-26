/*
** EPITECH PROJECT, 2022
** 3d_projection
** File description:
** offset_lines.c
*/
#include "my.h"

void offset_lines(line_t **line_list, float x_off, float y_off)
{
    for (int i = 0; line_list[i] != NULL; i++) {
        line_list[i]->start.x += x_off;
        line_list[i]->start.y += y_off;
        line_list[i]->end.x += x_off;
        line_list[i]->end.x += y_off;
        sfRectangleShape_setPosition(line_list[i]->rect, line_list[i]->start);
    }
}