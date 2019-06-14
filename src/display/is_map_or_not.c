/*
** EPITECH PROJECT, 2019
** my rpg
** File description:
** display
*/

#include "rpg.h"

int is_map(scene_t *scene)
{
    if (compare_str(scene->name, "menu") == A_SUCCESS)
        return (A_FAILED);
    if (compare_str(scene->name, "pause") == A_SUCCESS)
        return (A_FAILED);
    if (compare_str(scene->name, "inventory") == A_SUCCESS)
        return (A_FAILED);
    if (compare_str(scene->name, "fight") == A_SUCCESS)
        return (A_FAILED);
    return (A_SUCCESS);
}

int is_out_map(scene_t *scene)
{
    if (is_map(scene) == A_FAILED)
        return (A_FAILED);
    if (compare_n_char(scene->name, "house", 5) == A_SUCCESS)
        return (A_FAILED);
    if (compare_n_char(scene->name, "donjon", 6) == A_SUCCESS)
        return (A_FAILED);
    return (A_SUCCESS);
}

int is_fight_scene(scene_t *scene)
{
    if (is_map(scene) == A_FAILED)
        return (A_FAILED);
    if (compare_n_char(scene->name, "house", 5) == A_SUCCESS)
        return (A_FAILED);
    if (compare_str(scene->name, "village") == A_SUCCESS)
        return (A_FAILED);
    return (A_SUCCESS);
}