/*
** EPITECH PROJECT, 2022
** 3d-projection
** File description:
** mod.c
*/

int mod(int a, int b)
{
    int r = a % b;
    if (r < 0)
        r = b + r;
    return r;
}
