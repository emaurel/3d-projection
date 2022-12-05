/*
** EPITECH PROJECT, 2022
** 3d_projection
** File description:
** create_button.c
*/

#include "my.h"

button *create_button(char *text, int x, int y)
{
    button *res = malloc(sizeof(button));
    sfVector2f pos = {x, y};
    sfVector2f *position = malloc(sizeof(sfVector2f));
    position->x = x;
    position->y = y;
    sfVector2f textpos = {x, y - 5};
    sfVector2f size = {100, 30};
    res->clicked = 0;
    res->text = sfText_create();
    res->rect = sfRectangleShape_create();
    res->pos = position;
    res->shape_nb = -1;
    sfFont *font = sfFont_createFromFile("font.ttf");
    sfRectangleShape_setFillColor(res->rect, sfRed);
    sfRectangleShape_setPosition(res->rect, pos);
    sfRectangleShape_setSize(res->rect, size);
    sfText_setColor(res->text, sfBlack);
    sfText_setPosition(res->text, textpos);
    sfText_setString(res->text, text);
    sfText_setFont(res->text, font);
    return res;
}