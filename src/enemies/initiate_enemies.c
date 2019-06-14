/*
** EPITECH PROJECT, 2019
** rpg
** File description:
** initiate enemies
*/

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/stat.h>
#include "rpg.h"

char *get_enemy_file(void)
{
    char *buffer = NULL;
    int fd = open(ENEMY_STAT, O_RDONLY);
    struct stat buff;
    int size = 0;
    int nread = 0;

    if (fd == -1)
        return (NULL);
    stat(ENEMY_STAT, &buff);
    size = buff.st_size;
    buffer = malloc(sizeof(char) * (size) + 1);
    if (buffer == NULL)
        return (NULL);
    nread = read(fd, buffer, size);
    buffer[nread] = '\0';
    close(fd);
    return (buffer);
}

char *get_stat_line(char *initialize, int line)
{
    char *stat_line = NULL;

    stat_line = (get_word(initialize, '\n', line));
    if (stat_line == NULL)
        return (NULL);
    return (stat_line);
}

int initiate_enemy_stats_fight(enemy_t *new, char *stat_line)
{
    new->stat = malloc(sizeof(stat_player_t));
    if (new->stat == NULL)
        return (84);
    new->fight_s = sfSprite_create();
    new->fight_t = sfTexture_createFromFile(get_word\
    (stat_line, ' ', 5), NULL);
    new->stat->hp_max = my_convert_to_int\
    (get_word(stat_line, ' ', 6));
    new->stat->hp = new->stat->hp_max;
    new->stat->defense = my_convert_to_int\
    (get_word(stat_line, ' ', 7));
    new->stat->attack = my_convert_to_int\
    (get_word(stat_line, ' ', 8));
    new->stat->speed_attack = my_convert_to_int\
    (get_word(stat_line, ' ', 9));
    new->stat->chance_criticism = my_convert_to_int\
    (get_word(stat_line, ' ', 10));
    new->stat->xp = my_convert_to_int(get_word(stat_line, ' ', 11));
    return (0);
}

int add_elements_enemy_list(enemy_t *enemy, char *stat_line)
{
    enemy_t *new = malloc(sizeof(enemy_t));

    if (new == NULL)
        return (84);
    new->next = enemy->next;
    enemy->next = new;
    new->name = get_word(stat_line, ' ', 0);
    new->sprite = sfSprite_create();
    new->texture = sfTexture_createFromFile(get_word(stat_line, ' ', 1), NULL);
    new->map = get_word(stat_line, ' ', 2);
    new->item = my_convert_to_int(get_word(stat_line, ' ', 3));
    new->chance_loot = my_convert_to_int(get_word(stat_line, ' ', 4));
    return (initiate_enemy_stats_fight(new, stat_line));
}

int initiate_enemy(game_t **game)
{
    enemy_t *init_enemy = malloc(sizeof(enemy_t));
    char *initialize = get_enemy_file();
    char *stat_line = NULL;

    if (init_enemy == NULL)
        return (84);
    init_enemy->next = NULL;
    game[0]->enemy = init_enemy;
    for (int line = 1; line <= 10; line++) {
        stat_line = get_stat_line(initialize, line);
        if (stat_line == NULL || add_elements_enemy_list\
        (game[0]->enemy, stat_line) == 84)
            return (84);
    }
    if (initiate_enemies_on_scene(game) == 84)
        return (84);
    return (0);
}