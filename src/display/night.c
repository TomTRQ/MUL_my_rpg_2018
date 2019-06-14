/*
** EPITECH PROJECT, 2019
** rpg
** File description:
** night effects
*/

#include <stdlib.h>
#include <time.h>
#include "rpg.h"

int draw_night(game_t **game)
{
    sfRectangleShape *shape = sfRectangleShape_create();
    sfColor color = {25, 32, 60, 0};
    sfVector2f pos = {WIDTH, HEIGHT};
    int sec_time = GAME_TIME->seconds % 60;
    int val_trans = 0;

    if (GAME_TIME->seconds <= 60 || compare_n_char(GAME_SCENE->name,
        "donjon", 6) == 0 || compare_n_char(GAME_SCENE->name, "house", 5) == 0
        || shape == NULL || sec_time > 30)
        return (0);
    if (sec_time >= 0 && sec_time < 15)
        val_trans = 80 + sec_time * 8;
    else if (sec_time >= 15 && sec_time < 30)
        val_trans = 200 - (sec_time % 15) * 8;
    color.a = (sfUint8)(val_trans % 201);
    sfRectangleShape_setSize(shape, pos);
    sfRectangleShape_setFillColor(shape, color);
    sfRenderWindow_drawRectangleShape(GAME_WINDOW, shape, NULL);
    sfRectangleShape_destroy(shape);
    return (0);
}