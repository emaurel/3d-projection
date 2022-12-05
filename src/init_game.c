/*
** EPITECH PROJECT, 2022
** 3d_projection
** File description:
** init_game.c
*/

#include "my.h"



game *init_game(int nb_shape)
{
    game *res = malloc(sizeof(game));
    sfVector3f *cam = malloc(sizeof(sfVector3f));
    vect4f *cam4d = malloc(sizeof(vect4f));
    cam->x = -300;
    cam->y = -300;
    cam->z = 1000;

    cam4d->x = 0;
    cam4d->y = 0;
    cam4d->z = -10;
    cam4d->w = 200;
    sfVector3f angles = {0, 0, 0};
    vect4f angles_4d = {0, 0, 0, 0.01};
    res->button_list = malloc(sizeof(button *) * nb_shape);
    res->object_list = malloc(sizeof(object_3d *) * nb_shape);
    res->cam_3d = cam;
    res->cam_4d = cam4d;
    res->angles_3d = malloc(sizeof(sfVector3f));
    res->angles_4d = malloc(sizeof(vect4f));
    res->nb_shape = 0;

    res->button_list[0] = create_button("cube", 0, 0);
    res->button_list[1] = create_button("pyramide", 0, 40);
    res->button_list[2] = create_button("sphere", 0, 80);


    return res;
}