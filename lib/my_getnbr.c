/*
** EPITECH PROJECT, 2018
** my_getnbr.c
** File description:
** task05
*/

#include <stddef.h>

int my_getnbr(char const *str)
{
    int j;
    int count = 0;
    int a = 0;

    if (str == NULL)
        return (84);
    for (j = 0; str[j] != '\0'; j++) {
        if (str[j] <= '9' && str[j] >= '0')
            count = (count * 10) + (str[j] - 48);
        else if (str[j] == '-')
            a = 1;
        else
            return (0);
    }
    if (a == 1)
        count = count * (-1);
    return (count);
}

int my_getnbr_ptr(char const *str, int *nb)
{
    int j;
    int count = 0;
    int a = 0;

    if (str == NULL)
        return (84);
    for (j = 0; str[j] != '\0'; j++) {
        if (str[j] <= '9' && str[j] >= '0')
            count = (count * 10) + (str[j] - 48);
        else if (str[j] == '-')
            a = 1;
        else
            return (84);
    }
    if (a == 1)
        count = count * (-1);
    nb[0] = count;
    return (0);
}

int my_getnbr_lim(char const *str, char c)
{
    int count = 0;
    int a = 0;

    if (str == NULL)
        return (0);
    if (str[0] == '-') {
        a = 1;
    }
    for (int j = a; str[j] != '\0'; j++) {
        if (str[j] <= '9' && str[j] >= '0')
            count = (count * 10) + (str[j] - 48);
        else if (str[j] == c)
            break;
        else
            return (0);
    }
    if (a == 1)
        count = count * (-1);
    return (count);
}