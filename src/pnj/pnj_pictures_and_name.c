/*
** EPITECH PROJECT, 2019
** file that initiates pnj
** File description:
** my_rpg
*/

#include "rpg.h"

void initiate_pnj_faces(pnj_t *pnj)
{
    sfIntRect woman = {300, 150, 125, 150};
    sfIntRect old = {0, 150, 144, 150};
    sfIntRect boy = {150, 0, 130, 140};

    pnj->texture_p = sfTexture_createFromFile\
    ("assets/pnj/pnj_pictures.png", NULL);
    pnj->next->texture_p = sfTexture_createFromFile\
    ("assets/pnj/pnj_pictures.png", NULL);
    pnj->next->next->texture_p = sfTexture_createFromFile\
    ("assets/pnj/pnj_pictures.png", NULL);
    pnj->sprite_p = sfSprite_create();
    pnj->next->sprite_p = sfSprite_create();
    pnj->next->next->sprite_p = sfSprite_create();
    pnj->rect_p = woman;
    pnj->next->rect_p = old;
    pnj->next->next->rect_p = boy;
    pnj->id = '1';
    pnj->next->id = '2';
    pnj->next->next->id = '3';
}

void print_character_name(pnj_t *pnj, game_t **game)
{
    sfFont* font;
    sfText* text;
    sfVector2f vector = {30, 630};

    font = sfFont_createFromFile("assets/text/dialog.ttf");
    text = sfText_create();
    sfText_setString(text, pnj->name);
    sfText_setFont(text, font);
    sfText_setPosition(text, vector);
    sfText_setCharacterSize(text, 35);
    sfText_setColor(text, sfBlack);
    sfRenderWindow_drawText(GAME_WINDOW, text, NULL);
    sfText_destroy(text);
    sfFont_destroy(font);
}

void print_character_information(pnj_t *pnj, game_t **game)
{
    sfVector2f pos = {55, 480};

    print_character_name(pnj, game);
    sfSprite_setTexture(pnj->sprite_p, pnj->texture_p, sfTrue);
    sfSprite_setTextureRect(pnj->sprite_p, pnj->rect_p);
    sfSprite_setPosition(pnj->sprite_p, pos);
    sfRenderWindow_drawSprite(GAME_WINDOW, pnj->sprite_p, NULL);
}