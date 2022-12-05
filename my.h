/*
** EPITECH PROJECT, 2022
** 3d_projection
** File description:
** my.h
*/

#pragma once
#include <SFML/Graphics.h>
#include <SFML/System/Time.h>
#include <SFML/System/Vector3.h>
#include <SFML/System.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <math.h>
#define pi 3.1415

typedef struct line_s {
    sfRectangleShape *rect;
    sfVector2f start;
    sfVector2f end;
    float angle;
} line_t;

typedef struct shape_s {
    sfVector3f **points_3d;
    int **edge_table;
} shape;

typedef struct ed4dvector {
    float x;
    float y;
    float z;
    float w;
} vect4f;

typedef struct shape_4s {
    vect4f **points_4d;
    int **edge_table;
} shape_4d;


typedef struct object_3ds {
    shape *forme;
    sfVector2f **projection;
    sfVertexArray *array;
    int nb_points;
} object_3d;

typedef struct button_s {
    sfText *text;
    sfRectangleShape *rect;
    int clicked;
    sfVector2f *pos;
    int shape_nb;
} button;


typedef struct {
    button **button_list;
    object_3d **object_list;
    sfVector3f *cam_3d;
    vect4f *cam_4d;
    sfVector3f *angles_3d;
    vect4f *angles_4d;
    int nb_shape;
} game;


void analyse_events(sfRenderWindow *window, sfEvent event, game *jeu);
float absol(float b);
line_t *init_line(float x1, float y1, float x2, float y2);
void init_pixels(line_t *line);
void draw_line(line_t *line, sfRenderWindow *window);
sfVector2f **project3d_to_2d(sfVector3f **pointlist, int list_size, sfVector3f cam);
sfVector3f *set_3d_vect(float x, float y, float z);
shape *cube(float size);
void draw_2dshape(line_t **line_list, sfRenderWindow *window);
sfVertexArray *link_edges(sfVector2f **point_list, int **edge_table, int list_size);
void offset_lines(line_t **line_list, float x_off, float y_off);
void draw_points(sfVector2f **point_list, int size, sfRenderWindow *window);
void change_cam(sfVector2f **projection, sfVector3f **pointlist, sfVector3f cam, int list_size);
void change_edges(sfVertexArray *array, sfVector2f **point_list, int **edge_table, int list_size);
void rotate(object_3d *object, sfVector3f *angle, int nb_edges, sfVector3f *cam);
sfVertex *create_vertex(float x, float y);
int *associate_edges(int a, int b, int c, int d);
shape *pyramid(float size);
vect4f *set_4d_vect(float x, float y, float z, float w);
shape_4d *tesseract(float size);
sfVector3f **project4d_to_3d(vect4f **pointlist, int list_size, vect4f cam);
void rotate_4d(shape_4d *cube, vect4f *angle, int nb_edges);
void change_cam_4d(sfVector2f **projection, sfVector3f **projection_3d, vect4f **pointlist, vect4f cam_4d, sfVector3f cam_3d, int list_size);
void change_color(sfVertexArray *array, sfColor color);
shape_4d *pyramide_cubique(float size);
sfVector2f *racine_nieme(int k, int n);
shape *create_circle(float rayon, int resolution);
int mod(int a, int b);
shape *create_sphere(int rayon, int res, int res3d);
shape_4d *create_sphere_4d(int rayon, int res, int res3d);
shape_4d *create_hypersphere(int rayon, int res, int res3d, int res4d);
int my_strlen(char *s);
int is_str_eq(char *s1, char *s2);
object_3d *create_3d(char *object_type, int size, int resolution, sfVector3f *cam);
void destroy_3d(object_3d *object, int nb_points);
void draw_button(button *bouton, sfRenderWindow *window);
button *create_button(char *text, int x, int y);
void check_click(game *jeu, sfRenderWindow *window);
game *init_game(int nb_shape);