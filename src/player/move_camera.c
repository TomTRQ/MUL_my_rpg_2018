/*
** EPITECH PROJECT, 2019
** file that moves the camera
** File description:
** my_rpg
*/

#include "rpg.h"

void player_movement_left(game_t **game)
{
    if (GAME_SCENE->rect.left - SPEED < 0)
        GAME_PLAYER->pos.x -= SPEED;
    else if (GAME_PLAYER->pos.x > (WIDTH / 2))
        GAME_PLAYER->pos.x -= SPEED;
    else
        GAME_SCENE->rect.left -= SPEED;
    draw_walk_effect(game, LEFT);
}

void player_movement_right(game_t **game)
{
    sfVector2u len = sfTexture_getSize(GAME_SCENE->background);
    int val = GAME_SCENE->rect.left + WIDTH / 2;

    if (val >= (int)len.x)
        GAME_PLAYER->pos.x += SPEED;
    else if (GAME_PLAYER->pos.x < (WIDTH / 2))
        GAME_PLAYER->pos.x += SPEED;
    else
        GAME_SCENE->rect.left += SPEED;
    draw_walk_effect(game, RIGHT);
}

void player_movement_up(game_t **game)
{
    if (GAME_SCENE->rect.top - SPEED < 0)
        GAME_PLAYER->pos.y -= SPEED;
    else if (GAME_PLAYER->pos.y > (HEIGHT / 2))
        GAME_PLAYER->pos.y -= SPEED;
    else
        GAME_SCENE->rect.top -= SPEED;
    draw_walk_effect(game, TOP);
}

void player_movement_down(game_t **game)
{
    sfVector2u len = sfTexture_getSize(GAME_SCENE->background);
    int val = GAME_SCENE->rect.top + HEIGHT / 2;

    if (val >= (int)len.y)
        GAME_PLAYER->pos.y += SPEED;
    else if (GAME_PLAYER->pos.y < (HEIGHT / 2))
        GAME_PLAYER->pos.y += SPEED;
    else
        GAME_SCENE->rect.top += SPEED;
    draw_walk_effect(game, 0);
}
