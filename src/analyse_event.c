/*
** EPITECH PROJECT, 2022
** 3d_projection
** File description:
** analyse_event.c
*/
#include "my.h"

void analyse_events(sfRenderWindow *window, sfEvent event, vect4f *angle)
{
    if (event.type == sfEvtClosed)
        sfRenderWindow_close(window);
    if (event.type == sfEvtKeyPressed && event.key.code == sfKeyEscape)
        sfRenderWindow_close(window);
    if (event.type == sfEvtKeyPressed && event.key.code == sfKeyRight)
        angle->y += -0.01;
    if (event.type == sfEvtKeyPressed && event.key.code == sfKeyLeft)
        angle->y += 0.01;
    if (event.type == sfEvtKeyPressed && event.key.code == sfKeyUp)
        angle->x += 0.01;
    if (event.type == sfEvtKeyPressed && event.key.code == sfKeyDown)
        angle->x += -0.01;
    if (event.type == sfEvtKeyPressed && event.key.code == sfKeyX)
        angle->z += 0.01;
    if (event.type == sfEvtKeyPressed && event.key.code == sfKeyC)
        angle->z += -0.01;
    if (event.type == sfEvtKeyPressed && event.key.code == sfKeySpace) {
        angle->y = 0;
        angle->x = 0;
        angle->z = 0;
    }

}