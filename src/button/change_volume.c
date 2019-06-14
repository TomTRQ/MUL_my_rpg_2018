/*
** EPITECH PROJECT, 2019
** my rpg
** File description:
** change the volume
*/

#include "rpg.h"

int setup_sprite(button_t *button, int nb)
{
    button_t *tmp = NULL;
    sfIntRect rect[2] = {{72, 0, 72, 72}, {0, 0, 72, 72}};

    for (tmp = button; tmp != NULL; tmp = tmp->next)
        if (compare_str(tmp->name, "change_volume") == 0)
            break;
    if (tmp == NULL)
        return (0);
    if (nb == 1)
        sfSprite_setTextureRect(tmp->sprite, rect[1]);
    else
        sfSprite_setTextureRect(tmp->sprite, rect[0]);
    return (0);
}

int change_volume(game_t **game)
{
    static int volume_stat = 1;

    for (int i = 0; game[0]->scene[i] != NULL; i++)
        setup_sprite(game[0]->scene[i]->button, volume_stat);
    volume_stat = volume_stat == 1 ? 0 : 1;
    setting_volume_music(game, volume_stat);
    return (0);
}