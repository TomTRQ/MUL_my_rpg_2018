/*
** EPITECH PROJECT, 2019
** my rpg
** File description:
** free everythings
*/

#include <stdlib.h>
#include "rpg.h"

int free_tab(char ***tab)
{
    if (tab[0] == NULL)
        return (0);
    for (int i = 0; tab[0][i] != NULL; i++)
        free(tab[0][i]);
    free(tab[0]);
    tab[0] = NULL;
    return (0);
}

int free_str(char **str)
{
    if (str == NULL)
        return (0);
    free(str[0]);
    str[0] = NULL;
    return (0);
}