/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** Win / lose / leav
*/

#include <unistd.h>
#include "rpg.h"

static void game_over(game_t **game)
{
    sfSprite *sprite;
    sfTexture *texture;

    sprite = sfSprite_create();
    texture = sfTexture_createFromFile("assets/background/game_over.png", NULL);
    sfSprite_setTexture(sprite, texture, sfTrue);
    while (sfKeyboard_isKeyPressed(sfKeySpace) == sfFalse) {
        sfRenderWindow_clear(GAME_WINDOW, sfBlack);
        sfRenderWindow_drawSprite(GAME_WINDOW, sprite, NULL);
        sfRenderWindow_display(GAME_WINDOW);
    }
}

void win_fight(game_t **game, enemy_t *enemy)
{
    sfTime time_sleep = {3000000};

    game[0]->player->stat_player->xp += enemy->stat->xp;
    if (game[0]->player->stat_player->xp >= \
    game[0]->player->stat_player->xp_max) {
        game[0]->player->stat_player->level += 1;
        game[0]->player->stat_player->xp_max += 100;
        game[0]->player->stat_player->xp = 0;
        game[0]->player->stat_player->attack += 10;
        game[0]->player->stat_player->speed_attack += 1;
        game[0]->player->stat_player->defense += 5;
        game[0]->player->stat_player->hp_max += 10;
        game[0]->player->stat_player->chance_criticism += 2;
        print_text_line(game, "Vous etes desormais niveau", \
        int_to_array(game[0]->player->stat_player->level), "");
        sfRenderWindow_display(GAME_WINDOW);
        sfSleep(time_sleep);
    }
}

void lose_fight(game_t **game)
{
    game_over(game);
}

void leave_fight(game_t **game)
{
    sfSoundBuffer *buffer = sfSoundBuffer_createFromFile\
    ("assets/sound/flee.ogg");

    play_sound(buffer);
}