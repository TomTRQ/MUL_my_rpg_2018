/*
** EPITECH PROJECT, 2019
** minishell2
** File description:
** compare two strings
*/

#include <stdlib.h>

int compare_str(const char *str, const char *sent)
{
    int i = 0;

    if (str == NULL || sent == NULL)
        return (84);
    for (i = 0; str[i] != '\0' && sent[i] != '\0'; i++) {
        if (str[i] != sent[i])
            return (84);
    }
    if (str[i] == '\0' && sent[i] == '\0')
        return (0);
    else
        return (84);
}

int compare_n_char(const char *str, const char *sent, int len)
{
    int i = 0;

    if (str == NULL || sent == NULL)
        return (84);
    for (i = 0; str[i] != '\0' && sent[i] != '\0' && i < len; i++) {
        if (str[i] != sent[i])
            return (84);
    }
    if (i == len)
        return (0);
    if (str[i] == '\0' && sent[i] == '\0')
        return (0);
    else
        return (84);
}