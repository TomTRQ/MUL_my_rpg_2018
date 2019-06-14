/*
** EPITECH PROJECT, 2019
** file that initiates dialogs from file
** File description:
** my_rpg
*/

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/stat.h>
#include "rpg.h"

void print_dialog_background(game_t **game, char *file, int nb)
{
    sfSprite *sprite = sfSprite_create();
    sfTexture *texture = sfTexture_createFromFile\
    (file, NULL);
    sfVector2f first = {5, HEIGHT - 250};
    sfVector2f second = {250, HEIGHT - 250};

    if (nb != 1) {
        sfRenderWindow_clear(GAME_WINDOW, sfBlack);
        display(game);
    }
    sfSprite_setTexture(sprite, texture, sfTrue);
    if (nb == 0)
        sfSprite_setPosition(sprite, first);
    else if (nb == 1)
        sfSprite_setPosition(sprite, second);
    sfRenderWindow_drawSprite(GAME_WINDOW, sprite, NULL);
    sfSprite_destroy(sprite);
    sfTexture_destroy(texture);
}

void set_text(sfText *text, sfFont *font, sfVector2f vector, \
game_t **game)
{
    sfText_setPosition(text, vector);
    sfText_setCharacterSize(text, 55);
    sfText_setColor(text, sfBlack);
    sfRenderWindow_drawText(GAME_WINDOW, text, NULL);
    sfText_destroy(text);
    sfFont_destroy(font);
}

int print_dialog(char *display_tab, game_t **game)
{
    sfFont* font;
    sfText* text;
    sfVector2f vector = {280, 480};
    char *print = NULL;
    int count_lines = count_line_command(display_tab, '.');

    if (display_tab == NULL)
        return (0);
    for (int i = 0, a = 480; i < count_lines; i++, a += 60) {
        font = sfFont_createFromFile("assets/text/dialog.ttf");
        text = sfText_create();
        print = get_word(display_tab, '.', i);
        sfText_setString(text, print);
        sfText_setFont(text, font);
        vector.y = a;
        set_text(text, font, vector, game);
        free(print);
    }
    return (1);
}

int setup_text_from_file(char *path, pnj_t *pnj)
{
    int fd = open(path, O_RDONLY);
    struct stat buff;
    int size = 0;
    int nread = 0;

    stat(path, &buff);
    size = buff.st_size;
    pnj->dialog = malloc(sizeof(char) * (size));
    if (!pnj->dialog)
        return (84);
    nread = read(fd, pnj->dialog, size);
    pnj->dialog[nread] = '\0';
    close(fd);
    return (0);
}

int get_text_to_display(game_t **game, pnj_t *pnj)
{
    char **display_tab = NULL;
    int tab[3] = {0, 0, 0};
    int max = check_element_str(pnj->dialog, ';');

    if (parse_argument(&display_tab, pnj->dialog, ';') == 84)
        return (84);
    while (tab[1] < max) {
        sfRenderWindow_pollEvent(GAME_WINDOW, &GAME_EVENT);
        if (GAME_EVENT.type == sfEvtKeyPressed && GAME_EVENT.key.code ==
            sfKeyEscape)
            break;
        if (GAME_EVENT.type == sfEvtKeyPressed && GAME_EVENT.key.code == sfKeyT)
            tab[1] = tab[1] + 1;
        print_dialog_background(game, "assets/background/dialog_box.png", 0);
        print_character_information(pnj, game);
        print_dialog(display_tab[tab[1]], game);
        sfRenderWindow_display(GAME_WINDOW);
    }
    free_tab(&display_tab);
    return (0);
}