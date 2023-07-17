/*
** EPITECH PROJECT, 2022
** sbmlparser
** File description:
** json_reaction.c
*/

#include "sbmlparser.h"

element_t *get_reaction_element(element_t *tmp, content_t *content2)
{
    for (content_t *content = tmp->content; content;
    content = content->next) {
        if (strcmp(content->name, "species") == 0 &&
            strcmp(content->value, content2->value) == 0)
            return (tmp);
    }
    return (NULL);
}

element_t *get_element(element_t *tmp, content_t *content2)
{
    if (strcmp(tmp->name, "speciesReference") == 0) {
        if (get_reaction_element(tmp, content2) != NULL)
            return (tmp);
    }
    return (NULL);
}

element_t *is_reaction(data_t *data, element_t *element)
{
    element_t *tmp = data->elements;
    content_t *content2 = element->content;

    for (; content2 && strcmp(content2->name, "id") != 0;
    content2 = content2->next);
    for (; tmp; tmp = tmp->next) {
        if (get_element(tmp, content2) == NULL)
            continue;
        return (tmp);
    }
    return (NULL);
}
