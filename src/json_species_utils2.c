/*
** EPITECH PROJECT, 2022
** sbmlparser
** File description:
** json_species_utils2.c
*/

#include "sbmlparser.h"

int get_compartment_value2(data_t *data, element_t *tmp)
{
    for (content_t *content2 = tmp->content; content2 != NULL;
    content2 = content2->next) {
        if (!strcmp(content2->name, "compartment")) {
            data->flag_id_cpy = strdup(data->flag_id);
            data->flag_id = strdup(content2->value);
            return (1);
        }
    }
    return (0);
}

int get_compartment_value(data_t *data, content_t *content, element_t *tmp)
{
    if (!strcmp(content->name, "id") &&
        !strcmp(content->value, data->flag_id)) {
        if (get_compartment_value2(data, tmp) == 1)
            return (1);
    }
    return (0);
}

void species_compartment2(data_t *data, element_t *tmp)
{
    for (content_t *content = tmp->content; content != NULL;
    content = content->next) {
        get_compartment_value(data, content, tmp);
        if (data->flag_id_cpy)
            break;
    }
}

bool is_species_compartment(data_t *data, element_t *element)
{
    element_t *tmp = data->elements;

    for (; tmp; tmp = tmp->next) {
        if (!strncmp(tmp->name, "species", 7))
            species_compartment2(data, tmp);
        if (data->flag_id_cpy)
            break;
    }
    return (is_correct_compartment(data, element));
}
