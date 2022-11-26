/*
** EPITECH PROJECT, 2022
** 3d_projection
** File description:
** draw_circle.c
*/
#include "my.h"

void draw_points(sfVector2f **point_list, int size, sfRenderWindow *window)
{
    sfCircleShape *point = sfCircleShape_create();
    sfCircleShape_setFillColor(point, sfRed);
    sfCircleShape_setRadius(point, 2);
    for (int i = 0; i < size; i++) {
        sfCircleShape_setPosition(point, *point_list[i]);
        sfRenderWindow_drawCircleShape(window, point, NULL);
    }
}