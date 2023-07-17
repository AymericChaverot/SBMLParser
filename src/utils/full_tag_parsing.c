/*
** EPITECH PROJECT, 2022
** sbmlparser
** File description:
** full_tag_parsing.c
*/

#include "sbmlparser.h"

content_t *place_content_alphabetically(content_t *content, content_t *new)
{
    content_t *tmp = content;

    if (content == NULL)
        return (new);
    if (my_strcmp(content->name, new->name) > 0) {
        new->next = content;
        return (new);
    }
    for (; tmp->next && my_strcmp(tmp->next->name, new->name) < 0;
        tmp = tmp->next);
    new->next = tmp->next;
    tmp->next = new;
    return (content);
}

content_t *add_content(content_t *start, char *content, unsigned int *index)
{
    content_t *new = malloc(sizeof(content_t));
    char *tmp_name = malloc(sizeof(char) * (strlen(content) + 1));
    char *tmp_value = malloc(sizeof(char) * (strlen(content) + 1));
    int i = 0;
    int j = 0;

    for (; content[i] && content[i] != '='; i++)
        tmp_name[i] = content[i];
    tmp_name[i] = '\0';
    for (; content[i] && content[i] != '"'; i++);
    i += 1;
    for (; content[i] && content[i] != '"'; j++, i++)
        tmp_value[j] = content[i];
    tmp_value[j] = '\0';
    new->name = tmp_name;
    new->value = tmp_value;
    new->next = start;
    *index += i;
    return (place_content_alphabetically(start, new));
}

content_t *get_content(char *full_tag)
{
    content_t *content = NULL;
    unsigned int i = 0;

    while (full_tag[i] && full_tag[i] != ' ')
        i++;
    while (full_tag[i]) {
        if (is_alphanum(full_tag[i]))
            content = add_content(content, &full_tag[i], &i);
        i++;
    }
    return (content);
}

char *extract_name(char *full_tag)
{
    char *name = malloc(sizeof(char) * (strlen(full_tag) + 1));
    int i = 0;

    for (; full_tag[i] && full_tag[i] != ' '; i++)
        name[i] = full_tag[i];
    name[i] = '\0';
    return (name);
}
