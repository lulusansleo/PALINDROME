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

    int is_str_digit(char *str);

    int number_error(char *str);

    int change_to_base(int nb, int base);

    int palindrome(int nb, int base);

#endif /* !PALINDROME_H */
