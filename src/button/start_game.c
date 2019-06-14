/*
** EPITECH PROJECT, 2019
** my rpg
** File description:
** start game
*/

#include "rpg.h"

int start_game(game_t **game)
{
    sfSound *sound = sfSound_create();
    sfSoundBuffer *buffer = sfSoundBuffer_createFromFile\
    ("assets/sound/hearthquake.ogg");

    sfMusic_pause(GAME_MUSIC->menu);
    change_scene(game, "house_up");
    sfRenderWindow_clear(GAME_WINDOW, sfBlack);
    if (display(game) == 84)
        return (84);
    sfRenderWindow_display(GAME_WINDOW);
    check_if_activate_dialogs(game, sound, buffer);
    sfRenderWindow_display(GAME_WINDOW);
    check_if_activate_dialogs(game, sound, buffer);
    return (0);
}

int menu_game(game_t **game)
{
    change_scene(game, "menu");
    return (0);
}