/*
** EPITECH PROJECT, 2019
** main file of the project
** File description:
** my_rpg
*/

#include <unistd.h>
#include <stdlib.h>
#include "rpg.h"

int check_key(game_t **game)
{
    if (GAME_EVENT.key.code == sfKeyEscape)
        pause_game(game);
    if (GAME_EVENT.key.code == sfKeyE)
        inventory_game(game);
    return (0);
}

int check_event(game_t **game)
{
    while (sfRenderWindow_pollEvent(GAME_WINDOW, &GAME_EVENT)) {
        if (GAME_EVENT.type == sfEvtClosed)
            sfRenderWindow_close(GAME_WINDOW);
        if (GAME_EVENT.type == sfEvtMouseButtonPressed && check_button(game) ==
            84)
            return (84);
        if (GAME_EVENT.type == sfEvtKeyPressed && check_key(game) == 84)
            return (84);
        if (GAME_EVENT.type == sfEvtKeyPressed && handle_player_movements(game)
            == 84)
            return (84);
    }
    return (0);
}

int game_loop(game_t **game)
{
    while (sfRenderWindow_isOpen(game[0]->sf_obj->window)) {
        if (check_event(game) == 84)
            return (84);
        if (sfRenderWindow_isOpen(game[0]->sf_obj->window) == sfFalse)
            return (0);
        sfRenderWindow_clear(GAME_WINDOW, sfBlack);
        if (display(game) == 84)
            return (84);
        sfRenderWindow_display(GAME_WINDOW);
        check_start_fight(game);
        time_clock(GAME_TIME);
    }
    return (0);
}

int main(int ac, char **av)
{
    game_t *game = NULL;
    int val = 0;

    write(1, "---   Initiating the game   ---\n", 32);
    if (initiate_state(&game) == 84)
        return (84);
    if (initiate_enemy(&game) == 84)
        return (84);
    if (initiate_pnj_struct(&game) == 84)
        return (84);
    if (initiate_music_struct(&game) == 84)
        return (84);
    write(1, "Setting up the name\n", 20);
    if (setup_name(&game, av) == 84)
        return (84);
    write(1, "->    Launching the game ...\n", 29);
    val = game_loop(&game);
    destroy_free_all(&game);
    return (val);
}