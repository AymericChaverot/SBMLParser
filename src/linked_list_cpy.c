/*
** EPITECH PROJECT, 2022
** sbmlparser
** File description:
** linked_list_cpy.c
*/

#include "sbmlparser.h"

content_t *cpy_content(content_t *start, content_t *to_cpy)
{
    content_t *tmp = malloc(sizeof(content_t));

    tmp->name = strdup(to_cpy->name);
    tmp->value = strdup(to_cpy->value);
    tmp->next = start;
    return (tmp);
}

element_t *chose_placement(element_t *start, element_t *new)
{
    element_t *tmp = start;
    content_t *content = new->content;
    content_t *content2 = NULL;

    if (start == NULL)
        return (new);
    content2 = tmp->content;
    for (; content && strcmp(content->name, "id") != 0;
    content = content->next);
    for (; content2 && strcmp(content2->name, "id") != 0;
    content2 = content2->next);
    if (content && content2 && strcmp(content->value, content2->value) < 0) {
        new->next = start;
        return (new);
    }
    for (; tmp && tmp->next; tmp = tmp->next);
    tmp->next = new;
    return (start);
}

element_t *cpy_element(element_t *start, element_t *to_cpy)
{
    element_t *tmp = malloc(sizeof(element_t));

    tmp->name = strdup(to_cpy->name);
    for (content_t *tmp_content = to_cpy->content; tmp_content;
    tmp_content = tmp_content->next) {
        tmp->content = cpy_content(tmp->content, tmp_content);
    }
    return (chose_placement(start, tmp));
}
