/*
** EPITECH PROJECT, 2022
** my_world
** File description:
** window
*/

#include <SFML/Graphics.h>
#include "my_world.h"
#include <stdlib.h>

int main(void)
{
    window window = create_window();
    map map = create_map(20, &window);

    while (sfRenderWindow_isOpen(window.window)) {
        sfRenderWindow_clear(window.window, sfBlack);
        map = modify_map(&window, map);
        map = check_event(window, map);
        write_window(window, map);
    }
    window = close_window(window);
    return 0;
}
