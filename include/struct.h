/*
** EPITECH PROJECT, 2019
** struct file for the project
** File description:
** my_rpg
*/

#ifndef STRUCT_H_
    #define STRUCT_H_

    typedef struct player_s
    {
        sfSprite *sprite;
        sfTexture *texture;
        sfVector2f pos;
        sfIntRect rect;
        char *name;
        sfSprite *mount;
        sfTexture *texture_mount;
        struct stat_player_s *stat_player;
        struct inventory_s *inventory;
    }player_t;

    typedef struct stat_player_s
    {
        int hp;
        int hp_max;
        int defense;
        int attack;
        int speed_attack;
        int chance_criticism;
        int chance_escape;
        int xp;
        int xp_max;
        int level;
    }stat_player_t;

    typedef struct my_clock_s
    {
        sfClock *clock;
        sfTime elapsed;
        int seconds;
        int milli;
    }my_clock_t;

    typedef struct enemy_s
    {
        char *name;
        char *map;
        sfSprite *sprite;
        sfTexture *texture;
        sfVector2f vector;
        sfIntRect rect;
        int item;
        int chance_loot;
        sfSprite *fight_s;
        sfTexture *fight_t;
        struct stat_player_s *stat;
        struct enemy_s *next;
    }enemy_t;

    typedef struct pnj_s
    {
        char *name;
        char id;
        sfSprite *sprite;
        sfTexture *texture;
        sfVector2f vector;
        sfIntRect rect;
        char *dialog;
        sfSprite *sprite_p;
        sfTexture *texture_p;
        sfIntRect rect_p;
        struct pnj_s *next;
    }pnj_t;

    typedef struct music_s
    {
        sfMusic *menu;
        sfMusic *boss;
        sfMusic *back;
        sfMusic *mob;
        sfMusic *donjon;
        sfMusic *final_boss;
    }music_t;

    typedef struct sound_s
    {
        sfSound *heal;
        sfSound *kill;
        sfSound *attack;
        sfSound *house;
    }sound_t;

    typedef struct sf_obj_s
    {
        sfRenderWindow *window;
        sfEvent event;
    }sf_obj_t;

    typedef struct scene_s
    {
        char *name;
        char **map;
        sfTexture *background;
        sfIntRect rect;
        sfVector2f pos;
        struct button_s *button;
        enemy_t *enemy;
        pnj_t *pnj;
        enemy_t *boss;
    }scene_t;

    typedef struct game_t
    {
        scene_t **scene;
        int scene_nb;
        int enemy_spawn;
        player_t *player;
        my_clock_t *time;
        sf_obj_t *sf_obj;
        struct pnj_s *pnj;
        struct music_s *music;
        struct enemy_s *enemy;
    }game_t;

    typedef struct button_s
    {
        char *name;
        sfSprite *sprite;
        sfIntRect rect;
        int (*callback)(game_t **game);
        struct button_s *next;
    }button_t;
#endif