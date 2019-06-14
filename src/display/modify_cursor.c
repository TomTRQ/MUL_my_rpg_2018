/*
** EPITECH PROJECT, 2019
** file that modifies the cursor of the mouse
** File description:
** my_rpg
*/

#include "rpg.h"

void modify_cursor(game_t **game)
{
    sfSprite *sprite = sfSprite_create();
    sfTexture *texture = sfTexture_createFromFile\
    ("assets/mouse/mouse.png", NULL);
    sfVector2f pos = {sfMouse_getPositionRenderWindow(GAME_WINDOW).x - 45,\
    sfMouse_getPositionRenderWindow(GAME_WINDOW).y - 35};

    sfRenderWindow_setMouseCursorVisible(GAME_WINDOW, 0);
    sfSprite_setTexture(sprite, texture, sfTrue);
    sfSprite_setPosition(sprite, pos);
    sfRenderWindow_drawSprite(GAME_WINDOW, sprite, NULL);
    sfSprite_destroy(sprite);
    sfTexture_destroy(texture);
}