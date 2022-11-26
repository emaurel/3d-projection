/*
** EPITECH PROJECT, 2022
** 3d_projection
** File description:
** init_line.c
*/
#include "my.h"

line_t *init_line(float x1, float y1, float x2, float y2)
{
    line_t *res = malloc(sizeof(line_t));
    float w = x1 - x2;
    float h = y1 - y2;
    float len = sqrt(pow(w, 2) + pow(h, 2));
    float theta = asin(h/len) * 180 / pi + 90;
    sfVector2f size = {2, len};
    res->angle = theta;
    res->start.x = x1;
    res->start.y = y1;
    res->end.x = x2;
    res->end.y = y2;
    res->rect = sfRectangleShape_create();
    sfRectangleShape_setPosition(res->rect, res->start);
    sfRectangleShape_setSize(res->rect, size);
    sfRectangleShape_setRotation(res->rect, theta);
    sfRectangleShape_setFillColor(res->rect, sfBlack);
    return res;
}