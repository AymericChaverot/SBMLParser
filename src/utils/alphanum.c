/*
** EPITECH PROJECT, 2022
** sbmlparser
** File description:
** alphanum.c
*/

int is_alphanum(char c)
{
    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') ||
        (c >= '0' && c <= '9') || c == '?')
        return (1);
    return (0);
}
