/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** main fight funcs
*/

#include "rpg.h"
#include <unistd.h>

void display_fight(player_t *player, enemy_t *enemy, scene_t *scene,
    game_t **game)
{
    sfVector2f enemy_bar = {150, 150};
    sfVector2f player_bar = {820, 150};

    sfRenderWindow_clear(GAME_WINDOW, sfBlack);
    display_scene(scene, GAME_WINDOW);
    display_button(game[0]->scene[game[0]->scene_nb]->button, GAME_WINDOW);
    fight_lifebar(GAME_WINDOW, enemy_bar, enemy->stat->hp_max,
    enemy->stat->hp);
    fight_lifebar(GAME_WINDOW, player_bar, player->stat_player->hp_max,
    player->stat_player->hp);
    sfRenderWindow_drawSprite(GAME_WINDOW, enemy->sprite, NULL);
    sfRenderWindow_drawSprite(GAME_WINDOW, player->sprite, NULL);
    modify_cursor(game);
    sfRenderWindow_display(GAME_WINDOW);
}

static int fight_loop(game_t **game, enemy_t *enemy, scene_t *scene,
    sfRenderWindow *window)
{
    int end = 0;
    int first = 1;

    while (end == 0 || end == 4) {
        display_fight(GAME_PLAYER, enemy, scene, game);
        if (enemy->stat->speed_attack>
            GAME_PLAYER->stat_player->speed_attack && first == 1) {
            end = enemy_turn(game, enemy, GAME_PLAYER, end);
            first = 0;
        }
        if (end != 0)
            return (end);
        end = player_turn(game, enemy);
        display_fight(GAME_PLAYER, enemy, scene, game);
        if (end != 0 && end != 4)
            return (end);
        end = enemy_turn(game, enemy, game[0]->player, end);
    }
    return (end);
}

static void end_fight(int result, game_t **game, enemy_t *enemy)
{
    switch (result)
    {
        case 1:
            win_fight(game, enemy);
            break;
        case 2:
            leave_fight(game);
            break;
        case 3:
            lose_fight(game);
            exit_game(game);
            break;
        default:
            break;
    }
}

scene_t *choose_background(scene_t *scene, char *back)
{
    if (compare_str(back, "donjon_water") == 0)
        scene->background = sfTexture_createFromFile\
        ("assets/fight_back/back_water.png", NULL);
    if (compare_str(back, "donjon_mine") == 0 || \
    compare_str(back, "path_mine") == 0)
        scene->background = sfTexture_createFromFile\
        ("assets/fight_back/back_mine.png", NULL);
    if (compare_str(back, "donjon_wood") == 0)
        scene->background = sfTexture_createFromFile\
        ("assets/fight_back/back_castle.png", NULL);
    if (compare_str(back, "village") == 0)
        scene->background = sfTexture_createFromFile\
        ("assets/fight_back/back_village.png", NULL);
    if (compare_str(back, "path_wood") == 0)
        scene->background = sfTexture_createFromFile\
        ("assets/fight_back/back_forest.png", NULL);
    if (compare_str(back, "path_water") == 0)
        scene->background = sfTexture_createFromFile\
        ("assets/fight_back/back_lake.png", NULL);
    return (scene);
}

int launch_fight(game_t **game, enemy_t *enemy)
{
    int result = 0;
    char *scene_back = NULL;
    sfMusic *playing = get_playing_music(game);

    if (my_str_to_str(&scene_back, GAME_SCENE->name) == 84)
        return (AN_ERROR);
    if (change_scene(game, "fight") == 84)
        return (AN_ERROR);
    choose_music_fight(game, enemy);
    GAME_SCENE = choose_background(GAME_SCENE, scene_back);
    display_scene(GAME_SCENE, GAME_WINDOW);
    sfRenderWindow_display(GAME_WINDOW);
    GAME_PLAYER = init_player_fight(GAME_PLAYER);
    enemy = init_enemy_fight(enemy);
    result = fight_loop(game, enemy, GAME_SCENE, GAME_WINDOW);
    enemy->stat->hp = enemy->stat->hp_max;
    close_music_fight(game, enemy, playing);
    end_fight(result, game, enemy);
    change_scene(game, scene_back);
    return(A_SUCCESS);
}