/*
** EPITECH PROJECT, 2022
** 3d_projection
** File description:
** draw_button.c
*/

#include "my.h"

void draw_button(button *bouton, sfRenderWindow *window)
{
    sfRenderWindow_drawRectangleShape(window, bouton->rect, NULL);
    sfRenderWindow_drawText(window, bouton->text, NULL);
}