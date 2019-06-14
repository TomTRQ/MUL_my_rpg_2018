/*
** EPITECH PROJECT, 2019
** my rpg
** File description:
** ask the name of the player
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "rpg.h"

static void error_message(void)
{
    write(1, "Your name can contain only letters or numbers.\n", 47);
}

static int check_typo_name(const char *name)
{
    for (int i = 0; name[i] != '\0'; i++)
        if (name[i] < '0' || (name[i] > '9' && name[i] < 'A') || name[i] > 'z'
            || (name[i] < 'a' && name[i] > 'Z'))
            return (84);
    return (0);
}

int setup_name(game_t **game, char **av)
{
    char *buf = NULL;
    int val = 1;

    if (av[1] != NULL)
        val = check_typo_name(av[1]);
    if (val == 0) {
        if (my_str_to_str(&buf, av[1]) == 84)
            return (84);
    } else {
        if (av[1] != NULL)
            error_message();
        if (my_str_to_str(&buf, "Luis Fonsi") == 84)
            return (84);
    }
    if (game[0] == NULL || game[0]->player == NULL)
        return (84);
    if (my_str_to_str(&game[0]->player->name, buf) == 84)
        return (84);
    return (0);
}