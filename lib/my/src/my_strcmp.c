/*
** EPITECH PROJECT, 2021
** my_str_cmp
** File description:
** |
*/

#include <stdbool.h>
#include "my.h"

int my_strcmp(char const *s1, char const *s2)
{
    if (my_strlen(s1) != my_strlen(s2))
        return false;
    for (int i = 0; s1[i] != '\0'; i++)
        if (s2[i] != s1[i])
            return false;
    return true;
}
