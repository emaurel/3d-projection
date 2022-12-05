/*
** EPITECH PROJECT, 2022
** 3d_projection
** File description:
** strlen.c
*/

#include "my.h"

int my_strlen(char *s)
{
    int i = 0;
    while(s[i])
        i++;
    return i;
}