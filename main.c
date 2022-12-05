/*
** EPITECH PROJECT, 2022
** 3d_projection
** File description:
** main.c
*/
#include "my.h"

int main(void)
{

    sfVideoMode mode = {800, 600, 32};
    sfRenderWindow *window = NULL;
    sfEvent event;
    int nb_button = 3;
    game *jeu = init_game(nb_button);
 
    sfClock *clock = sfClock_create();
    sfTime time;

/*     int resolution = 30;
    int nb_cercle = 30;
    int nb_sphere = 10;
    shape *cercle = create_circle(100, resolution);
    sfVector2f **projection_cercle = project3d_to_2d(cercle->points_3d, resolution, cam);
    sfVertexArray *array_cercle = link_edges(projection_cercle, cercle->edge_table, resolution);

    shape_4d *sphere_4d = create_sphere_4d(200, resolution, nb_cercle);
    sfVector3f **projection3d_sphere = project4d_to_3d(sphere_4d->points_4d, resolution * nb_cercle, cam4d);
    sfVector2f **projection_sphere_4d = project3d_to_2d(projection3d_sphere, resolution * nb_cercle, cam);
    sfVertexArray *array_sphere_4d = link_edges(projection_sphere_4d, sphere_4d->edge_table, resolution * nb_cercle); */


    /*shape_4d *hypersphere = create_hypersphere(150, resolution, nb_cercle, nb_sphere);
    sfVector3f **projection_3d_hypersphere = project4d_to_3d(hypersphere->points_4d, resolution * nb_cercle * nb_sphere, cam4d);
    sfVector2f **projection_hypersphere = project3d_to_2d(projection_3d_hypersphere, resolution * nb_cercle * nb_sphere, cam);
    sfVertexArray *array_hypersphere = link_edges(projection_hypersphere, hypersphere->edge_table, resolution * nb_cercle * nb_sphere);
    */
    float seconds;
    //offset_lines(cube_l, 100, 100);
    window = sfRenderWindow_create(mode, "3d_projection", sfClose, NULL);
    while (sfRenderWindow_isOpen(window)) {
        time = sfClock_getElapsedTime(clock);
        seconds = time.microseconds / 1000000.0;
        while (sfRenderWindow_pollEvent(window, &event)) {
            analyse_events(window, event, jeu);
        }

        if (seconds > 0.01) {
            /* rotate_4d(tesseract_f, &angles_4d, 16);
            change_cam_4d(projection_tesseract, projection3d_tesseract, tesseract_f->points_4d, cam4d, cam, 16);
            change_edges(array_tesseract, projection_tesseract, tesseract_f->edge_table, 16);
            rotate_4d(pyra_cube, &angles_4d, 9);
            change_cam_4d(projection_pyra_cube, projection3d_pyra_cube, pyra_cube->points_4d, cam4d, cam, 9);
            change_edges(array_pyra_cube, projection_pyra_cube, pyra_cube->edge_table, 9);

            rotate_4d(sphere_4d, &angles_4d, resolution * nb_cercle);
            change_cam_4d(projection_sphere_4d, projection3d_sphere, sphere_4d->points_4d, cam4d, cam, resolution * nb_cercle);
            change_edges(array_sphere_4d, projection_sphere_4d, sphere_4d->edge_table, resolution * nb_cercle); */

            /* rotate_4d(hypersphere, &angles_4d, resolution * nb_cercle * nb_sphere);
            change_cam_4d(projection_hypersphere, projection_3d_hypersphere, hypersphere->points_4d, cam4d, cam, resolution * nb_cercle * nb_sphere);
            change_edges(array_hypersphere, projection_hypersphere, hypersphere->edge_table, resolution * nb_cercle * nb_sphere); */

            /* rotate(pyramid_f, &angles, 5);
            change_cam(projection_pyra, pyramid_f->points_3d, cam, 5);
            change_edges(array_pyra, projection_pyra, pyramid_f->edge_table, 5);
            */
            for (int i = 0; i < jeu->nb_shape; i++) {
                if (jeu->object_list[i] != NULL) {
                rotate(jeu->object_list[i], jeu->angles_3d, jeu->object_list[i]->nb_points, jeu->cam_3d);
                }
            }

            sfClock_restart(clock);
        }
        //change_color(array_cube, sfGreen);
        //change_color(array_pyra, sfRed);
        sfRenderWindow_clear(window, sfWhite);
        for (int i = 0; i < jeu->nb_shape; i++) {
            if (jeu->object_list[i]->nb_points != NULL)
                sfRenderWindow_drawVertexArray(window, jeu->object_list[i]->array, NULL);
        }
        for (int i = 0; i < nb_button; i++)
            draw_button(jeu->button_list[i], window);
               
        //sfRenderWindow_drawVertexArray(window, sphere->array, NULL);
        //sfRenderWindow_drawVertexArray(window, array_tesseract, NULL);
        //sfRenderWindow_drawVertexArray(window, array_pyra_cube, NULL);
        //sfRenderWindow_drawVertexArray(window, array_cercle, NULL);
        //sfRenderWindow_drawVertexArray(window, array_sphere_4d, NULL);
        //sfRenderWindow_drawVertexArray(window, array_hypersphere, NULL);
        //draw_2dshape(cube_l, window);
        //draw_points(projection, 8, window);
        //draw_line(line, window);
        sfRenderWindow_display(window);
    }
    sfRenderWindow_destroy(window);
}