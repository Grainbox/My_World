/*
** EPITECH PROJECT, 2022
** my_world
** File description:
** my_world
*/

#include "my_world.h"
#include "my.h"
#include <stdlib.h>
#include <stdio.h>
#include <SFML/Graphics.h>
#include <math.h>

int get_hitbox_size(int size)
{
    int hitbox = 0;

    if (size <= 20)
        hitbox = 6;
    else if (size <= 50)
        hitbox = 3;
    else
        hitbox = 1;
    return hitbox;
}

int get_tiles_size(int size)
{
    int tiles_size = 0;

    return size;
}

sfVector2f project_iso_point(int x, int y, int z)
{
    sfVector2f points = {0, 0};
    int angle_x = 15;
    int angle_y = -35;

    points.x = cos(angle_x) * x - cos(angle_x) * y;
    points.y = sin(angle_y) * y + sin(angle_y) * x - z;
    return points;
}

sfVector2f **create_2d_map(double **map_3d, int size)
{
    sfVector2f **map_2d = NULL;

    map_2d = malloc(sizeof(sfVector2f *) * size);
    for (int i = 0; i < size; i++)
        map_2d[i] = malloc(sizeof(sfVector2f) * size);
    for (int y = 0; y < size; y++)
        for (int x = 0; x < size; x++)
            map_2d[y][x] = project_iso_point(x, y, map_3d[y][x]);
    return map_2d;
}

double **create_3d_map(int size)
{
    double **map_3d = malloc(sizeof(double *) * size);

    for (int i = 0; i < size; i++) {
        map_3d[i] = malloc(sizeof(double) * size);
        for (int j = 0; j < size; j++)
            map_3d[i][j] = 0;
    }
    return map_3d;
}

void scaling_loop(window *window, sfVector2f **map_2d, int size)
{
    sfVector2u win_size = sfRenderWindow_getSize(window->window);
    double scale = 10000 / size * 0.008;

    for (int y = 0; y < size; y++)
        for (int x = 0; x < size; x++) {
            map_2d[y][x].x *= 10 * scale;
            map_2d[y][x].y *= 8 * scale;
            map_2d[y][x].x += (win_size.x / 2);
            map_2d[y][x].y += 100;
        }
}

map create_map(int size, window *window)
{
    double **map_3d = create_3d_map(size);
    int size_hitbox = get_hitbox_size(size);
    int size_tiles = get_tiles_size(size);
    sfVector2f **map_2d = create_2d_map(map_3d, size);
    map map = {0, 0, 0, map_3d, 1, 1, 1};

    scaling_loop(window, map_2d, size);
    map.map_size = size;
    map.size_hitbox = size_hitbox;
    map.map = map_2d;
    return (map);
}
