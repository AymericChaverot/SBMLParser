/*
** EPITECH PROJECT, 2022
** sbmlparser
** File description:
** requirement.c
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int my_is_alphanum(char c)
{
    if (c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z' || c >= '0' && c <= '9')
        return (1);
    return (0);
}

size_t word_size(char const *str)
{
    size_t count = 0;

    for (unsigned int i = 0; my_is_alphanum(str[i]); i++)
        count++;
    return (count);
}

size_t count_words(char const *str)
{
    size_t count = 0;

    for (unsigned int i = 0; str[i]; i++) {
        if (my_is_alphanum(str[i])) {
            count++;
            i += word_size(&str[i]) - 1;
        }
    }
    return (count);
}

char *get_word(char const *str, size_t word_size)
{
    char *new = malloc(sizeof(char) * (word_size + 1));

    for (size_t i = 0; i < word_size; i++)
        new[i] = str[i];
    new[word_size] = '\0';
    return (new);
}

char **my_str_to_word_array_synthesis(char const *str)
{
    char **array = malloc((count_words(str) + 1) * sizeof(char *));
    unsigned int word = 0;

    for (unsigned int i = 0; str[i]; i++) {
        if (my_is_alphanum(str[i])) {
            array[word] = get_word(&str[i], word_size(&str[i]));
            i += word_size(&str[i]) - 1;
            word++;
        }
    }
    array[word] = NULL;
    return (array);
}
