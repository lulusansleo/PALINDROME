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

    long int palindrome_p(long int nb, long int base, it_info_t *info);

    long int base_addition(long int nb, long int add, long int base);

    long int get_params(it_info_t *info, char **av);

    int error_handling(int ac, char **av);

    void print_usage(int output);

#endif /* !PALINDROME_H */
