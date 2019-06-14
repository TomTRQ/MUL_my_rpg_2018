/*
** EPITECH PROJECT, 2019
** inventory.c
** File description:
** my_rpg
*/

#include <stdio.h>
#include <stdlib.h>
#include "rpg.h"

/*
    1 : potion d'attack
    2 : potion de soin
    3 : potion d'agilité
    4 : épée dep
    5 : épée fin
    6 : vetements dep
    7 : vetements fin
    8 : bouclier dep
    9 : bouclier fin
    10 : sable
    11 : cookie
    NB_ITMES = 11   0->11 == 12
    : potion de défense
*/

void fill_modif_inventory(char **tab, inventory_t *inventory, int i)
{
    int res = 0;

    inventory[i].param_player = malloc(sizeof(char) * my_strlen(tab[0]));
    inventory[i].param_player = my_strdup(tab[0]);
    res = my_getnbr(tab[1]);
    if (res > 0)
        inventory[i].damage = res;
    else
        inventory[i].enemy_damage = res;
    inventory[i].life = my_getnbr(tab[2]);
    inventory[i].rapidity = my_getnbr(tab[3]);
    inventory[i].leak = my_getnbr(tab[4]);
}

int modif_inventory(inventory_t *inventory, char *str, int i)
{
    FILE *dir = NULL;
    char *array = NULL;
    char **tab = NULL;
    size_t n = 0;

    dir = fopen(str, "r");
    if (dir == NULL)
        return (84);
    if (getline(&array, &n, dir) == -1)
        return (84);
    if (parse_argument(&tab, array, ':') == 84)
        return (84);
    fill_modif_inventory(tab, inventory, i);
    free_tab(&tab);
    fclose(dir);
    return (0);
}

int my_strlen_n(char *str)
{
    int i = 0;

    if (str == NULL)
        return (-84);
    for (i = 0; str[i] != '\0' && str[i] != '\n'; i++);
    return (i);
}

char *modif_str(char *str)
{
    char *tab = NULL;
    int i = my_strlen_n(str);

    if (i == -84)
        return (NULL);
    tab = malloc(sizeof(char) * (i + 1));
    if (tab == NULL)
        return (NULL);
    for (int j = 0; j < i; j++)
        tab[j] = str[j];
    tab[i] = '\0';
    return (tab);
}

int fill_inventory(inventory_t *inventory, FILE *dir)
{
    char *str = NULL;
    char *tab = NULL;
    size_t n = 0;

    for (int i = 0; i < NB_ITEMS; i++) {
        n = 0;
        str = NULL;
        if (getline(&str, &n, dir) == -1)
            return (84);
        tab = modif_str(str);
        inventory = initiate_inventory(inventory, i);
        if (modif_inventory(inventory, tab, i) == 84)
            return (84);
        free(tab);
        free(str);
    }
    return (0);
}