/*
** EPITECH PROJECT, 2019
** my rpg
** File description:
** boat
*/

#include <unistd.h>
#include "rpg.h"

/*int active_boat(game_t **game)
{
    if (scene->map[(int)new_pos_1.y][(int)new_pos_1.x] == BOA)
        return (active_boat(game));
    write(1, "go on boat\n", 11);
    return (0);
}*/

int verif_boat(game_t **game)
{
    change_scene(game, "path_water");
    return (1);
}

int open_treasure(game_t **game)
{
    static int once = 0;
    sfTime time_sleep = {200000};

    if (once == 0) {
        print_text_line(game, "Un coffre plein! Vous y trouvez un Objet!",
            "", "");
        sfRenderWindow_display(GAME_WINDOW);
        once = 1;
        sfSleep(time_sleep);
    }
    return (0);
}