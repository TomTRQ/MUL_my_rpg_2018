/*
** EPITECH PROJECT, 2019
** file that initiates pnj
** File description:
** my_rpg
*/

#include <stdlib.h>
#include "rpg.h"

int add_structs_pnj_list(pnj_t *pnj)
{
    pnj_t *new = malloc(sizeof(pnj_t));

    if (new == NULL)
        return (84);
    new->next = pnj->next;
    pnj->next = new;
    return (0);
}

void add_elements_structs(pnj_t *pnj)
{
    pnj->id = 1;
    pnj->next->id = 2;
    pnj->next->next->id = 3;
    setup_text_from_file("assets/text/woman.txt", pnj);
    setup_text_from_file("assets/text/old.txt", pnj->next);
    setup_text_from_file("assets/text/boy.txt", pnj->next->next);
    initiate_pnj_faces(pnj);
    pnj->name = "Mme.Boulghour";
    pnj->next->name = "Mme.Quinoa";
    pnj->next->next->name = "M.Mais";
}

int check_if_activate_dialogs(game_t **game, sfSound *sound, \
sfSoundBuffer *buffer)
{
    static int nb = 0;

    sfSound_setLoop(sound, sfTrue);
    sfSound_setVolume(sound, VOLUME_ON);
    sfSound_setBuffer(sound, buffer);
    if (nb == 0) {
        print_text_line(game, "UN TREMBLEMENT DE TERRE ?!?!!", "", "");
        nb = 1;
    } else if (nb == 1) {
        sfRenderWindow_pollEvent(GAME_WINDOW, &GAME_EVENT);
        sfSound_play(sound);
        while (GAME_EVENT.type != sfEvtKeyPressed && GAME_EVENT.type !=
            sfEvtMouseButtonPressed)
            sfRenderWindow_pollEvent(GAME_WINDOW, &GAME_EVENT);
        sfSound_destroy(sound);
        sfSoundBuffer_destroy(buffer);
        sfMusic_play(GAME_MUSIC->back);
        nb = 2;
    }
    return (0);
}

int initiate_pnj_struct(game_t **game)
{
    pnj_t *pnj_init = malloc(sizeof(pnj_t));

    if (pnj_init == NULL)
        return (84);
    pnj_init->next = NULL;
    game[0]->pnj = pnj_init;
    for (int count = 0; count != 2; count++)
        add_structs_pnj_list(game[0]->pnj);
    add_elements_structs(game[0]->pnj);
    return (0);
}