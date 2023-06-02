/*
** EPITECH PROJECT, 2022
** modify_map.c
** File description:
** functions to modify the map
*/

#include <SFML/Graphics.h>
#include "my_world.h"
#include <stdlib.h>
#include <stdio.h>
#include "my.h"

sfVector2f get_origine_pos(window *window)
{
    sfVector2f point_origine;
    sfVector2u win_size = sfRenderWindow_getSize(window->window);

    point_origine.x = win_size.x / 2;
    point_origine.y = 100;
    return point_origine;
}

map change_map(vector2i pt_select, map map, window *window, int sig)
{
    if (sig == 1)
        map.map_3d[pt_select.x][pt_select.y] += 0.5;
    if (sig == 2)
        map.map_3d[pt_select.x][pt_select.y] -= 0.5;
    map.map = create_2d_map(map.map_3d, map.map_size);
    scaling_loop(window, map.map, map.map_size);
    return map;
}

vector2i get_first_vector2i(void)
{
    vector2i vector;

    vector.x = 0;
    vector.y = 0;
    vector.init = 0;
    return vector;
}

void get_tile(vector2i *tile, vector2i pt_selected)
{
    tile[0].x = pt_selected.x;
    tile[0].y = pt_selected.y;
    tile[1].x = pt_selected.x - 1;
    tile[1].y = pt_selected.y;
    tile[2].x = pt_selected.x;
    tile[2].y = pt_selected.y - 1;
    tile[3].x = pt_selected.x - 1;
    tile[3].y = pt_selected.y - 1;
}

vector2i *find_selected_tile(window *window, map map1)
{
    vector2i *tile = malloc(sizeof(vector2i) * 4);
    vector2i point_selected;
    map empty_map = create_map(map1.map_size, window);
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(window->window);
    int y = 0;
    double scale = 10000 / map1.map_size * 0.008;

    for (int x = 0; x != map1.map_size && y != map1.map_size;) {
        if (check_tile(empty_map, x, y, mouse_pos) == sfTrue) {
            point_selected.x = x;
            point_selected.y = y;
            get_tile(tile, point_selected);
            return tile;
        } else
            y++;
        if (y == map1.map_size && x != map1.map_size) {
            y = 0;
            x++;
        }
    }
    return tile;
}

map modify_map(window *window, map map1)
{
    sfVector2u win_size = sfRenderWindow_getSize(window->window);
    vector2i point_selected = get_first_vector2i();
    vector2i *tile_selected = malloc(sizeof(vector2i) * 4);
    int sig = 0;
    int tile_init = 0;

    if (sfMouse_isButtonPressed(sfMouseLeft) == sfTrue) {
        if (map1.dig == 1)
            sig = 1;
        else
            sig = 2;
        point_selected = find_selected_point(window, map1);
        sfVector2i mouse_pos = sfMouse_getPosition(window->window);
        if (point_selected.init == 1 &&
            point_selected.x <= map1.map_size - 1 &&
            point_selected.y <= map1.map_size - 1)
            map1 = change_map(point_selected, map1, window, sig);
    }
    return map1;
}
