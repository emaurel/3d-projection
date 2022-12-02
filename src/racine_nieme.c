/*
** EPITECH PROJECT, 2022
** 3d-projection
** File description:
** racine_nieme.c
*/
#include "my.h"

sfVector2f *racine_nieme(int k, int n)
{
    sfVector2f *res = malloc(sizeof(sfVector2f));
    res->x = cos((2 * k * pi) / n);
    res->y = sin((2 * k * pi) / n);
    return res;
}