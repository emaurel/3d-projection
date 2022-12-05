/*
** EPITECH PROJECT, 2022
** 3d_projection
** File description:
** chcek_click.c
*/

#include "my.h"


int is_mouse_on(sfVector2i *mouse_pos, button *bouton)
{
    return mouse_pos->x >= bouton->pos->x  && mouse_pos->x <= bouton->pos->x + 100 && mouse_pos->y >= bouton->pos->y && mouse_pos->y <= bouton->pos->y + 30 ;
}


void check_click(game *jeu, sfRenderWindow *window)
{
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(window);
    for (int i = 0; i < 3; i++) {
        if (is_mouse_on(&mouse_pos, jeu->button_list[i])) {
            if (jeu->button_list[i]->clicked == 0) {
                jeu->button_list[i]->shape_nb = jeu->nb_shape;
                jeu->object_list[jeu->button_list[i]->shape_nb] = create_3d(sfText_getString(jeu->button_list[i]->text), 100, 30, jeu->cam_3d);
                jeu->button_list[i]->clicked = 1;
                jeu->nb_shape++;

            }
            else {
                jeu->nb_shape--;
                destroy_3d(jeu->object_list[jeu->button_list[i]->shape_nb], jeu->object_list[jeu->button_list[i]->shape_nb]->nb_points);
                jeu->button_list[i]->clicked = 0;
                jeu->button_list[i]->shape_nb = -1;
            }
        }
    }
}