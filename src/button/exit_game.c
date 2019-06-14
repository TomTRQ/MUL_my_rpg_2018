/*
** EPITECH PROJECT, 2019
** my rpg
** File description:
** exit game
*/

#include <unistd.h>
#include "rpg.h"

int exit_game(game_t **game)
{
    sfRenderWindow_close(GAME_WINDOW);
    return (0);
}