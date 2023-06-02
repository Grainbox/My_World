/*
** EPITECH PROJECT, 2022
** B-MUL-200-REN-2-1-myworld-hugo1.fontaine
** File description:
** draw_convex
*/

#include <SFML/Graphics.h>
#include "my_world.h"
#include "my.h"

int check_height2(float height, sfColor *color)
{
    if (height < -3) {
        color->r = 61;
        color->g = 61;
        color->b = 61;
        return 0;
    }
    if (height > 3) {
        color->r = 212;
        color->g = 209;
        color->b = 207;
        return 0;
    }
    return 0;
}

sfColor check_height(float height)
{
    sfColor color = {0, 0, 0, 255};

    if (height >= 0 && height <= 3) {
        color.r = 28;
        color.g = 117;
        color.b = 52;
        return color;
    }
    if (height >= -3 && height < 0) {
        color.r = 97;
        color.g = 51;
        color.b = 16;
        return color;
    }
    check_height2(height, &color);
    return color;
}

void convex(window window, tls points, float height)
{
    sfConvexShape *shape = sfConvexShape_create();
    sfColor color = check_height(height);

    sfConvexShape_setPointCount(shape, 4);
    sfConvexShape_setPoint(shape, 0, points.point1);
    sfConvexShape_setPoint(shape, 1, points.point2);
    sfConvexShape_setPoint(shape, 2, points.point3);
    sfConvexShape_setPoint(shape, 3, points.point4);
    sfConvexShape_setFillColor(shape, color);
    sfRenderWindow_drawConvexShape(window.window, shape, NULL);
    sfConvexShape_destroy(shape);
}
