/*
** EPITECH PROJECT, 2022
** sbmlparser
** File description:
** reactions_build2.c
*/

#include "sbmlparser.h"

void add_reactant2
        (data_t *data, content_t *content, char *species, element_t *tmp2)
{
    if (strcmp(content->name, "id") == 0)
        if (strcmp(content->value, species) == 0)
            data->reactions->reactants = cpy_element(
                    data->reactions->reactants, tmp2);
}

void add_reactant(data_t *data, char *tag, element_t *list)
{
    char *species = get_species(tag);
    element_t *tmp2 = list;

    for (; tmp2; tmp2 = tmp2->next) {
        for (content_t *content = tmp2->content; content;
        content = content->next)
            add_reactant2(data, content, species, tmp2);
    }
}

void add_product2
        (data_t *data, content_t *content, char *species, element_t *tmp2)
{
    if (strcmp(content->name, "id") == 0)
        if (strcmp(content->value, species) == 0)
            data->reactions->products = cpy_element(
                    data->reactions->products, tmp2);
}

void add_product(data_t *data, char *tag, element_t *list)
{
    char *species = get_species(tag);
    element_t *tmp2 = list;

    for (; tmp2; tmp2 = tmp2->next) {
        for (content_t *content = tmp2->content; content;
        content = content->next)
            add_product2(data, content, species, tmp2);
    }
}
