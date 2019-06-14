/*
** EPITECH PROJECT, 2019
** my rpg
** File description:
** initiate scene
*/

#include <stdio.h>
#include <stdlib.h>
#include "rpg.h"

static int initiate_sprite(int nb, char *buf, scene_t **scene)
{
    if (nb == 4) {
        scene[0]->map = NULL;
        if (load_map(buf, scene) == 84)
            return (84);
        return (0);
    } else if (nb == 3) {
        scene[0]->background = sfTexture_createFromFile(buf, NULL);
        if (scene[0]->background == NULL)
            return (84);
    }
    if (nb == 0) {
        scene[0]->name = NULL;
        if (my_str_to_str(&scene[0]->name, buf) == 84)
            return (84);
    }
    return (0);
}

static int initiate_rect(int nb, char **buf, scene_t **scene)
{
    if (nb == 1) {
        scene[0]->rect.left = my_getnbr(buf[0]);
        scene[0]->rect.top = my_getnbr(buf[1]);
        scene[0]->rect.width = my_getnbr(buf[2]);
        scene[0]->rect.height = my_getnbr(buf[3]);
    } else if (nb == 2) {
        scene[0]->pos.x = my_getnbr(buf[0]);
        scene[0]->pos.y = my_getnbr(buf[1]);
    }
    return (0);
}

static int initiate_manager(int nb, char *buf, scene_t **scene)
{
    char **tab = NULL;

    buf = add_null(buf);
    if (nb == 1 || nb == 2) {
        if (parse_argument(&tab, buf, '-') == 84)
            return (84);
        initiate_rect(nb, tab, scene);
        free_tab(&tab);
    } else {
        if (initiate_sprite(nb, buf, scene) == 84)
            return (84);
    }
    return (0);
}

static int initiate_scene(char *path, scene_t **scene)
{
    FILE *dir = NULL;
    size_t len = 0;
    char *buf = NULL;

    path = add_null(path);
    dir = fopen(path, "r");
    if (dir == NULL)
        return (84);
    for (int i = 0; i < 5; i++) {
        if (getline(&buf, &len, dir) == -1)
            return (84);
        if (initiate_manager(i, buf, scene) == 84)
            return (84);
    }
    free(buf);
    fclose(dir);
    return (0);
}

int initiate_all_scene(game_t **game)
{
    FILE *dir = NULL;
    size_t len = 0;
    ssize_t nread = 0;
    char *buf = NULL;
    int i = 0;

    dir = fopen(PATH_SCENE, "r");
    if (dir == NULL)
        return (84);
    for (nread = getline(&buf, &len, dir); nread != -1 && nread != 0; nread =
        getline(&buf, &len, dir), i++) {
        game[0]->scene[i] = malloc(sizeof(scene_t));
        if (nread == -1 || game[0]->scene[i] == NULL || initiate_scene(buf,
            &game[0]->scene[i]) == 84)
            return (84);
        free_str(&buf);
    }
    game[0]->scene[i] = NULL;
    fclose(dir);
    return (0);
}