/*
** EPITECH PROJECT, 2019
** file that modifies the cursor of the mouse
** File description:
** my_rpg
*/

#include <stdlib.h>
#include "rpg.h"

char *int_to_array(int nb)
{
    int i = 1;
    int buff = nb;
    char *new = NULL;

    for (; buff >= 10; i++) {
        buff = buff / 10;
    }
    new = malloc(sizeof(char) * (i + 1));
    new[i] = '\0';
    if (new == NULL)
        return (NULL);
    for (; nb >= 10; ) {
        i = i - 1;
        new[i] = nb % 10 + '0';
        nb = nb / 10;
    }
    i = i - 1;
    new[i] = nb + '0';
    return (new);
}

char *my_strcat(char *dest, char *src)
{
    int i = 0;
    int j = 0;
    char *temp = malloc(sizeof(char) * my_strlen(dest) + my_strlen(src) + 1);

    if (dest == NULL || src == NULL)
        return (NULL);
    for (i = 0; dest[i] != '\0'; i++)
        temp[i] = dest[i];
    for (j = 0; src[j] != '\0'; j++)
        temp[i + j] = src[j];
    temp[i + j] = '\0';
    return (temp);
}

void print_text_line(game_t **game, char *first_text, \
char *item, char *second_text)
{
    sfText *text = sfText_create();
    sfFont *font = sfFont_createFromFile("assets/text/dialog.ttf");
    sfVector2f vector = {320, 535};
    static int tab[2] = {1, 0};

    if (sfKeyboard_isKeyPressed(sfKeyT) && \
    tab[0] == 1 && GAME_TIME->milli / 4 != tab[1])
        tab[0] = 0;
    else if (tab[0] == 1) {
        print_dialog_background\
        (game, "assets/background/sec_dialog_box.png", 1);
        first_text = my_strcat(first_text, item);
        if (second_text != NULL && second_text[0] != '\0')
            first_text = my_strcat(first_text, second_text);
        sfText_setString(text, first_text);
        sfText_setFont(text, font);
        set_text(text, font, vector, game);
        tab[0] = 1;
    }
    tab[1] = GAME_TIME->milli / 4;
}