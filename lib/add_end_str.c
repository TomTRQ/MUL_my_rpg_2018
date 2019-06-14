/*
** EPITECH PROJECT, 2019
** rpg
** File description:
** add a '\0' at the end of a string
*/

#include <stddef.h>

char *add_null(char *str)
{
    int i = 0;

    if (str == NULL)
        return (NULL);
    for (; str[i] != '\0' && str[i] != '\n'; i++);
    if (str[i] == '\n')
        str[i] = '\0';
    return (str);
}
