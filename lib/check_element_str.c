/*
** EPITECH PROJECT, 2019
** file that check the occurence of a character
** File description:
** my_rpg
*/

#include <stdlib.h>

int check_element_str(char *str, int c)
{
    int count = 0;

    if (str == NULL)
        return (0);
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == c)
            count = count + 1;
    }
    return (count);
}