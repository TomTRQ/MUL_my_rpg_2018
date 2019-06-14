/*
** EPITECH PROJECT, 2019
** my rpg
** File description:
** initiate state
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "rpg.h"

int initiate_state(game_t **game)
{
    game[0] = malloc(sizeof(game_t));
    if (game[0] == NULL)
        return (84);
    game[0]->scene = malloc(sizeof(scene_t *) * (NB_SCENE + 1));
    if (game[0]->scene == NULL)
        return (84);
    write(1, "Initiating the scene...\n", 24);
    if (initiate_all_scene(game) == 84)
        return (84);
    write(1, "Initiating objects and buttons...\n", 34);
    if (initiate_all_button(game) == 84)
        return (84);
    if (initiate_sf_object(game) == 84)
        return (84);
    game[0]->scene_nb = 0;
    game[0]->player = initiate_player();
    if (game[0]->player == NULL)
        return (84);
    game[0]->time = initiate_time_struct();
    return (0);
}