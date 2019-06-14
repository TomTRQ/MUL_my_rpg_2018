/*
** EPITECH PROJECT, 2019
** my rpg
** File description:
** initiate button
*/

#include <stdio.h>
#include <stdlib.h>
#include "rpg.h"

static int (*BUTTON[5])(game_t **game) = {change_volume, start_game,
    exit_game, pause_game, menu_game};

int setup_sprite_button(char **tab, button_t **button)
{
    sfTexture *texture;
    sfVector2f pos = {my_getnbr(tab[0]), my_getnbr(tab[1])};

    if (compare_str(tab[2], "True") == 0)
        texture = sfTexture_createFromFile(tab[7], &button[0]->rect);
    else
        texture = sfTexture_createFromFile(tab[7], NULL);
    button[0]->sprite = sfSprite_create();
    if (button[0]->sprite == NULL || texture == NULL)
        return (84);
    if (compare_str(tab[2], "True") == 0) {
        sfSprite_setTexture(button[0]->sprite, texture, sfFalse);
    } else {
        sfSprite_setTexture(button[0]->sprite, texture, sfTrue);
        sfSprite_setTextureRect(button[0]->sprite, button[0]->rect);
    }
    sfSprite_setPosition(button[0]->sprite, pos);
    return (0);
}

int setup_callback_rect(char **tab, button_t **button)
{
    char str[5][14] = {"change_volume", "start_game", "exit_game",
        "pause_game", "menu_game"};
    sfIntRect rect = {my_getnbr(tab[3]), my_getnbr(tab[4]), my_getnbr(tab[5]),
        my_getnbr(tab[6])};
    int i = 0;

    button[0]->rect = rect;
    for (; i < 5; i++)
        if (compare_str(str[i], tab[8]) == 0)
            break;
    if (i == 5)
        return (84);
    button[0]->callback = BUTTON[i];
    button[0]->name = NULL;
    if (my_str_to_str(&button[0]->name, tab[8]) == 84)
        return (84);
    return (0);
}

int setup_button(char *buf, scene_t **scene)
{
    char **tab = NULL;
    button_t *button = NULL;

    buf = add_null(buf);
    if (parse_argument(&tab, buf, '-') == 84)
        return (84);
    button = malloc(sizeof(button_t));
    if (button == NULL)
        return (84);
    if (setup_callback_rect(tab, &button) == 84)
        return (84);
    if (setup_sprite_button(tab, &button) == 84)
        return (84);
    button->next = scene[0]->button;
    scene[0]->button = button;
    free_tab(&tab);
    return (0);
}

int initiate_button(char *path, scene_t **scene)
{
    FILE *dir = NULL;
    size_t len = 0;
    ssize_t nread = 0;
    char *buf = NULL;

    path = add_null(path);
    dir = fopen(path, "r");
    if (dir == NULL)
        return (84);
    scene[0]->button = NULL;
    for (nread = getline(&buf, &len, dir); nread != -1 && nread != 0; nread =
        getline(&buf,
        &len, dir)) {
        if (nread == -1 || setup_button(buf, scene) == 84)
            return (84);
        free_str(&buf);
    }
    fclose(dir);
    return (0);
}

int initiate_all_button(game_t **game)
{
    FILE *dir = NULL;
    size_t len = 0;
    ssize_t nread = 0;
    char *buf = NULL;
    int i = 0;

    dir = fopen(PATH_BUTTON, "r");
    if (dir == NULL)
        return (84);
    for (nread = getline(&buf, &len, dir); nread != -1 && nread != 0; nread =
        getline(&buf, &len, dir), i++) {
        if (nread == -1 || initiate_button(buf, &game[0]->scene[i]) == 84)
            return (84);
        free_str(&buf);
    }
    fclose(dir);
    return (0);
}