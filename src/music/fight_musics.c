/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** main fight funcs
*/

#include "rpg.h"

void play_sound(sfSoundBuffer *buffer)
{
    sfSound *sound = sfSound_create();

    sfSound_setVolume(sound, VOLUME_ON);
    sfSound_setBuffer(sound, buffer);
    sfSound_play(sound);
}

void handle_music(game_t **game, sfMusic *music)
{
    if (sfMusic_getStatus(GAME_MUSIC->back) == sfPlaying) {
        sfMusic_pause(GAME_MUSIC->back);
        sfMusic_play(music);
    } else if (sfMusic_getStatus(GAME_MUSIC->donjon) == sfPlaying) {
        sfMusic_pause(GAME_MUSIC->donjon);
        sfMusic_play(music);
    }
}

void choose_music_fight(game_t **game, enemy_t *enemy)
{
    if (enemy->stat->hp_max >= 150)
        handle_music(game, GAME_MUSIC->boss);
    else
        handle_music(game, GAME_MUSIC->mob);
}

void close_music_fight(game_t **game, enemy_t *enemy, sfMusic *playing)
{
    if (enemy->stat->hp_max >= 150) {
        sfMusic_pause(GAME_MUSIC->boss);
        sfMusic_play(playing);
    } else {
        sfMusic_pause(GAME_MUSIC->mob);
        sfMusic_play(playing);
    }
}

sfMusic *get_playing_music(game_t **game)
{
    if (sfMusic_getStatus(GAME_MUSIC->back) == sfPlaying)
        return (GAME_MUSIC->back);
    else if (sfMusic_getStatus(GAME_MUSIC->donjon) == sfPlaying)
        return (GAME_MUSIC->donjon);
    return (GAME_MUSIC->back);
}