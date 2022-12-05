/*
** EPITECH PROJECT, 2022
** 3d_projection
** File description:
** is_str_eq.c
*/

#include "my.h"

int is_str_eq(char *s1, char *s2)
{
    if (my_strlen(s1) != my_strlen(s2))
        return 0;
    for (int i = 0; s1[i]; i++) {
        if (s1[i] != s2[i])
            return 0;
    }
    return 1;
}