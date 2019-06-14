/*
** EPITECH PROJECT, 2019
** rpg
** File description:
** display boat
*/

#include <stdlib.h>
#include "rpg.h"

sfUint8 *create_line(sfColor color, int width)
{
    int len_max = (width * 1 * 4);
    sfUint8 *pixels = malloc(sizeof(sfUint8) * len_max);

    if (pixels == NULL)
        return (NULL);
    for (int i = 0; i < width; i++) {
        pixels[i * 4] = color.r;
        pixels[i * 4 + 1] = color.g;
        pixels[i * 4 + 2] = color.b;
        pixels[i * 4 + 3] = 255;
    }
    return (pixels);
}

sfColor setup_color(int r, int g, int b)
{
    sfColor color = {0, 0, 0, 250};

    color.r = (sfUint8) r;
    color.g = (sfUint8) g;
    color.b = (sfUint8) b;
    return (color);
}

void setup_texture_on_sprite(game_t **game)
{
    sfVector2f pos = {0, 0};

    pos.x = GAME_PLAYER->pos.x;
    pos.y = GAME_PLAYER->pos.y + 40;

    sfSprite_setTexture(GAME_PLAYER->mount, GAME_PLAYER->texture_mount, sfTrue);
    sfSprite_setPosition(GAME_PLAYER->mount, pos);
}

void draw_boat(game_t **game)
{
    sfColor color = {235, 152, 78, 250};
    sfUint8 *pixels = NULL;

    if (GAME_PLAYER->texture_mount != NULL)
        sfTexture_destroy(GAME_PLAYER->texture_mount);
    GAME_PLAYER->texture_mount = sfTexture_create(48, 10);
    pixels = create_line(color, 48);
    sfTexture_updateFromPixels(GAME_PLAYER->texture_mount, pixels, 48, 1, 0, 0);
    sfTexture_updateFromPixels(GAME_PLAYER->texture_mount, pixels, 48, 1, 0, 1);
    color = setup_color(156, 100, 12);
    pixels = create_line(color, 44);
    for (int i = 2; i < 10; i +=2) {
        sfTexture_updateFromPixels(GAME_PLAYER->texture_mount, pixels,
            (48 - i * 2), 1, i, i);
        sfTexture_updateFromPixels(GAME_PLAYER->texture_mount, pixels,
            (48 - i * 2), 1, i, i + 1);
    }
    setup_texture_on_sprite(game);
}