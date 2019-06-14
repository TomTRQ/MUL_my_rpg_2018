/*
** EPITECH PROJECT, 2019
** my rpg
** File description:
** start and resume the pause
*/

#include "rpg.h"

int pause_game(game_t **game)
{
    static int scene = 0;

    if (game[0]->scene_nb > 1) {
        scene = game[0]->scene_nb;
        game[0]->scene_nb = 1;
    } else {
        game[0]->scene_nb = scene;
    }
    return (0);
}