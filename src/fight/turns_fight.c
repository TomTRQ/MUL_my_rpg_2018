/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** fight action funcs
*/

#include "rpg.h"
#include <stdio.h>

int enemy_turn(game_t **game, enemy_t *enemy, player_t *player, int def)
{
    sfTime time_sleep = {1000000};

    sfSleep(time_sleep);
    if (def == 4) {
        enemy->stat->hp -= player->stat_player->attack /
                                (enemy->stat->defense / 2) + 2;
        player->stat_player->hp -= enemy->stat->attack /
                                (player->stat_player->defense / 5) + 2;
        anim_enemy_atk(game, enemy);
        anim_player_atk(game, enemy);
    } else {
        player->stat_player->hp -= (enemy->stat->attack * 2) /
        (player->stat_player->defense / 5) + 2;
        anim_enemy_atk(game, enemy);
    }
    if (player->stat_player->hp <= 0)
        return (LOSE);
    return (0);
}

static int is_button(sfVector2i mpos)
{
    if (sfMouse_isButtonPressed(sfMouseLeft)) {
        if (mpos.x > 285 && mpos.x < 475 && mpos.y > 640 && mpos.y < 715) {
                return (1);
        }
        if (mpos.x > 475 && mpos.x < 685 && mpos.y > 640 && mpos.y < 715) {
            if (sfMouse_isButtonPressed(sfMouseLeft))
                return (2);
        }
        if (mpos.x > 685 && mpos.x < 827 && mpos.y > 640 && mpos.y < 715) {
            if (sfMouse_isButtonPressed(sfMouseLeft))
                return (3);
        }
        if (mpos.x > 827 && mpos.x < 927 && mpos.y > 640 && mpos.y < 715) {
            if (sfMouse_isButtonPressed(sfMouseLeft))
                return (4);
        }
    }
    return (0);
}

static int select_fight_menu(game_t **game, enemy_t *enemy)
{
    int choice = 0;
    sfVector2i mpos;

    while (1) {
        mpos = sfMouse_getPositionRenderWindow(GAME_WINDOW);
        display_fight(GAME_PLAYER, enemy, GAME_SCENE, game);
        choice = is_button(mpos);
        if (choice != 0)
            return (choice);
    }
}

int player_turn(game_t **game, enemy_t *enemy)
{
    int choice = 0;

    choice = select_fight_menu(game, enemy);
    switch (choice) {
        case 1:
            enemy->stat->hp -= (GAME_PLAYER->stat_player->attack * 2) /
                (enemy->stat->defense / 5) + 2;
            anim_player_atk(game, enemy);
            break;
        case 2:
            return (CONTRE);
        case 3:
            return (player_turn(game, enemy));
        case 4:
            return (RUN);
        default:
            break;
    }
    if (enemy->stat->hp <= 0)
        return (WIN);
    return (0);
}