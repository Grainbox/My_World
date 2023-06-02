/*
** EPITECH PROJECT, 2021
** Project_Template
** File description:
** my_to_number
*/

#include "my.h"
#include <stdlib.h>

void int_to_str(char *str, int number)
{
    int to_number = number;
    int gap = 0;
    int count = 0;

    if (number == 0) {
        str[count] = '0';
        count++;
    }
    while (to_number > 0) {
        to_number /= 10;
        count++;
    }
    for (int i = 0; i < count; i++) {
        gap = number % 10;
        number /= 10;
        str[count - (i + 1)] = gap + '0';
    }
    str[count] = '\0';
}

void combine(char *str, char *str2)
{
    int i = 0;
    int l = 0;

    for (; str[i] != '\0'; i++);
    str[i] = '.';
    for (i++; str2[i] != '\0'; i++, l++)
        str[i] = str2[l];
    str[i] = '\0';
}

char *double_str(double num)
{
    int ipart = (int)num;
    double fpart = num - (double)ipart + 1e-9;
    int after_dot = 1;
    char *str = malloc(sizeof(char) * 20);
    char str2[20];
    int i = 0;

    int_to_str(str, ipart);
    for (; str[i] != '\0'; i++);
    for (; after_dot > 0; after_dot--)
        fpart *= 10;
    ipart = (int)fpart;
    int_to_str(str2, ipart);
    combine(str, str2);
    return str;
}
