/*
** EPITECH PROJECT, 2022
** sbmlparser
** File description:
** json_species_utils.c
*/

#include "sbmlparser.h"

bool check_species_content(data_t *data, element_t *tmp)
{
    for (content_t *content = tmp->content; content != NULL;
    content = content->next) {
        if (!strcmp(content->name, "id") &&
            !strcmp(content->value, data->flag_id))
            return (true);
    }
    return (false);
}

bool is_species_species(data_t *data, element_t *element)
{
    element_t *tmp = element;

    if (!strcmp(tmp->name, "species") && check_species_content(data, tmp))
        return (true);
    return (false);
}

bool is_species_reaction2
(data_t *data, reaction_t *reaction)
{
    if (!reaction)
        return (false);
    for (element_t *tmp = reaction->reactants; tmp; tmp = tmp->next) {
        if (is_species_species(data, tmp))
            return (true);
    }
    for (element_t *tmp = reaction->products; tmp; tmp = tmp->next) {
        if (is_species_species(data, tmp))
            return (true);
    }
    return (false);
}

bool is_species_reaction(data_t *data, element_t *element)
{
    content_t *tmp2 = element->content;
    reaction_t *reaction = data->reactions;
    char *id = NULL;
    if (!strcmp(element->name, "reaction")) {
        for (; tmp2 && strcmp(tmp2->name, "id") != 0; tmp2 = tmp2->next);
        if (tmp2)
            id = strdup(tmp2->value);
        else
            return (false);
        for (; reaction && strcmp(reaction->id, id) != 0;
        reaction = reaction->next);
        return (is_species_reaction2(data, reaction));
    }
    return (false);
}
