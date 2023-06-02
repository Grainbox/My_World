/*
** EPITECH PROJECT, 2022
** int_to_char
** File description:
** int_to_char
*/

#include "my.h"
#include <stdbool.h>
#include <stdlib.h>
#include <limits.h>

void add_end(char *buffer, int n)
{
    if (n == 0) {
        buffer[0] = '0';
        buffer[1] = '\0';
    }
}

char *int_to_char(int n)
{
    char *buffer = malloc(sizeof(char) * 50);
    int i = 0;
    bool isneg = n<0;
    unsigned int n1 = isneg ? -n : n;

    while (n1 != 0) {
        buffer[i++] = n1 % 10 + '0';
        n1 = n1 / 10;
    }
    if (isneg)
        buffer[i++] = '-';
    buffer[i] = '\0';
    for (int t = 0; t < i / 2; t++) {
        buffer[t] ^= buffer[i-t-1];
        buffer[i-t-1] ^= buffer[t];
        buffer[t] ^= buffer[i-t-1];
    }
    add_end(buffer, n);
    return buffer;
}
