/*
** EPITECH PROJECT, 2019
** my rpg
** File description:
** change scene - effect
*/

#include <unistd.h>
#include "rpg.h"

int change_map_black(game_t **game)
{
    sfRectangleShape *shape = sfRectangleShape_create();
    sfColor color = sfBlack;
    sfVector2f pos = {WIDTH, HEIGHT};
    sfUint8 val = 100;
    sfTime sleep_time = {600};

    if (shape == NULL)
        return (84);
    for (int nb = 100; nb < 255; nb+=10, val+=10) {
        color.a = val;
        sfRenderWindow_clear(GAME_WINDOW, sfBlack);
        display(game);
        sfRectangleShape_setSize(shape, pos);
        sfRectangleShape_setFillColor(shape, color);
        sfRenderWindow_drawRectangleShape(GAME_WINDOW, shape, NULL);
        sfRenderWindow_display(GAME_WINDOW);
        sfSleep(sleep_time);
    }
    sfRectangleShape_destroy(shape);
    return (0);
}

int change_map_light(game_t **game)
{
    sfRectangleShape *shape = sfRectangleShape_create();
    sfColor color = sfBlack;
    sfVector2f pos = {WIDTH, HEIGHT};
    sfUint8 val = 255;
    sfTime sleep_time = {600};

    if (shape == NULL)
        return (84);
    for (int nb = 255; nb > 100; nb-=10, val-=10) {
        color.a = val;
        sfRenderWindow_clear(GAME_WINDOW, sfBlack);
        display(game);
        sfRectangleShape_setSize(shape, pos);
        sfRectangleShape_setFillColor(shape, color);
        sfRenderWindow_drawRectangleShape(GAME_WINDOW, shape, NULL);
        sfRenderWindow_display(GAME_WINDOW);
        sfSleep(sleep_time);
    }
    sfRectangleShape_destroy(shape);
    return (0);
}

int change_scene(game_t **game, char *new_scene)
{
    int i = 0;

    GAME_SCENE->pos.x = GAME_PLAYER->pos.x;
    GAME_SCENE->pos.y = GAME_PLAYER->pos.y;
    for (; game[0]->scene[i] != NULL && compare_str(game[0]->scene[i]->name,
        new_scene) != 0; i++);
    if (change_map_black(game) == 84)
        return (84);
    game[0]->scene_nb = i;
    GAME_PLAYER->pos.x = GAME_SCENE->pos.x;
    GAME_PLAYER->pos.y = GAME_SCENE->pos.y;
    if (change_map_light(game) == 84)
        return (84);
    while (sfRenderWindow_pollEvent(GAME_WINDOW, &GAME_EVENT));
    return (0);
}