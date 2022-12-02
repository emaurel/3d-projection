/*
** EPITECH PROJECT, 2022
** 3d-projection
** File description:
** sphere.c
*/
#include "my.h"

shape *create_sphere(int rayon, int res, int res3d)
{

    int nb_cercle = res3d;
    shape *sphere = malloc(sizeof(shape));
    sfVector3f **coords = malloc(sizeof(sfVector3f *) * nb_cercle * res);
    int **edge_table = malloc(sizeof(int *) * nb_cercle * res);
    for (int i = 0; i < nb_cercle * res; i++)
        edge_table[i] = malloc(sizeof(int) * 3);

    sfVector2f *pos;
    int rayon_c;
    int p;
    for (int i = 0; i < nb_cercle; i++) {
        rayon_c = rayon * sin(2* (i * pi / nb_cercle));
        for (int k = 0; k < res; k++) {
            p = k + i * res;
            pos = racine_nieme(k, res);
            coords[p] = set_3d_vect(rayon_c * pos->x, rayon_c * pos->y, rayon * cos(2* (i * pi / nb_cercle)));
            edge_table[p][0] = mod(mod(k - 1, res) + i * res, res * nb_cercle);
            edge_table[p][1] = mod(mod(k + 1, res) + i * res, res * nb_cercle);
            edge_table[p][2] = mod(p + res, res * nb_cercle);
        }
    }
    sphere->edge_table = edge_table;
    sphere->points_3d = coords;
    return sphere;
}