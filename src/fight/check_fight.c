/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** check_fight
*/

#include "rpg.h"

int check_start_fight(game_t **game)
{
    if (game[0]->enemy_spawn <= 3 && is_fight_scene(GAME_SCENE) == A_SUCCESS) {
        game[0]->enemy_spawn = 4;
        launch_fight(game, GAME_SCENE->enemy);
    }
    return (0);
}