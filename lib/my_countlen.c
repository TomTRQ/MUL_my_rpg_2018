/*
** EPITECH PROJECT, 2019
** my_strlen.c
** File description:
** my strlen
*/

#include <stddef.h>

int my_strlen(char *str)
{
    int len = 0;

    if (str == NULL)
        return (0);
    for (; str[len] != '\0'; len++);
    return (len);
}

int my_strarray(char **str)
{
    int len = 0;

    if (str == NULL)
        return (0);
    for (; str[len] != NULL; len++);
    return (len);
}

int count_argv(char *src)
{
    int len = 0;
    int val = 0;

    for (int i = 0; src[i] != '\0'; i++) {
        if (val == 0 && src[i] != '\t' && src[i] != ' ') {
            len++;
            val = 1;
        }
        if (src[i] == '\t' || src[i] == ' ')
            val = 0;
    }
    return (len);
}

int count_line_command(const char *str, char c)
{
    int len = 0;
    int val = 0;

    if (str == NULL)
        return (0);
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == c && val == 1) {
            len++;
            val = 0;
        } else if (str[i] != '\t' && str[i] != ' ' && str[i] != c)
            val = 1;
    }
    return (val != 0 ? len + 1 : len);
}

int count_char(char const *src, int i, char c)
{
    int len = 0;

    for (; src[i] != '\0' && src[i] != c; i++, len++) {
        if (src[i] == '\t' || src[i] == ' ')
            break;
    }
    return (len);
}