/*
** EPITECH PROJECT, 2019
** main file of the project
** File description:
** my_rpg
*/

#include <unistd.h>
#include <stdlib.h>
#include "rpg.h"

void destroy_sprite(sfSprite *sprite)
{
    if (sprite == NULL)
        return;
    else
        sfSprite_destroy(sprite);
}

void destroy_texture(sfTexture *texture)
{
    if (texture == NULL)
        return;
    else
        sfTexture_destroy(texture);
}

void destroy_scenes(scene_t *scene)
{
    if (scene->name != NULL)
        free (scene->name);
    for (int a = 0; scene->map[a] != NULL; a++)
        free (scene->map[a]);
    free (scene->map);
    destroy_texture(scene->background);
    free(scene->enemy);
    free(scene->button);
    free(scene);
}

void destroy_free_all(game_t **game)
{
    destroy_sprite(game[0]->player->sprite);
    destroy_texture(game[0]->player->texture);
    free (game[0]->player->stat_player);
    sfClock_destroy(game[0]->time->clock);
    free(game[0]->time);
    free(game[0]->player);
    for (int a = 0; game[0]->scene[a] != NULL; a++)
        destroy_scenes(game[0]->scene[a]);
    destroy_music(game);
    sfRenderWindow_close(GAME_WINDOW);
    sfRenderWindow_destroy(GAME_WINDOW);
    write(1, "Exit game   <-\n", 15);
}