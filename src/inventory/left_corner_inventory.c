/*
** EPITECH PROJECT, 2019
** inventory.c
** File description:
** my_rpg
*/

#include "rpg.h"
#include <stdio.h>
#include <stdlib.h>

int display_def(sfText *text, game_t **game,
    sfVector2f coord)
{
    char *tab = NULL;

    coord.x = 40;
    coord.y = 650;
    tab = my_strcat("Defense : ",
        my_convert_to_char(GAME_STAT->defense));
    if (tab == NULL)
        return (EXIT_FAILURE);
    sfText_setString(text, tab);
    display_text(text, game, coord, 40);
    return (EXIT_SUCCESS);
}

int display_chance_escape(sfText *text, game_t **game,
    sfVector2f coord)
{
    char *tab = NULL;

    coord.x = 40;
    coord.y = 600;
    tab = my_strcat("Escape : ",
        int_to_array(GAME_STAT->chance_escape));
    tab = my_strcat(tab, "%");
    if (tab == NULL)
        return (EXIT_FAILURE);
    if (tab == NULL)
        return (EXIT_FAILURE);
    sfText_setString(text, tab);
    display_text(text, game, coord, 40);
    return (EXIT_SUCCESS);
}

int display_chance_criticism(sfText *text, game_t **game,
    sfVector2f coord)
{
    char *tab = NULL;

    coord.x = 40;
    coord.y = 550;
    tab = my_strcat("Criticism : ",
        int_to_array(GAME_STAT->chance_criticism));
    tab = my_strcat(tab, "%");
    if (tab == NULL)
        return (EXIT_FAILURE);
    if (tab == NULL)
        return (EXIT_FAILURE);
    sfText_setString(text, tab);
    display_text(text, game, coord, 40);
    return (EXIT_SUCCESS);
}

int display_speed_attack(sfText *text, game_t **game,
    sfVector2f coord)
{
    char *tab = NULL;

    coord.x = 40;
    coord.y = 500;
    tab = my_strcat("Speed : ",
        my_convert_to_char(GAME_STAT->speed_attack));
    if (tab == NULL)
        return (EXIT_FAILURE);
    sfText_setString(text, tab);
    display_text(text, game, coord, 40);
    return (EXIT_SUCCESS);
}

int display_attack(sfText *text, game_t **game,
    sfVector2f coord)
{
    char *tab = NULL;

    coord.x = 40;
    coord.y = 450;
    tab = my_strcat("Attack : ",
        my_convert_to_char(GAME_STAT->attack));
    if (tab == NULL)
        return (EXIT_FAILURE);
    sfText_setString(text, tab);
    display_text(text, game, coord, 40);
    free(tab);
    return (EXIT_SUCCESS);
}