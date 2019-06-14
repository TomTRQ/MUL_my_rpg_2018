/*
** EPITECH PROJECT, 2019
** rpg
** File description:
** my strcopy
*/

#include <stdlib.h>

int my_str_to_str(char **dest, const char *src)
{
    int len = 0;

    if (dest[0] != NULL)
        free(dest[0]);
    for (; src[len] != '\0'; len++);
    dest[0] = malloc(sizeof(char) * (len + 1));
    if (dest[0] == NULL)
        return (84);
    for (int j = 0; src[j] != 0; j++)
        dest[0][j] = src[j];
    dest[0][len] = '\0';
    return (0);
}