/*
** EPITECH PROJECT, 2019
** my_parsing.c
** File description:
** parsing
*/

#include <stdlib.h>
#include "rpg.h"

int jump_space(char const *src, int i, char c)
{
    for (; src[i] != '\0' && src[i] != c; i++) {
        if (src[i] != '\t' && src[i] != ' ')
            break;
    }
    return (i);
}

static void count_len_line(char const *str, int *i, int *len, char c)
{
    int k = 0;

    for (; str[*i] != '\0' && str[*i] != c;) {
        k = count_char(str, *i, c);
        *i = *i + k;
        *len = *len + k + 1;
        *len = *len + count_char(str, *i, c);
        *i = jump_space(str, *i, c);
    }
}

static int put_next_line(char **save, char const *str, int i, char c)
{
    int len = 0;
    int j = 0;
    int k = 0;

    for (; str[i] == c; i++);
    j = i;
    i = jump_space(str, i, c);
    count_len_line(str, &i, &len, c);
    save[0] = malloc(sizeof(char) * (len + 1));
    if (save[0] == NULL)
        return (-1);
    for (k = 0; str[j] != '\0' && str[j] != c; k++) {
        j = jump_space(str, j, c);
        len = count_char(str, j, c);
        for (int m = k; k < len + m; j++, k++)
            save[0][k] = str[j];
        save[0][k] = ' ';
    }
    save[0][k - 1] = '\0';
    return (i);
}

int parse_argument(char ***dest, char const *str, char c)
{
    int len = 0;
    int j = 0;

    if (str == NULL)
        return (84);
    len = count_line_command(str, c) + 1;
    dest[0] = malloc(sizeof(char *) * len);
    if (dest[0] == NULL)
        return (84);
    dest[0][len - 1] = NULL;
    for (int i = 0; i < (len - 1); i++) {
        j = put_next_line(&(dest[0][i]), str, j, c);
        if (j == -1)
            return (84);
        else if (str[j] == '\0')
            break;
    }
    return (0);
}
