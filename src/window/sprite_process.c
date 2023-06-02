/*
** EPITECH PROJECT, 2022
** B-MUL-200-REN-2-1-myworld-hugo1.fontaine
** File description:
** sprite_process
*/

#include <SFML/Graphics.h>
#include "my_world.h"
#include <stdlib.h>

window add_background(window window)
{
    sfTexture *texture = NULL;
    sfSprite *sprite = sfSprite_create();
    sfVector2f pos = {0, 0};

    texture = sfTexture_createFromFile("./assets/pink_sky.jpg", NULL);
    sfSprite_setTexture(sprite, texture, sfTrue);
    sfSprite_setPosition(sprite, pos);
    window.bg_sprite = sprite;
    return window;
}

window increase_button(window window)
{
    sfTexture *texture = NULL;
    sfSprite *sprite = sfSprite_create();
    sfVector2f scale = {0.05, 0.05};
    sfVector2f pos = { 230, 650 };

    texture = sfTexture_createFromFile("./assets/increase.png", NULL);
    sfSprite_setTexture(sprite, texture, sfTrue);
    sfSprite_setScale(sprite, scale);
    sfSprite_setPosition(sprite, pos);
    window.b1_sprite = sprite;
    return window;
}

window dig_button(window window)
{
    sfTexture *texture = NULL;
    sfSprite *sprite = sfSprite_create();
    sfVector2f scale = {0.05, 0.05};
    sfVector2f pos = {230, 650};

    texture = sfTexture_createFromFile("./assets/dig.png", NULL);
    sfSprite_setTexture(sprite, texture, sfTrue);
    sfSprite_setScale(sprite, scale);
    sfSprite_setPosition(sprite, pos);
    window.b2_sprite = sprite;
    return window;
}

window lines_button(window window)
{
    sfTexture *texture = NULL;
    sfSprite *sprite = sfSprite_create();
    sfVector2f scale = {0.05, 0.05};
    sfVector2f pos = {360, 650};

    texture = sfTexture_createFromFile("./assets/lines.png", NULL);
    sfSprite_setTexture(sprite, texture, sfTrue);
    sfSprite_setScale(sprite, scale);
    sfSprite_setPosition(sprite, pos);
    window.b3_sprite = sprite;
    return window;
}

window tiles_button(window window)
{
    sfTexture *texture = NULL;
    sfSprite *sprite = sfSprite_create();
    sfVector2f scale = {0.05, 0.05};
    sfVector2f pos = {100, 650};

    texture = sfTexture_createFromFile("./assets/tiles.png", NULL);
    sfSprite_setTexture(sprite, texture, sfTrue);
    sfSprite_setScale(sprite, scale);
    sfSprite_setPosition(sprite, pos);
    window.b4_sprite = sprite;
    return window;
}
