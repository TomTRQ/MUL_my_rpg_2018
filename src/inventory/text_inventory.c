/*
** EPITECH PROJECT, 2019
** inventory.c
** File description:
** my_rpg
*/

#include "rpg.h"
#include <stdio.h>
#include <stdlib.h>

int display_text(sfText *text, game_t **game, sfVector2f coord, int len)
{
    sfFont *font;

    font = sfFont_createFromFile("assets/text/dialog.ttf");
    if (!font)
        return (EXIT_FAILURE);
    sfText_setFont(text, font);
    sfText_setPosition(text, coord);
    sfText_setCharacterSize(text, len);
    sfText_setColor(text, sfBlack);
    sfRenderWindow_drawText(GAME_WINDOW, text, NULL);
    sfFont_destroy(font);
    return (EXIT_SUCCESS);
}

static int display_bottom_left_corner(sfText *text, game_t **game,
    sfVector2f coord)
{
    if (display_attack(text, game, coord) == EXIT_FAILURE)
        return (EXIT_FAILURE);
    if (display_speed_attack(text, game, coord) == EXIT_FAILURE)
        return (EXIT_FAILURE);
    if (display_chance_criticism(text, game, coord) == EXIT_FAILURE)
        return (EXIT_FAILURE);
    if (display_chance_escape(text, game, coord) == EXIT_FAILURE)
        return (EXIT_FAILURE);
    if (display_def(text, game, coord) == EXIT_FAILURE)
        return (EXIT_FAILURE);
    return (EXIT_SUCCESS);
}

static int display_head(sfText *text, game_t **game,
    sfVector2f coord)
{
    display_name(text, game, coord);
    if (display_level(text, game, coord) == EXIT_FAILURE)
        return (EXIT_FAILURE);
    if (display_xp(text, game, coord) == EXIT_FAILURE)
        return (EXIT_FAILURE);
    display_hp(text, game, coord);
    return (EXIT_SUCCESS);
}

int display_text_inventory(sfText *text, game_t **game)
{
    sfVector2f coord;

    display_head(text, game, coord);
    display_bottom_left_corner(text, game, coord);
    return (EXIT_SUCCESS);
}

int set_text_inventory(game_t **game)
{
    sfText *text;

    text = sfText_create();
    display_text_inventory(text, game);
    sfText_destroy(text);
    return (EXIT_SUCCESS);
}