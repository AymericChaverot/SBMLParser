/*
** EPITECH PROJECT, 2022
** sbmlparser
** File description:
** sbml_parsing.c
*/

#include "sbmlparser.h"

size_t count_tags(char const *str)
{
    size_t count = 0;

    for (unsigned int i = 0; str[i]; i++) {
        if (str[i] == '<')
            count++;
    }
    return (count);
}

char *get_tag_content(char *tag)
{
    char *content = malloc(sizeof(char) * (strlen(tag) + 1));
    int i = 0;

    for (; tag[i] && tag[i] != '>'; i++)
        content[i] = tag[i];
    content[i] = '\0';
    return (content);
}

char **extract_tags(char *str)
{
    char **tags = malloc(sizeof(char *) * (count_tags(str) + 1));
    int i = 0;
    int j = 0;

    for (; str[i]; i++) {
        if (str[i] == '<') {
            i++;
            tags[j] = get_tag_content(&str[i]);
            j++;
        }
    }
    tags[count_tags(str)] = NULL;
    return (tags);
}
