/*
** EPITECH PROJECT, 2022
** 3d_projection
** File description:
** analyse_event.c
*/
#include "my.h"

void analyse_events(sfRenderWindow *window, sfEvent event, game *jeu)
{
    if (event.type == sfEvtClosed)
        sfRenderWindow_close(window);
    if (event.type == sfEvtKeyPressed && event.key.code == sfKeyEscape)
        sfRenderWindow_close(window);
    if (event.type == sfEvtKeyPressed && event.key.code == sfKeyRight)
        jeu->angles_3d->y += -0.01;
    if (event.type == sfEvtKeyPressed && event.key.code == sfKeyLeft)
        jeu->angles_3d->y += 0.01;
    if (event.type == sfEvtKeyPressed && event.key.code == sfKeyUp)
        jeu->angles_3d->x += 0.01;
    if (event.type == sfEvtKeyPressed && event.key.code == sfKeyDown)
        jeu->angles_3d->x += -0.01;
    if (event.type == sfEvtKeyPressed && event.key.code == sfKeyX)
        jeu->angles_3d->z += 0.01;
    if (event.type == sfEvtKeyPressed && event.key.code == sfKeyC)
        jeu->angles_3d->z += -0.01;
    if (event.type == sfEvtKeyPressed && event.key.code == sfKeySpace) {
        jeu->angles_3d->y = 0;
        jeu->angles_3d->x = 0;
        jeu->angles_3d->z = 0;
    }
    /* jeu->angles_4d->x = jeu->angles_3d->x;
    jeu->angles_4d->y = jeu->angles_3d->y;
    jeu->angles_4d->z = jeu->angles_3d->z; */
    

    if (event.type == sfEvtMouseButtonPressed) {

        check_click(jeu, window);
}
}