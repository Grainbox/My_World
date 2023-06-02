/*
** EPITECH PROJECT, 2022
** B-MUL-200-REN-2-1-myworld-hugo1.fontaine
** File description:
** my_world_struct
*/

#ifndef MY_WORLD_STRUCT_H_
    #define MY_WORLD_STRUCT_H_

    #include <SFML/Graphics.h>

    struct window {
        sfVideoMode mode;
        sfRenderWindow *window;
        sfEvent event;
        sfVertexArray *map;
        sfSprite *b1_sprite;
        sfSprite *b2_sprite;
        sfSprite *b3_sprite;
        sfSprite *b4_sprite;
        sfSprite *bg_sprite;
    };
    typedef struct window window;

    struct map {
        int map_size;
        int size_hitbox;
        sfVector2f **map;
        double **map_3d;
        int dig;
        int display_lines;
        int display_tiles;
    };
    typedef struct map map;

    struct floor_tiles {
        sfVector2f point1;
        sfVector2f point2;
        sfVector2f point3;
        sfVector2f point4;
    };
    typedef struct floor_tiles tls;

    struct vector2i {
        int x;
        int y;
        int init;
        double dx;
        double dy;
    };
    typedef struct vector2i vector2i;

#endif
