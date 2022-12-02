/*
** EPITECH PROJECT, 2022
** 3d-projection
** File description:
** shpere_4d.c
*/

/*
** EPITECH PROJECT, 2022
** 3d-projection
** File description:
** sphere.c
*/
#include "my.h"

shape_4d *create_sphere_4d(int rayon, int res, int res3d)
{

    int nb_cercle = res3d;
    shape_4d *sphere = malloc(sizeof(shape_4d));
    vect4f **coords = malloc(sizeof(vect4f *) * nb_cercle * res);
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
            coords[p] = set_4d_vect(rayon_c * pos->x, rayon_c * pos->y, rayon * cos(2* (i * pi / nb_cercle)), 0);
            edge_table[p][0] = mod(mod(k - 1, res) + i * res, res * nb_cercle);
            edge_table[p][1] = mod(mod(k + 1, res) + i * res, res * nb_cercle);
            edge_table[p][2] = mod(p + res, res * nb_cercle);
        }
    }
    sphere->edge_table = edge_table;
    sphere->points_4d = coords;
    return sphere;
}