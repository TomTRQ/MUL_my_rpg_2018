/*
** EPITECH PROJECT, 2019
** my rpg
** File description:
** display
*/

#include "rpg.h"

int display_button(button_t *button, sfRenderWindow *window)
{
    button_t *a_button = NULL;
    sfVector2i mouse = sfMouse_getPositionRenderWindow(window);
    sfFloatRect rect_button;
    sfColor gold_color = {255, 215, 0, 230};
    sfColor save_color;

    for (a_button = button; a_button != NULL; a_button = a_button->next) {
        rect_button = sfSprite_getGlobalBounds(a_button->sprite);
        if (sfFloatRect_contains(&rect_button, mouse.x, mouse.y) == 0) {
            save_color = sfSprite_getColor(a_button->sprite);
            sfSprite_setColor(a_button->sprite, gold_color);
            sfRenderWindow_drawSprite(window, a_button->sprite, NULL);
            sfSprite_setColor(a_button->sprite, save_color);
        } else
            sfRenderWindow_drawSprite(window, a_button->sprite, NULL);
    }
    return (0);
}

static int display_player(game_t **game, sfRenderWindow *window)
{
    sfSprite_setTexture(GAME_PLAYER->sprite, GAME_PLAYER->texture, sfTrue);
    sfSprite_setTextureRect(GAME_PLAYER->sprite, GAME_PLAYER->rect);
    sfSprite_setPosition(GAME_PLAYER->sprite, GAME_PLAYER->pos);
    if (compare_str(GAME_SCENE->name, "path_water") == 0) {
        draw_boat(game);
        sfRenderWindow_drawSprite(window, GAME_PLAYER->sprite, NULL);
        if (GAME_PLAYER->texture_mount != NULL && is_out_map(GAME_SCENE) == 0)
            sfRenderWindow_drawSprite(window, GAME_PLAYER->mount, NULL);
    } else {
        if (GAME_PLAYER->texture_mount != NULL && is_out_map(GAME_SCENE) == 0)
            sfRenderWindow_drawSprite(window, GAME_PLAYER->mount, NULL);
        sfRenderWindow_drawSprite(window, GAME_PLAYER->sprite, NULL);
    }
    return (0);
}

int display_scene(scene_t *scene, sfRenderWindow *window)
{
    sfSprite *sprite = sfSprite_create();

    if (sprite == NULL)
        return (84);
    sfSprite_setTexture(sprite, scene->background, sfTrue);
    if (is_map(scene) == 0)
        sfSprite_setScale(sprite, ZOOM);
    sfSprite_setTextureRect(sprite, scene->rect);
    sfRenderWindow_drawSprite(window, sprite, NULL);
    sfSprite_destroy(sprite);
    return (0);
}

int display(game_t **game)
{
    display_scene(game[0]->scene[game[0]->scene_nb], GAME_WINDOW);
    if (is_map(GAME_SCENE) == 0) {
        display_player(game, GAME_WINDOW);
        draw_night(game);
    }
    display_inventory(game);
    display_button(game[0]->scene[game[0]->scene_nb]->button, GAME_WINDOW);
    modify_cursor(game);
    return (0);
}