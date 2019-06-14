/*
** EPITECH PROJECT, 2019
** inventory.c
** File description:
** my_rpg
*/

#include "rpg.h"
#include <stdio.h>
#include <stdlib.h>

int inventory_game(game_t **game)
{
    static char *scene = NULL;

    if (game[0]->scene_nb == 0)
        return (EXIT_SUCCESS);
    if (scene == NULL) {
        my_str_to_str(&scene, GAME_SCENE->name);
        change_scene(game, "inventory");
    } else {
        change_scene(game, scene);
        free(scene);
        scene = NULL;
    }
    return (EXIT_SUCCESS);
}