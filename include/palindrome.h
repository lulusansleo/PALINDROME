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
        long int i_min;
        long int i_max;
    } it_info_t;

    int is_str_digit(char *str);

    int number_error(char *str);

    long int change_to_base(long int nb, long int base);

    long int change_from_base(long int nb, long int base);

    long int reverse_number(long int nb, long int base);

    long int palindrome(long int nb, long int base, it_info_t *info);

    int palindrome_wrapper(int ac, char **av);

    int palindrome_p_wrapper(int ac, char **av);

    int check_arg(char **av);

    int check_values(long int base, it_info_t *info);

#endif /* !PALINDROME_H */
