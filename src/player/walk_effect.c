/*
** EPITECH PROJECT, 2019
** rpg
** File description:
** snow
*/

#include <stdlib.h>
#include <time.h>
#include "rpg.h"

sfUint8 *create_random_pixel(sfColor color)
{
    int len_max = (20 * 4);
    sfUint8 *pixels = malloc(sizeof(sfUint8) * len_max);
    int random = rand() % 16;

    if (pixels == NULL)
        return (NULL);
    for (int i = 0; i < 20; i++) {
        pixels[i * 4] = color.r;
        pixels[i * 4 + 1] = color.g;
        pixels[i * 4 + 2] = color.b;
        if (i > random && i < random + 4)
            pixels[i * 4 + 3] = 250;
        else
            pixels[i * 4 + 3] = 0;
    }
    return (pixels);
}

sfVector2f setup_position(game_t **game, int nb)
{
    sfVector2f pos = {0, 0};

    pos.x = GAME_PLAYER->pos.x + 9;
    pos.y = GAME_PLAYER->pos.y;
    if (nb == RIGHT) {
        pos.x = pos.x - 19;
        pos.y = pos.y + 28;
    } else if (nb == TOP) {
        pos.x = pos.x + 5;
        pos.y = pos.y + 49;
    }
    if (nb == LEFT) {
        pos.x = pos.x + 29;
        pos.y = pos.y + 28;
    }
    return (pos);
}

void draw_walk_effect(game_t **game, int nb)
{
    sfColor walk = {147, 100, 58, 250};
    sfVector2f pos;
    sfUint8 *pixels = NULL;

    if (GAME_PLAYER->texture_mount != NULL)
        sfTexture_destroy(GAME_PLAYER->texture_mount);
    GAME_PLAYER->texture_mount = sfTexture_create(20, 20);
    for (int i = 0; i < 20; i += 4) {
        pixels = create_random_pixel(walk);
        for (int j = 0; j < 4; j++)
            sfTexture_updateFromPixels(GAME_PLAYER->texture_mount, pixels,
                20, 1, 0, i + j);
    }
    pos = setup_position(game, nb);
    sfSprite_setTexture(GAME_PLAYER->mount, GAME_PLAYER->texture_mount, sfTrue);
    sfSprite_setPosition(GAME_PLAYER->mount, pos);
    if (pixels != NULL)
        free(pixels);
}