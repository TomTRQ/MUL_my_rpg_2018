/*
** EPITECH PROJECT, 2019
** rpg
** File description:
** go out or inside a building
*/

#include "rpg.h"

int go_donjon(game_t **game)
{
    char wood[] = "donjon_wood";
    char mine[] = "donjon_mine";
    char water[] = "donjon_water";
    int val = 0;

    sfMusic_pause(GAME_MUSIC->back);
    if (compare_str(GAME_SCENE->name, "path_wood") == 0)
        val = change_scene(game, wood);
    if (compare_str(GAME_SCENE->name, "path_mine") == 0)
        val = change_scene(game, mine);
    if (compare_str(GAME_SCENE->name, "path_water") == 0)
        val = change_scene(game, water);
    sfMusic_play(GAME_MUSIC->donjon);
    return (val);
}

int go_out(game_t **game)
{
    char wood[] = "path_wood";
    char mine[] = "path_mine";
    char water[] = "path_water";
    int val = 0;

    sfMusic_pause(GAME_MUSIC->donjon);
    if (compare_str(GAME_SCENE->name, "donjon_wood") == 0)
        val = change_scene(game, wood);
    if (compare_str(GAME_SCENE->name, "donjon_mine") == 0)
        val = change_scene(game, mine);
    if (compare_str(GAME_SCENE->name, "donjon_water") == 0)
        val = change_scene(game, water);
    sfMusic_play(GAME_MUSIC->back);
    return (val);
}