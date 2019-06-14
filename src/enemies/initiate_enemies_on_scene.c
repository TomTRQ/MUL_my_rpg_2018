/*
** EPITECH PROJECT, 2019
** rpg
** File description:
** initiate enemies
*/

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "rpg.h"

void setup_intrect_boss(scene_t *scene, int nb)
{
    int intrect[4][4] = {{0, 90, 95, 90}, {193, 190, 98, 99}, {120, 0, 120,
        120}, {120, 240, 210, 120}};

    scene->boss->rect.left = intrect[nb][0];
    scene->boss->rect.top = intrect[nb][1];
    scene->boss->rect.width = intrect[nb][2];
    scene->boss->rect.height = intrect[nb][3];
}

int initiate_boss_on_scene(scene_t *scene, enemy_t *temp)
{
    if (compare_str(temp->name, "forest_boss") == 0) {
        scene->boss = temp;
        setup_intrect_boss(scene, 0);
        return (1);
    } else if (compare_str(temp->name, "mine_boss") == 0) {
        scene->boss = temp;
        setup_intrect_boss(scene, 1);
        return (1);
    }
    if (compare_str(temp->name, "water_boss") == 0) {
        scene->boss = temp;
        setup_intrect_boss(scene, 2);
        return (1);
    } else if (compare_str(temp->name, "final_boss") == 0) {
        scene->boss = temp;
        setup_intrect_boss(scene, 3);
        return (1);
    }
    return (0);
}

int add_enemy_on_scene(scene_t *scene, enemy_t *enemy)
{
    enemy_t *temp = enemy;
    enemy_t *new = malloc(sizeof(enemy_t));

    if (new == NULL)
        return (84);
    new->next = NULL;
    scene->enemy = new;
    while (temp != NULL) {
        if (compare_str(scene->name, temp->map) == 0 && \
        initiate_boss_on_scene(scene, temp) == 0) {
            scene->enemy = temp;
        }
        temp = temp->next;
    }
    return (0);
}

int initiate_enemies_on_scene(game_t **game)
{
    int count = 0;

    while (game[0]->scene[count] != NULL) {
        if (add_enemy_on_scene\
        (game[0]->scene[count], game[0]->enemy) == 84)
            return (84);
        count = count + 1;
    }
    return (0);
}