/*
** EPITECH PROJECT, 2019
** rpg
** File description:
** initiate enemies
*/

#include <stdlib.h>
#include <unistd.h>
#include "rpg.h"

void setting_volume_music(game_t **game, int sound)
{
    if (sound == 1) {
        sfMusic_setVolume(GAME_MUSIC->menu, VOLUME_ON);
        sfMusic_setVolume(GAME_MUSIC->boss, VOLUME_ON);
        sfMusic_setVolume(GAME_MUSIC->back, VOLUME_ON);
        sfMusic_setVolume(GAME_MUSIC->mob, VOLUME_ON);
        sfMusic_setVolume(GAME_MUSIC->donjon, VOLUME_ON);
        sfMusic_setVolume(GAME_MUSIC->final_boss, VOLUME_ON);
    } else {
        sfMusic_setVolume(GAME_MUSIC->menu, 0);
        sfMusic_setVolume(GAME_MUSIC->boss, 0);
        sfMusic_setVolume(GAME_MUSIC->back, 0);
        sfMusic_setVolume(GAME_MUSIC->mob, 0);
        sfMusic_setVolume(GAME_MUSIC->donjon, 0);
        sfMusic_setVolume(GAME_MUSIC->final_boss, 0);
    }
}

void setting_loop_music(game_t **game)
{
    sfMusic_setLoop(GAME_MUSIC->menu, sfTrue);
    sfMusic_setLoop(GAME_MUSIC->boss, sfTrue);
    sfMusic_setLoop(GAME_MUSIC->back, sfTrue);
    sfMusic_setLoop(GAME_MUSIC->mob, sfTrue);
    sfMusic_setLoop(GAME_MUSIC->donjon, sfTrue);
    sfMusic_setLoop(GAME_MUSIC->final_boss, sfTrue);
}

int initiate_music_struct(game_t **game)
{
    game[0]->music = malloc(sizeof(music_t));

    if (game[0]->music == NULL)
        return (84);
    GAME_MUSIC->menu = sfMusic_createFromFile("assets/music/menu.ogg");
    GAME_MUSIC->boss = sfMusic_createFromFile("assets/music/boss_fight.ogg");
    GAME_MUSIC->back = sfMusic_createFromFile("assets/music/background.ogg");
    GAME_MUSIC->mob = sfMusic_createFromFile("assets/music/fight.ogg");
    GAME_MUSIC->donjon = sfMusic_createFromFile("assets/music/dungeon.ogg");
    GAME_MUSIC->final_boss = sfMusic_createFromFile\
    ("assets/music/final_boss.ogg");
    setting_loop_music(game);
    setting_volume_music(game, 1);
    sfMusic_play(GAME_MUSIC->menu);
    write(1, "Musics initiated\n", 17);
    return (0);
}