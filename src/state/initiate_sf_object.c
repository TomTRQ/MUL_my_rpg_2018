/*
** EPITECH PROJECT, 2019
** my rpg
** File description:
** initiate sf object struct
*/

#include <stdlib.h>
#include "rpg.h"

int initiate_sf_object(game_t **game)
{
    sfVideoMode video_mode;

    video_mode.width = WIDTH;
    video_mode.height = HEIGHT;
    video_mode.bitsPerPixel = BITS_PIXELS;
    game[0]->sf_obj = malloc(sizeof(sf_obj_t));
    if (game[0]->sf_obj == NULL)
        return (84);
    game[0]->sf_obj->window = sfRenderWindow_create(video_mode, "Tek Quest IV",
        sfClose, NULL);
    if (game[0]->sf_obj->window == NULL)
        return (84);
    sfRenderWindow_setFramerateLimit(game[0]->sf_obj->window, 120);
    return (0);
}