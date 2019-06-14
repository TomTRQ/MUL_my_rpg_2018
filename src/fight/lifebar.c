/*
** EPITECH PROJECT, 2019
** my rpg
** File description:
** display
*/

#include "rpg.h"

void fight_lifebar(sfRenderWindow *window, sfVector2f vector, \
int max_hp, int hp)
{
    sfRectangleShape *red = sfRectangleShape_create();
    sfRectangleShape *black = sfRectangleShape_create();
    sfVector2f size = {300, 12};
    sfVector2f pos = {vector.x + 10, vector.y - 10};

    sfRectangleShape_setSize(black, size);
    size.x = hp * 300 / max_hp;
    sfRectangleShape_setSize(red, size);
    sfRectangleShape_setPosition(black, pos);
    sfRectangleShape_setPosition(red, pos);
    sfRectangleShape_setFillColor(red, sfRed);
    sfRectangleShape_setFillColor(black, sfBlack);
    sfRectangleShape_setOutlineColor(black, sfBlack);
    sfRenderWindow_drawRectangleShape(window, black, NULL);
    sfRenderWindow_drawRectangleShape(window, red, NULL);
    sfRectangleShape_destroy(red);
    sfRectangleShape_destroy(black);
}