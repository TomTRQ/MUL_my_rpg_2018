/*
** EPITECH PROJECT, 2019
** my rpg
** File description:
** load the map
*/

#include <stdio.h>
#include <stdlib.h>
#include "rpg.h"

int take_size(char *buf, scene_t **scene, int *len)
{
    int lenght = 0;

    buf = add_null(buf);
    lenght = my_getnbr(buf);
    scene[0]->map = malloc(sizeof(char *) * (lenght + 1));
    if (scene[0]->map == NULL)
        return (84);
    for (int i = 0; i <= lenght; i++)
        scene[0]->map[i] = NULL;
    *len = lenght;
    return (0);
}

int load_map(char *path, scene_t **scene)
{
    FILE *dir = NULL;
    size_t len = 0;
    ssize_t nread = 0;
    int lenght = 0;
    char *buf = NULL;

    dir = fopen(path, "r");
    nread = getline(&buf, &len, dir);
    if (nread == -1)
        return (84);
    if (take_size(buf, scene, &lenght) == 84)
        return (84);
    for (int i = 0; i < lenght; i++) {
        nread = getline(&scene[0]->map[i], &len, dir);
        if (nread == -1)
            return (84);
        scene[0]->map[i] = add_null(scene[0]->map[i]);
    }
    return (0);
}