/*
** EPITECH PROJECT, 2019
** rpg
** File description:
** look around the player and return a bool to know if he can move or not
*/

#include "rpg.h"

static int check_pnj_enemy(sfVector2f new_pos, game_t **game, sfVector2i move)
{
    int val = CAN_MOVE;
    pnj_t *pnj = NULL;
    char c = GAME_SCENE->map[(int)new_pos.y][(int)new_pos.x];

    if (c == PNJ_1 || c == PNJ_2 || c == PNJ_3) {
        pnj = get_pnj(game, c);
        if (pnj != NULL) {
            val = get_text_to_display(game, pnj);
            return (val == AN_ERROR ? AN_ERROR : CANT_MOVE);
        }
    }
    if (c == BOSS) {
        if (move_to_boss(game, move) == A_FAILED)
            return (CAN_MOVE);
        val = launch_fight(game, GAME_SCENE->boss);
        GAME_SCENE->map[(int)new_pos.y][(int)new_pos.x] = '.';
        return (val == AN_ERROR ? AN_ERROR : CANT_MOVE);
    }
    return (val);
}

static int check_building(char c, game_t **game)
{
    int val = CANT_MOVE;

    if (c == DON)
        val = go_donjon(game);
    if (c == SOR)
        val = go_out(game);
    if (c == FOR)
        val = change_scene(game, "path_wood");
    if (c == HOU)
        val = change_scene(game, "house_down");
    if (c == FLO)
        val = change_scene(game, "house_up");
    if (c == MIN)
        val = change_scene(game, "path_mine");
    if (c == VIL)
        val = change_scene(game, "village");
    if (val == AN_ERROR) {
        return (AN_ERROR);
    }
    return (val == A_SUCCESS ? CANT_MOVE : CAN_MOVE);
}

static int check_move(scene_t *scene, game_t **game, sfVector2f new_pos_1,
    sfVector2i move)
{
    int val;

    if (out_of_map(scene->map, new_pos_1.y, new_pos_1.x) == 1)
        return (1);
    if (scene->map[(int)new_pos_1.y][(int)new_pos_1.x] == OBS ||
        scene->map[(int)new_pos_1.y][(int)new_pos_1.x] == STO)
        return (1);
    if (scene->map[(int)new_pos_1.y][(int)new_pos_1.x] == VID)
        return (0);
    if (scene->map[(int)new_pos_1.y][(int)new_pos_1.x] == COF)
        return (open_treasure(game));
    if (scene->map[(int)new_pos_1.y][(int)new_pos_1.x] == WAT)
        return (verif_boat(game));
    val = check_building(scene->map[(int)new_pos_1.y][(int)new_pos_1.x], game);
    if (val != CAN_MOVE)
        return (val);
    val = check_pnj_enemy(new_pos_1, game, move);
    return (val);
}

static void create_secondary_position(sfVector2f *new_pos_1, sfVector2f
    *new_pos_2, sfVector2i move_pos)
{
    if (move_pos.x == 0 && move_pos.y < 0) {
        new_pos_2->x = new_pos_1->x + SIZE_SIDE - (SPEED * 2);
        new_pos_2->y = new_pos_1->y + 0;
    } else if (move_pos.x == 0 && move_pos.y > 0) {
        new_pos_1->y = new_pos_1->y + SIZE_SIDE - (SPEED * 2);
        new_pos_2->x = new_pos_1->x + SIZE_SIDE - (SPEED * 2);
        new_pos_2->y = new_pos_1->y + 0;
    }
    if (move_pos.x < 0 && move_pos.y == 0) {
        new_pos_2->x = new_pos_1->x + 0;
        new_pos_2->y = new_pos_1->y + SIZE_SIDE - (SPEED * 2);
    } else if (move_pos.x > 0 && move_pos.y == 0) {
        new_pos_1->x = new_pos_1->x + SIZE_SIDE - (SPEED * 2);
        new_pos_2->x = new_pos_1->x + 0;
        new_pos_2->y = new_pos_1->y + SIZE_SIDE - (SPEED * 2);
    }
    new_pos_1->x = new_pos_1->x / SIZE_SIDE;
    new_pos_1->y = new_pos_1->y / SIZE_SIDE;
    new_pos_2->x = new_pos_2->x / SIZE_SIDE;
    new_pos_2->y = new_pos_2->y / SIZE_SIDE;
}

int setup_position_to_check(scene_t *scene, sfVector2i move, game_t **game)
{
    sfVector2f new_pos_1 = {0, 0};
    sfVector2f new_pos_2 = {0, 0};
    int val;

    new_pos_1.x = scene->rect.left * ZOOM.x + GAME_PLAYER->pos.x + move.x +
        SPEED;
    new_pos_1.y = scene->rect.top * ZOOM.y + GAME_PLAYER->pos.y + move.y +
        SPEED;
    create_secondary_position(&new_pos_1, &new_pos_2, move);
    val = check_move(scene, game, new_pos_1, move);
    if (val != CAN_MOVE)
        return (val);
    val = check_move(scene, game, new_pos_2, move);
    return (val);
}