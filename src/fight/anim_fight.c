/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** animations for fight
*/

#include "rpg.h"

void anim_enemy_atk(game_t **game, enemy_t *enemy)
{
    int i = 0;
    sfVector2f slash = {850, 50};
    sfSoundBuffer *buffer = sfSoundBuffer_createFromFile\
    ("assets/sound/attack.ogg");

    while (i < 150) {
        i += 30;
        enemy->vector.x += i;
        sfSprite_setPosition(enemy->sprite, enemy->vector);
        display_fight(GAME_PLAYER, enemy, GAME_SCENE, game);
    }
    play_sound(buffer);
    enemy->vector.x = 150;
    sfSprite_setPosition(enemy->sprite, enemy->vector);
    display_fight(GAME_PLAYER, enemy, GAME_SCENE, game);
    print_damage(game, slash, enemy->stat->attack /
                (GAME_PLAYER->stat_player->defense / 5) + 2);
    display_fight(GAME_PLAYER, enemy, GAME_SCENE, game);
}

void anim_player_atk(game_t **game, enemy_t *enemy)
{
    int i = 0;
    sfVector2f slash = {150, 50};
    sfSoundBuffer *buffer = sfSoundBuffer_createFromFile\
    ("assets/sound/attack.ogg");

    while (i < 150) {
        i += 30;
        GAME_PLAYER->pos.x -= i;
        sfSprite_setPosition(GAME_PLAYER->sprite, GAME_PLAYER->pos);
        display_fight(GAME_PLAYER, enemy, GAME_SCENE, game);
    }
    play_sound(buffer);
    for (i = 0; i < 150;) {
        i += 30;
        GAME_PLAYER->pos.x += i;
        sfSprite_setPosition(GAME_PLAYER->sprite, GAME_PLAYER->pos);
        display_fight(GAME_PLAYER, enemy, GAME_SCENE, game);
    }
    print_damage(game, slash, (GAME_PLAYER->stat_player->attack * 2) /
                (enemy->stat->defense / 5) + 2);
    display_fight(GAME_PLAYER, enemy, GAME_SCENE, game);
}

player_t *init_player_fight(player_t *player)
{
    player->pos.x = 850;
    player->pos.y = 300;
    sfTexture *pl_texture;
    pl_texture = sfTexture_createFromFile("assets/player/player.png", NULL);

    sfSprite_setTexture(player->sprite, pl_texture, sfTrue);
    sfSprite_setPosition(player->sprite, player->pos);
    return (player);
}

enemy_t *init_enemy_fight(enemy_t *enemy)
{
    enemy->vector.x = 150;
    enemy->vector.y = 200;

    sfSprite_setTexture(enemy->sprite, enemy->fight_t, sfTrue);
    sfSprite_setPosition(enemy->sprite, enemy->vector);
    return (enemy);
}