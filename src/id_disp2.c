/*
** EPITECH PROJECT, 2022
** sbmlparser
** File description:
** id_disp2.c
*/

#include "sbmlparser.h"

void display_id_species(data_t *data)
{
    int count = 0;
    printf("List of reactions consuming species %s (quantities)\n",
    data->flag_id);
    for (reaction_t *tmp = data->reactions; tmp != NULL; tmp = tmp->next) {
        for (element_t *element = tmp->reactants; element != NULL;
        element = element->next) {
            display_id_species2(data, element, &count);
        }
        if (count > 0) {
            printf("--->%s (%d)\n", tmp->id, count);
            count = 0;
        }
    }
}

void display_id_reaction3(element_t *element)
{
    for (content_t *content = element->content; content != NULL;
    content = content->next) {
        if (!strcmp(content->name, "id")) {
            printf("--->%s\n", content->value);
        }
    }
}

void display_id_reaction2(reaction_t *tmp)
{
    for (element_t *element = tmp->products; element != NULL;
    element = element->next) {
        display_id_reaction3(element);
    }
}

void display_id_reaction4(element_t *element)
{
    for (content_t *content = element->content; content != NULL;
    content = content->next) {
        if (!strcmp(content->name, "id")) {
            printf("--->%s\n", content->value);
        }
    }
}

void display_id_reaction(data_t *data)
{
    reaction_t *tmp = data->reactions;

    for (; tmp && strcmp(tmp->id, data->flag_id) != 0; tmp = tmp->next);
    if (tmp == NULL)
        return;
    printf("List of reactants of reaction %s\n", tmp->id);
    for (element_t *element = tmp->reactants; element != NULL;
    element = element->next) {
        display_id_reaction4(element);
    }
    printf("List of products of reaction %s\n", tmp->id);
    display_id_reaction2(tmp);
}
