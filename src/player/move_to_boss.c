/*
** EPITECH PROJECT, 2019
** rpg
** File description:
** moves the player to the boss
*/

#include "rpg.h"

void setup_intrect_sprite(game_t **game, int turn)
{
    sfIntRect rect;

    if (turn == 3)
        turn = 0;
    rect.height = GAME_BOSS->rect.height;
    rect.width = GAME_BOSS->rect.width;
    rect.left = GAME_BOSS->rect.left + rect.width * turn;
    rect.top = GAME_BOSS->rect.top;
    sfSprite_setTextureRect(GAME_BOSS->sprite, rect);
}

sfVector2f setup_pos_boss(game_t **game, sfVector2i move, int turn)
{
    sfVector2f pos_boss;
    float rotation = 0;

    pos_boss.y = GAME_PLAYER->pos.y + (move.y * (5 - turn));
    pos_boss.x = GAME_PLAYER->pos.x + (move.x * (5 - turn));
    if (move.x != 0) {
        pos_boss.x = move.x > 0 ? pos_boss.x + (GAME_PLAYER->rect.width * 3) :
            pos_boss.x - (GAME_BOSS->rect.width);
        rotation = move.x > 0 ? 90 : 270;
        pos_boss.y += move.x > 0 ? 0 : GAME_BOSS->rect.height;
    } else if (move.y != 0) {
        pos_boss.y = move.y > 0 ? pos_boss.y + (GAME_PLAYER->rect.height * 3) :
            pos_boss.y - (GAME_BOSS->rect.height);
        rotation = move.y > 0 ? 180 : 0;
        pos_boss.x += move.y > 0 ? GAME_BOSS->rect.width : 0;
    }
    sfSprite_setRotation(GAME_BOSS->sprite, rotation);
    sfSprite_setPosition(GAME_BOSS->sprite, pos_boss);
    return (pos_boss);
}

int move_to_boss(game_t **game, sfVector2i move)
{
    sfTime time_sleep = {200000};

    if (GAME_SCENE->boss == NULL)
        return (A_FAILED);
    sfSprite_setTexture(GAME_BOSS->sprite, GAME_BOSS->texture, sfTrue);
    for (int turn = 0; turn < 5; turn++) {
        sfRenderWindow_clear(GAME_WINDOW, sfBlack);
        display(game);
        setup_intrect_sprite(game, turn);
        setup_pos_boss(game, move, turn);
        sfRenderWindow_drawSprite(GAME_WINDOW, GAME_BOSS->sprite, NULL);
        sfRenderWindow_display(GAME_WINDOW);
        sfSprite_setRotation(GAME_BOSS->sprite, 0);
        sfSleep(time_sleep);
    }
    return (A_SUCCESS);
}

pnj_t *get_pnj(game_t **game, char c)
{
    pnj_t *tmp_pnj = game[0]->pnj;

    for (; tmp_pnj != NULL; tmp_pnj = tmp_pnj->next) {
        if (tmp_pnj->id == c)
            break;
    }
    return (tmp_pnj != NULL ? tmp_pnj : NULL);
}