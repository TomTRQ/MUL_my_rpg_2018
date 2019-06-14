/*
** EPITECH PROJECT, 2019
** struct inventory file for the project
** File description:
** my_rpg
*/

//#include "rpg.h"
#include <stdio.h>
#include <stdlib.h>

static char *my_revstr(char *str, int len)
{
    char nbr;

    for (int count = 0; count < (len / 2); count++) {
        nbr = str[count];
        str[count] = str[len - count - 1];
        str[len - count - 1] = nbr;
    }
    str[len] = '\0';
    return (str);
}

static char *negative(int nbr)
{
    char *result;
    int a = 0;

    for (int nb = nbr * -1; nb != 0; nb = nb / 10, a++);
    result = malloc((a + 2) * sizeof(char));
    for (int nb = nbr * -1, a = 0; nb > 0; nb = nb / 10, a++)
        result[a] = nb % 10 + 48;
    result[a] = '-';
    result[a + 1] = '\0';
    result = my_revstr(result, a + 1);
    return (result);
}

char *my_convert_to_char(int nbr)
{
    int a = 0;
    char *result;

    if (nbr < 0)
        negative(nbr);
    for (int nb = nbr; nb != 0; nb = nb / 10, a++);
    result = malloc((a + 1) * sizeof(char));
    if (result == NULL)
        return (NULL);
    for (int nb = nbr, a = 0; nb > 0; nb = nb / 10, a++)
        result[a] = nb % 10 + 48;
    result[a] = '\0';
    result = my_revstr(result, a);
    return (result);
}