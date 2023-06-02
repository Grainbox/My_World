/*
** EPITECH PROJECT, 2022
** my_world
** File description:
** my_world
*/

#ifndef MY_WORLD_H_

    #define MY_WORLD_H_

    #include "./my_world_struct.h"

    #include <SFML/Graphics.h>

    map create_map(int size, window *window);

    sfVector2f **create_2d_map(double **map_3d, int size);

    sfVector2f project_iso_point(int x, int y, int z);

    void draw_map(window window, map map);

    window create_window(void);

    window close_window(window window);

    map check_event(window window, map map);

    void write_window(window window, map map);

    window increase_button(window window);

    window dig_button(window window);

    window lines_button(window window);

    window tiles_button(window window);

    void convex(window window, tls points, float height);

    window add_background(window window);

    void draw_background(window window);

    map modify_map(window *window, map map);

    int get_hitbox_size(int size);

    map dig_button_event(window window, map map);

    char *double_str(double num);

    void scaling_loop(window *window, sfVector2f **map_2d, int size);

    map lines_button_event(window window, map map);

    map tiles_button_event(window window, map map);

    vector2i find_selected_point(window *window, map map1);

    sfBool check_tile(map empty_map, int x, int y, sfVector2i mouse_pos);

#endif
