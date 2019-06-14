/*
** EPITECH PROJECT, 2019
** inventory.c
** File description:
** my_rpg
*/

#include "rpg.h"
#include <stdio.h>
#include <stdlib.h>

int modif_inventory_stack(game_t **game, int id)
{
    GAME_INVENTORY[id].nb_stack += 1;
    return (EXIT_SUCCESS);
}

int display_const_inventory(game_t **game)
{
    if (set_text_inventory(game) == EXIT_FAILURE)
        return (EXIT_FAILURE);
    return (EXIT_SUCCESS);
}

int display_obj_inventory(int i, int len, game_t **game)
{
    if (len % 6 != 0)
        GAME_INVENTORY[i].vector.x = len * 20 + 200;
    else
        GAME_INVENTORY[i].vector.x = 200;
    if (len / 6 < 1)
        GAME_INVENTORY[i].vector.y = 200;
    else
        GAME_INVENTORY[i].vector.y = 300;
    GAME_INVENTORY[i].texture = \
    sfTexture_createFromFile(GAME_INVENTORY[i].param_player, NULL);
    sfSprite_setTexture(GAME_INVENTORY[i].sprite, GAME_INVENTORY[i].texture,
        sfFalse);
    sfRenderWindow_drawSprite(GAME_WINDOW, GAME_INVENTORY[i].sprite, NULL);
    sfSprite_destroy(GAME_INVENTORY[i].sprite);
    sfTexture_destroy(GAME_INVENTORY[i].texture);
    return (EXIT_SUCCESS);
}

int choose_obj_display(game_t **game)
{
    for (int i = 0, len = 0; i < NB_ITEMS; i++) {
        if (GAME_INVENTORY[i].nb_stack > 0) {
            display_obj_inventory(i, len, game);
            len++;
        }
    }
    return (EXIT_SUCCESS);
}

int display_inventory(game_t **game)
{
    if (compare_str(GAME_SCENE->name, "inventory") == 0) {
        display_const_inventory(game);
        choose_obj_display(game);
    }
    return (EXIT_SUCCESS);
}