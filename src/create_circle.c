/*
** EPITECH PROJECT, 2022
** 3d-projection
** File description:
** create_circle.c
*/

#include "my.h"


shape *create_circle(float rayon, int resolution)
{
    int nb_points = resolution;
    shape *cercle = malloc(sizeof(shape));
    sfVector3f **res = malloc(sizeof(sfVector3f *) * nb_points);
    int **edge_table = malloc(sizeof(int *) * nb_points);
    sfVector2f *pos;
    for (int k = 0; k < nb_points; k++) {
        edge_table[k] = malloc(sizeof(int) * 3);
        pos = racine_nieme(k, nb_points);
        res[k] = set_3d_vect(rayon * pos->x, rayon * pos->y, 0);
        edge_table[k][0] = mod(k - 1, nb_points);
        edge_table[k][1] = mod(k + 1, nb_points);
        edge_table[k][2] = k;
    }
    cercle->edge_table = edge_table;
    cercle->points_3d = res;
    return cercle;
}