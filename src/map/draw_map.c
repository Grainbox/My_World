/*
** EPITECH PROJECT, 2022
** B-MUL-200-REN-2-1-myworld-hugo1.fontaine
** File description:
** draw_map
*/

#include "my_world.h"
#include "my.h"
#include <stdlib.h>

sfVertexArray *create_line(sfVector2f *point1, sfVector2f *point2)
{
    sfVertexArray *vertex_array = sfVertexArray_create();
    sfVertex vertex1 = {.position = *point1, .color = sfBlue };
    sfVertex vertex2 = {.position = *point2, .color = sfBlue };

    sfVertexArray_append(vertex_array ,vertex1);
    sfVertexArray_append(vertex_array ,vertex2);
    sfVertexArray_setPrimitiveType(vertex_array, sfLinesStrip);
    return (vertex_array);
}

void draw_tiles(window window, int y, map map1, int map_size)
{
    sfVector2f p1 = {0, 0};
    sfVector2f **map = map1.map;

    for (int x = 0; x < map_size; x++) {
        p1 = map[x][y];
        if ((y + 1) != map_size && (x + 1) != map_size) {
            tls pts = {p1, map[x + 1][y], map[x + 1][y + 1], map[x][y + 1]};
            convex(window, pts, map1.map_3d[x][y]);
        }
    }
}

int draw_2d_map(window window ,sfVector2f **map_2d, int map_size, int y)
{
    sfVertexArray *map = NULL;

    for (int x = 0; x < map_size; x++)
        if ((x + 1) != map_size) {
            map = create_line(&map_2d[y][x], &map_2d[y][x + 1]);
            sfRenderWindow_drawVertexArray(window.window, map, NULL);
        }
    for (int x = 0; x < map_size; x++)
        if ((y + 1) != map_size) {
            map = create_line(&map_2d[y][x], &map_2d[y + 1][x]);
            sfRenderWindow_drawVertexArray(window.window, map, NULL);
        }
    return 0;
}

void draw_map(window window, map map)
{
    if (map.display_tiles != -1) {
        for (int y = 0; y < map.map_size; y++)
            draw_tiles(window, y, map, map.map_size);
    }
    if (map.display_lines != -1) {
        for (int y = 0; y < map.map_size; y++)
            draw_2d_map(window, map.map, map.map_size, y);
    }
}
