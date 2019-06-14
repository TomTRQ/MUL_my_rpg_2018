/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** animations for fight
*/

#include "rpg.h"

int print_damage(game_t **game, sfVector2f pos, int dmg)
{
    sfFont* font = sfFont_createFromFile("assets/text/dialog.ttf");
    sfText* text = sfText_create();
    char *str = NULL;
    sfTime time_sleep = {400000};

    str = int_to_array(dmg);
    if (str == NULL)
        return (84);
    sfText_setString(text, str);
    sfText_setFont(text, font);
    sfText_setCharacterSize(text, 70);
    sfText_setColor(text, sfRed);
    sfText_move(text, pos);
    sfRenderWindow_drawText(GAME_WINDOW, text, NULL);
    sfRenderWindow_display(GAME_WINDOW);
    sfSleep(time_sleep);
    sfText_destroy(text);
    sfFont_destroy(font);
    return (0);
}