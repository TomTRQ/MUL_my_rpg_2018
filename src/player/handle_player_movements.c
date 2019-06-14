/*
** EPITECH PROJECT, 2019
** file used to move the player sprite
** File description:
** my_rpg
*/

#include <stdlib.h>
#include "rpg.h"

int player_moving_right(game_t **game)
{
    static int nb = 0;
    int val;
    sfVector2i movement = {SPEED, 0};

    val = setup_position_to_check(GAME_SCENE, movement, game);
    if (val != CAN_MOVE)
        return (val);
    GAME_PLAYER->rect.top = 292;
    GAME_PLAYER->rect.height = 47;
    player_movement_right(game);
    if (GAME_TIME->milli / 15 != nb)
        GAME_PLAYER->rect.left += 50;
    if (GAME_PLAYER->rect.left >= 390)
        GAME_PLAYER->rect.left = 285;
    nb = GAME_TIME->milli / 15;
    game[0]->enemy_spawn = rand() % ENEMY_SPAWN;
    return (A_SUCCESS);
}

int player_moving_left(game_t **game)
{
    static int nb = 0;
    int val;
    sfVector2i movement = {-SPEED, 0};

    val = setup_position_to_check(GAME_SCENE, movement, game);
    if (val != CAN_MOVE)
        return (val);
    GAME_PLAYER->rect.top = 242;
    GAME_PLAYER->rect.height = 47;
    player_movement_left(game);
    if (GAME_TIME->milli / 15 != nb)
        GAME_PLAYER->rect.left += 50;
    if (GAME_PLAYER->rect.left >= 390)
        GAME_PLAYER->rect.left = 285;
    nb = GAME_TIME->milli / 15;
    game[0]->enemy_spawn = rand() % ENEMY_SPAWN;
    return (A_SUCCESS);
}

int player_moving_up(game_t **game)
{
    static int nb = 0;
    sfVector2i movement = {0, -SPEED};
    int val;

    val = setup_position_to_check(GAME_SCENE, movement, game);
    if (val != CAN_MOVE)
        return (val);
    GAME_PLAYER->rect.top = 338;
    GAME_PLAYER->rect.height = 50;
    player_movement_up(game);
    if (GAME_TIME->milli / 15 != nb)
        GAME_PLAYER->rect.left += 50;
    if (GAME_PLAYER->rect.left >= 390)
        GAME_PLAYER->rect.left = 285;
    nb = GAME_TIME->milli / 15;
    game[0]->enemy_spawn = rand() % ENEMY_SPAWN;
    return (A_SUCCESS);
}

int player_moving_down(game_t **game)
{
    static int nb = 0;
    sfVector2i movement = {0, SPEED};
    int val = 0;

    val = setup_position_to_check(GAME_SCENE, movement, game);
    if (val != CAN_MOVE)
        return (val);
    GAME_PLAYER->rect.top = 192;
    GAME_PLAYER->rect.height = 50;
    player_movement_down(game);
    if (GAME_TIME->milli / 15 != nb)
        GAME_PLAYER->rect.left += 50;
    if (GAME_PLAYER->rect.left >= 390)
        GAME_PLAYER->rect.left = 285;
    nb = GAME_TIME->milli / 15;
    game[0]->enemy_spawn = rand() % ENEMY_SPAWN;
    return (A_SUCCESS);
}

int handle_player_movements(game_t **game)
{
    int val = A_SUCCESS;

    if (GAME_EVENT.key.code == sfKeyLeft) {
        val = player_moving_left(game);
    } else if (GAME_EVENT.key.code == sfKeyRight) {
        val = player_moving_right(game);
        return (val);
    }
    if (GAME_EVENT.key.code == sfKeyUp) {
        val = player_moving_up(game);
        return (val);
    } else if (GAME_EVENT.key.code == sfKeyDown) {
        val = player_moving_down(game);
        return (val);
    }
    return (val);
}