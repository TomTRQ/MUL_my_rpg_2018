/*
** EPITECH PROJECT, 2019
** struct inventory file for the project
** File description:
** my_rpg
*/

#ifndef INVENTORY_H_
    #define INVENTORY_H_

    #include <stdio.h>

    static const int NB_ITEMS = 11;
    static const char PATH_INVENTORY[] = "assets/obj/all_path_obj.txt";
    #define GAME_INVENTORY game[0]->player->inventory
    #define GAME_STAT game[0]->player->stat_player

    typedef struct inventory_s
    {
        char *param_player;
        sfSprite *sprite;
        sfTexture *texture;
        sfVector2f vector;
        sfIntRect rect;
        int damage;
        int enemy_damage;
        int life;
        int rapidity;
        int leak;
        int nb_stack;
    }inventory_t;

    inventory_t *set_inventory(void);
    int fill_inventory(inventory_t *inventory, FILE *dir);
    int inventory_game(game_t **game);
    int set_text_inventory(game_t **game);
    char *my_convert_to_char(int nbr);
    char *my_strcat(char *dest, char *str);
    char *my_strdup(char const *src);
    int display_inventory(game_t **game);
    inventory_t *initiate_inventory(inventory_t *inventory, int i);
    int display_text(sfText *text, game_t **game, sfVector2f coord, int len);

    // left_corner.c
    int display_def(sfText *text, game_t **game,
        sfVector2f coord);
    int display_chance_escape(sfText *text, game_t **game,
        sfVector2f coord);
    int display_chance_criticism(sfText *text, game_t **game,
        sfVector2f coord);
    int display_speed_attack(sfText *text, game_t **game,
        sfVector2f coord);
    int display_attack(sfText *text, game_t **game,
        sfVector2f coord);
    // head.c
    int display_hp(sfText *text, game_t **game,
        sfVector2f coord);
    int display_name(sfText *text, game_t **game,
        sfVector2f coord);
    int display_level(sfText *text, game_t **game,
        sfVector2f coord);
    int display_xp(sfText *text, game_t **game,
        sfVector2f coord);
#endif