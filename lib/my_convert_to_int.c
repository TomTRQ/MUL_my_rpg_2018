/*
** EPITECH PROJECT, 2018
** my_convert_to_int
** File description:
** my_convert_to_int
*/

#include <stddef.h>
#include "my.h"

int my_compute_power_it(int nb, int p)
{
    int a = nb;
    int count;

    if (p < 0 || p > 100000)
        return (0);
    if (p == 0)
        return (1);
    for (count = 1; count < p; count++) {
        nb = nb * a;
    }
    return (nb);
}

char *my_revstr(char *str)
{
    int a = 0;
    int count = 0;
    char nbr;

    if (str == NULL)
        return (NULL);
    while (str[a] != '\0')
        a++;
    while (count < a / 2) {
        nbr = str[count];
        str[count] = str[a - count - 1];
        str[a - count - 1] = nbr;
        count++;
    }
    str[a] = '\0';
    return (str);
}

int my_convert_to_int(char *str)
{
    int a = 0;
    int result = 0;

    if (str == NULL)
        return (0);
    str = my_revstr(str);
    while (str[a] != '\0') {
        if (a >= 1)
            result = result + ((str[a] - 48) * my_compute_power_it(10, a));
        else
            result = result + ((str[a] - 48));
        a++;
    }
    return (result);
}
