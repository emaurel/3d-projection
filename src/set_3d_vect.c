/*
** EPITECH PROJECT, 2022
** 3d_projection
** File description:
** set_3d_vect.c
*/
#include "my.h"

sfVector3f *set_3d_vect(float x, float y, float z)
{
    sfVector3f *res = malloc(sizeof(sfVector3f));
    res->x = x;
    res->y = y;
    res->z = z;
    return res;
}

vect4f *set_4d_vect(float x, float y, float z, float w)
{
    vect4f *res = malloc(sizeof(vect4f));
    res->x = x;
    res->y = y;
    res->z = z;
    res->w = w;
    return res;
}