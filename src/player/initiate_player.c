/*
** EPITECH PROJECT, 2019
** rpg
** File description:
** initiate the player
*/

#include <stdlib.h>
#include "rpg.h"

stat_player_t *initiate_stat(void)
{
    stat_player_t *stat_player = malloc(sizeof(stat_player_t));

    if (stat_player == NULL)
        return (NULL);
    stat_player->hp = PLAYER_HP;
    stat_player->hp_max = PLAYER_HP;
    stat_player->defense = 30;
    stat_player->attack = PLAYER_DMG;
    stat_player->speed_attack = 20;
    stat_player->chance_criticism = 2;
    stat_player->chance_escape = 1;
    stat_player->xp = 0;
    stat_player->xp_max = 200;
    stat_player->level = 1;
    return (stat_player);
}

player_t *initiate_player_graphic(player_t *player)
{
    player->sprite = sfSprite_create();
    if (player->sprite == NULL)
        return (NULL);
    player->texture = sfTexture_createFromFile("assets/player/knight.png",
        NULL);
    if (player->texture == NULL)
        return (NULL);
    player->texture_mount = NULL;
    player->mount = sfSprite_create();
    if (player->mount == NULL)
        return (NULL);
    player->texture_mount = NULL;
    return (player);
}

player_t *initiate_player(void)
{
    player_t *player = malloc(sizeof(player_t));

    if (player == NULL)
        return (NULL);
    player = initiate_player_graphic(player);
    if (player == NULL)
        return (NULL);
    player->pos.x = 550;
    player->pos.y = 350;
    player->rect.left = 292;
    player->rect.top = 192;
    player->rect.width = 48;
    player->rect.height = 48;
    player->name = NULL;
    player->stat_player = initiate_stat();
    player->inventory = set_inventory();
    return (player);
}