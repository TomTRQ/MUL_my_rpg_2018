/*
** EPITECH PROJECT, 2019
** struct inventory file for the project
** File description:
** my_rpg
*/

#include "rpg.h"
#include <stdio.h>
#include <stdlib.h>

inventory_t *initiate_inventory(inventory_t *inventory, int i)
{
    inventory[i].sprite = sfSprite_create();
    if (inventory[i].sprite == NULL)
        return (NULL);
    inventory[i].texture = NULL;
    inventory[i].damage = 0;
    inventory[i].enemy_damage = 0;
    inventory[i].life = 0;
    inventory[i].rapidity = 0;
    inventory[i].leak = 0;
    inventory[i].nb_stack = 0;
    return (inventory);
}

int create_inventory(inventory_t *inventory)
{
    FILE *dir = NULL;

    dir = fopen(PATH_INVENTORY, "r");
    if (inventory == NULL || dir == NULL)
        return (84);
    fill_inventory(inventory, dir);
    fclose(dir);
    return (0);
}

inventory_t *set_inventory(void)
{
    static int init = 0;
    inventory_t *inventory = NULL;

    if (init == 0) {
        init++;
        inventory = malloc(sizeof(inventory_t) * (NB_ITEMS));
        if (inventory == NULL)
            return (NULL);
        create_inventory(&(inventory[0]));
    }
    return (inventory);
}