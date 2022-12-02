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

shape_4d *create_hypersphere(int rayon, int res, int res3d, int res4d)
{

    int nb_cercle = res3d;
    int nb_sphere = res4d;
    shape_4d *sphere = malloc(sizeof(shape_4d));
    vect4f **coords = malloc(sizeof(vect4f *) * nb_cercle * res * nb_sphere);
    int **edge_table = malloc(sizeof(int *) * nb_cercle * res * nb_sphere);
    for (int i = 0; i < nb_cercle * res * nb_sphere; i++)
        edge_table[i] = malloc(sizeof(int) * 4);

    sfVector2f *pos;
    int rayon_c;
    int rayon_s;
    int p = -1;
    for (int j = 0; j < nb_sphere; j++) {
        rayon_s = rayon * sin(2* (j * pi / nb_sphere));
        for (int i = 0; i < nb_cercle; i++) {
            rayon_c = rayon_s * sin(2* (i * pi / nb_cercle));
            for (int k = 0; k < res; k++) {
                p++;
                pos = racine_nieme(k, res);
                coords[p] = set_4d_vect(rayon_c * pos->x, rayon_c * pos->y, rayon_s * cos(2* (i * pi / nb_cercle)), rayon * cos(2* (j * pi / nb_sphere)));
                printf("p : %i\n", p);
                edge_table[p][0] = mod(mod(k - 1, res) + i * res, res * nb_cercle * nb_sphere);
                edge_table[p][1] = mod(mod(k + 1, res) + i * res, res * nb_cercle * nb_sphere);
                edge_table[p][2] = mod(p + res, res * nb_cercle);
                edge_table[p][3] = mod(p + res + nb_cercle * res, res * nb_cercle * nb_sphere);
            }
        }
    }
    sphere->edge_table = edge_table;
    sphere->points_4d = coords;
    printf("fin\n");
    return sphere;
}