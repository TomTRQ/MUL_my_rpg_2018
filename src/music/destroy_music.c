/*
** EPITECH PROJECT, 2019
** rpg
** File description:
** initiate enemies
*/

#include "rpg.h"

void destroy_music(game_t **game)
{
    sfMusic_destroy(GAME_MUSIC->menu);
    sfMusic_destroy(GAME_MUSIC->boss);
    sfMusic_destroy(GAME_MUSIC->back);
    sfMusic_destroy(GAME_MUSIC->mob);
    sfMusic_destroy(GAME_MUSIC->donjon);
    sfMusic_destroy(GAME_MUSIC->final_boss);
}