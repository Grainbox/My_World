/*
** EPITECH PROJECT, 2022
** B-MUL-200-REN-2-1-myworld-hugo1.fontaine
** File description:
** select_pint
*/

#include <SFML/Graphics.h>
#include "my_world.h"
#include <stdlib.h>
#include <stdio.h>
#include "my.h"

sfBool check_tile(map empty_map, int x, int y, sfVector2i mouse_pos)
{
    int sig = 0;

    if (x == 0 || y == 0)
        return sfFalse;
    if (mouse_pos.x > empty_map.map[x][y - 1].x &&
        mouse_pos.x < empty_map.map[x - 1][y].x)
        sig++;
    if (mouse_pos.y > empty_map.map[x - 1][y - 1].y &&
        mouse_pos.y <= empty_map.map[x][y].y)
        sig++;
    if (sig == 2)
        return sfTrue;
    else
        return sfFalse;
}

sfBool check_point(map empty_map, int x, int y, sfVector2i mouse_pos)
{
    int sig = 0;

    if (empty_map.map[x][y].x <= mouse_pos.x + empty_map.size_hitbox &&
        empty_map.map[x][y].x >= mouse_pos.x - empty_map.size_hitbox)
        sig++;
    if (empty_map.map[x][y].y <= mouse_pos.y + empty_map.size_hitbox &&
        empty_map.map[x][y].y >= mouse_pos.y - empty_map.size_hitbox)
        sig++;
    if (sig == 2)
        return sfTrue;
    else
        return sfFalse;
}

vector2i find_selected_point(window *window, map map1)
{
    vector2i point_selected;
    map empty_map = create_map(map1.map_size, window);
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(window->window);
    int y = 0;

    for (int x = 0; x != map1.map_size && y != map1.map_size;) {
        if (check_point(empty_map, x, y, mouse_pos) == sfTrue) {
            point_selected.x = x;
            point_selected.y = y;
            point_selected.init = 1;
            return point_selected;
        } else
            y++;
        if (y == map1.map_size && x != map1.map_size) {
            y = 0;
            x++;
        }
    }
    point_selected.init = 0;
    return point_selected;
}
