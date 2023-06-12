/*
** EPITECH PROJECT, 2023
** palindrome
** File description:
** palindrome header
*/

#ifndef PALINDROME_H
    #define PALINDROME_H

    #include <string.h>
    #include <ctype.h>
    #include <stdio.h>
    #include <stdlib.h>

    typedef struct it_info {
        int i_min;
        int i_max;
    } it_info_t;

    int is_str_digit(char *str);

    int number_error(char *str);

    int change_to_base(int nb, int base);

    int palindrome(int nb, int base, it_info_t *info);

    void palindrome_wrapper(int ac, char **av);

#endif /* !PALINDROME_H */
