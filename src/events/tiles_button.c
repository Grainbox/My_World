/*
** EPITECH PROJECT, 2022
** B-MUL-200-REN-2-1-myworld-hugo1.fontaine
** File description:
** tiles_button
*/

#include <SFML/Graphics.h>
#include "my_world.h"
#include "my.h"
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <unistd.h>
#include <fcntl.h>

map tiles_button_event(window window, map map)
{
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(window.window);
    sfBool event = sfMouse_isButtonPressed(sfMouseLeft);

    if (event == sfTrue && mouse_pos.y >= 656)
        if (mouse_pos.y <= 710 && mouse_pos.x >= 110 && mouse_pos.x <= 220)
            map.display_tiles *= -1;
    return map;
}
