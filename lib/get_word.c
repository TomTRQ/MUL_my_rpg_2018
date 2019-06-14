/*
** EPITECH PROJECT, 2019
** file that gets a certain word from a string
** File description:
** my_rpg
*/

#include <stdlib.h>

char *get_word(char *str, char c, int nb)
{
    char *new = NULL;
    int n = 0;
    int s = 0;

    if (!str)
        return (NULL);
    for (int i = 0; i < nb && str[n] != '\0'; n++) {
        if (str[n] == c)
            i++;
    }
    for (s = n; str[s] != c && str[s] != '\0'; s++);
    new = malloc(sizeof(char) * (s - n + 1));
    if (!new)
        return (NULL);
    for (s = n; str[s] != c && str[s] != '\0'; s++)
        new[s - n] = str[s];
    new[s - n] = '\0';
    return (new);
}
