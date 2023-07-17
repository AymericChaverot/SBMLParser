/*
** EPITECH PROJECT, 2022
** sbmlparser
** File description:
** json_containers_utils.c
*/

#include "sbmlparser.h"

bool check_id(data_t *data, element_t *element)
{
    for (content_t *content = element->content; content != NULL;
    content = content->next) {
        if (strcmp(content->name, "id") == 0 &&
            strcmp(content->value, data->flag_id) == 0)
            return (true);
    }
    return (false);
}

bool is_correct_compartment(data_t *data, element_t *element)
{
    if (strncmp(element->name, "compartment", 11) == 0) {
        if (check_id(data, element))
            return (true);
    }
    return (false);
}

bool check_compartment(data_t *data, element_t *element)
{
    for (content_t *content = element->content; content != NULL;
    content = content->next) {
        if (strcmp(content->name, "compartment") == 0 &&
            strcmp(content->value, data->flag_id) == 0)
            return (true);
    }
    return (false);
}

bool is_correct_species(data_t *data, element_t *element)
{
    if (strncmp(element->name, "species", 7) == 0)
        if (check_compartment(data, element))
            return (true);
    return (false);
}

bool is_correct_reaction(data_t *data, element_t *element)
{
    if (strncmp(element->name, "reaction", 8) == 0) {
        if (check_compartment(data, element))
            return (true);
    }
    return (false);
}
