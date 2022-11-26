/*
** EPITECH PROJECT, 2022
** 3d_projection
** File description:
** associate_edge.c
*/

#include "my.h"


int *associate_edges(int a, int b, int c, int d)
{
    int *table = malloc(sizeof(int) * 4);
    table[0] = a;
    table[1] = b;
    table[2] = c;
    table[3] = d;
    return table;
}
