/*
** EPITECH PROJECT, 2019
** rpg
** File description:
** verification for a char **
*/

#include "my.h"

int out_of_map(char **str, float y, float x)
{
    int len = my_strarray(str);
    int lenght = 0;

    if (y < 0 || x < 0)
        return (1);
    if (y > len)
        return (1);
    lenght = my_strlen(str[(int)y]);
    if (x > lenght)
        return (1);
    return (0);
}