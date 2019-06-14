/*
** EPITECH PROJECT, 2019
** inventory.c
** File description:
** my_rpg
*/

#include "rpg.h"
#include <stdio.h>
#include <stdlib.h>

int display_hp(sfText *text, game_t **game,
    sfVector2f coord)
{
    char *tab = NULL;

    tab = my_strcat("Life : ", int_to_array(GAME_STAT->hp));
    if (tab == NULL)
        return (EXIT_FAILURE);
    tab = my_strcat(tab, "/");
    if (tab == NULL)
        return (EXIT_FAILURE);
    tab = my_strcat(tab, int_to_array(GAME_STAT->hp_max));
    if (tab == NULL)
        return (EXIT_FAILURE);
    sfText_setString(text, tab);
    coord.x = 40;
    coord.y = 400;
    display_text(text, game, coord, 40);
    free(tab);
    return (EXIT_SUCCESS);
}

int display_name(sfText *text, game_t **game,
    sfVector2f coord)
{
    coord.x = 560;
    coord.y = 30;
    sfText_setString(text, GAME_PLAYER->name);
    display_text(text, game, coord, 60);
    return (EXIT_SUCCESS);
}

int display_level(sfText *text, game_t **game,
    sfVector2f coord)
{
    char *tab = NULL;

    coord.x = 470;
    coord.y = 100;
    tab = my_strcat("Level : ",
        int_to_array(GAME_STAT->level));
    if (tab == NULL)
        return (EXIT_FAILURE);
    sfText_setString(text, tab);
    display_text(text, game, coord, 55);
    free(tab);
    return (EXIT_SUCCESS);
}

int display_xp(sfText *text, game_t **game,
    sfVector2f coord)
{
    char *tab = NULL;

    coord.x = 690;
    coord.y = 100;
    tab = my_strcat("Xp: ", int_to_array(GAME_STAT->xp));
    tab = my_strcat(tab, "/");
    tab = my_strcat(tab, int_to_array(GAME_STAT->xp_max));
    if (tab == NULL)
        return (EXIT_FAILURE);
    sfText_setString(text, tab);
    display_text(text, game, coord, 55);
    free(tab);
    return (EXIT_SUCCESS);
}