/*
** EPITECH PROJECT, 2019
** my rpg
** File description:
** all defines
*/

#ifndef MY_H_
    #define MY_H_

    int my_convert_to_int(char *str);
    int check_element_str(char *str, int c);
    char *get_word(char *str, char c, int nb);
    int my_strlen(char *str);
    int my_strarray(char **str);
    int count_argv(char *src);
    int count_line_command(const char *str, char c);
    int count_char(char const *src, int i, char c);
    int parse_argument(char ***dest, char const *str, char c);
    int my_getnbr(char const *str);
    int compare_str(const char *str, const char *sent);
    int free_str(char **str);
    int free_tab(char ***tab);
    int my_str_to_str(char **dest, const char *src);
    char *add_null(char *str);
    int out_of_map(char **str, float y, float x);
    int compare_n_char(const char *str, const char *sent, int len);
    char *int_to_array(int nb);

#endif