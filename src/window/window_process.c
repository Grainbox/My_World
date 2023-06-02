/*
** EPITECH PROJECT, 2022
** B-MUL-200-REN-2-1-myworld-hugo1.fontaine
** File description:
** window_process
*/

#include <SFML/Graphics.h>
#include "my_world.h"
#include "my.h"
#include <stdlib.h>

window close_window(window window)
{
    sfRenderWindow_destroy(window.window);
    sfVertexArray_destroy(window.map);
    sfSprite_destroy(window.b1_sprite);
    return window;
}

void write_window(window window, map map)
{
    sfRenderWindow_clear(window.window, sfBlack);
    sfRenderWindow_drawSprite(window.window, window.bg_sprite, NULL);
    draw_map(window, map);
    if (map.dig == -1)
        sfRenderWindow_drawSprite(window.window, window.b2_sprite, NULL);
    else
        sfRenderWindow_drawSprite(window.window, window.b1_sprite, NULL);
    sfRenderWindow_drawSprite(window.window, window.b3_sprite, NULL);
    sfRenderWindow_drawSprite(window.window, window.b4_sprite, NULL);
    sfRenderWindow_display(window.window);
}

window create_window(void)
{
    sfVideoMode m = {1280, 720, 32};
    char t[] = "My World";
    sfRenderWindow *w = sfRenderWindow_create(m, t, sfResize | sfClose, NULL);
    sfEvent event;
    sfVertexArray *map = NULL;
    window screen = { m, w, event, map, NULL, NULL, NULL, NULL, NULL };

    sfRenderWindow_setFramerateLimit(screen.window, 30);
    screen = add_background(screen);
    screen = increase_button(screen);
    screen = dig_button(screen);
    screen = lines_button(screen);
    screen = tiles_button(screen);
    return screen;
}

map check_event(window window, map map)
{
    while (sfRenderWindow_pollEvent(window.window, &window.event)) {
        if (window.event.type == sfEvtClosed)
            sfRenderWindow_close(window.window);
        map = dig_button_event(window, map);
        map = lines_button_event(window, map);
        map = tiles_button_event(window, map);
    }
    return map;
}
