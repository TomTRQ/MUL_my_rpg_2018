/*
** EPITECH PROJECT, 2019
** my rpg
** File description:
** check button
*/

#include "rpg.h"

int check_button(game_t **game)
{
    button_t *tmp = NULL;
    int x = GAME_EVENT.mouseButton.x;
    int y = GAME_EVENT.mouseButton.y;
    sfFloatRect pos;
    int val = 0;

    tmp = game[0]->scene[game[0]->scene_nb]->button;
    for (int i = 0; tmp != NULL; i++) {
        pos = sfSprite_getGlobalBounds(tmp->sprite);
        if (sfFloatRect_contains(&pos, x, y) == sfTrue) {
            val = tmp->callback(game);
            break;
        }
        tmp = tmp->next;
    }
    return (val != 84 ? 0 : 84);
}