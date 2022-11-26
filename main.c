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
    line_t *line = init_line(400, 300, 400, 0);
    shape *cube_f = cube(100);
    shape *pyramid_f = pyramid(100);
    shape_4d *tesseract_f = tesseract(100);
    sfVector3f cam = {-300, -300, 200};
    vect4f cam4d = {0, 0, -10, 200};
    sfVector3f **projection3d_tesseract = project4d_to_3d(tesseract_f->points_4d, 16, cam4d);
    sfVector2f **projection_tesseract = project3d_to_2d(projection3d_tesseract, 16, cam);
    sfVertexArray *array_tesseract = link_edges(projection_tesseract, tesseract_f->edge_table, 16);
    sfVector2f **projection_cube = project3d_to_2d(cube_f->points_3d, 8, cam);
    sfVertexArray *array_cube = link_edges(projection_cube, cube_f->edge_table, 8);
    sfVector2f **projection_pyra = project3d_to_2d(cube_f->points_3d, 5, cam);
    sfVertexArray *array_pyra = link_edges(projection_cube, cube_f->edge_table, 5);
    sfVector3f angles = {0.01, 0, 0};
    vect4f angles_4d = {0.01, 0.01, 0.01, 0.01};
    sfClock *clock = sfClock_create();
    sfTime time;

    float seconds;
    //offset_lines(cube_l, 100, 100);
    window = sfRenderWindow_create(mode, "3d_projection", sfResize | sfClose, NULL);
    while (sfRenderWindow_isOpen(window)) {
        time = sfClock_getElapsedTime(clock);
        seconds = time.microseconds / 1000000.0;

        while (sfRenderWindow_pollEvent(window, &event))
            analyse_events(window, event, &angles_4d);
        if (seconds > 0.01) {
            rotate_4d(tesseract_f, &angles_4d, 16);
            change_cam_4d(projection_tesseract, projection3d_tesseract, tesseract_f->points_4d, cam4d, cam, 16);
            change_edges(array_tesseract, projection_tesseract, tesseract_f->edge_table, 16);

            /* rotate(pyramid_f, &angles, 5);
            change_cam(projection_pyra, pyramid_f->points_3d, cam, 5);
            change_edges(array_pyra, projection_pyra, pyramid_f->edge_table, 5);
            rotate(cube_f, &angles, 8);
            change_cam(projection_cube, cube_f->points_3d, cam, 8);
            change_edges(array_cube, projection_cube, cube_f->edge_table, 8); */
            sfClock_restart(clock);
        }
        sfRenderWindow_clear(window, sfWhite);
        //sfRenderWindow_drawVertexArray(window, array_pyra, NULL);
        //sfRenderWindow_drawVertexArray(window, array_cube, NULL);
        sfRenderWindow_drawVertexArray(window, array_tesseract, NULL);
        //draw_2dshape(cube_l, window);
        //draw_points(projection, 8, window);
        //draw_line(line, window);
        sfRenderWindow_display(window);
    }
    sfRenderWindow_destroy(window);
}