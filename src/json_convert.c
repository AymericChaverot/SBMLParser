/*
** EPITECH PROJECT, 2022
** sbmlparser
** File description:
** json_convert.c
*/

#include "sbmlparser.h"

bool reaction_exists(data_t *data, element_t *list)
{
    element_t *element = list;
    for (; element; element = element->next) {
        if (strncmp(element->name, "reaction", 8) == 0 &&
        check_compartment(data, element))
                return (true);
    }
    return (false);
}

void json_display_id_compartment(data_t *data, element_t *list)
{
    printf("{\n\"listOfCompartments\": [\n");
    if (json_display(data, list, is_correct_compartment))
        printf("\n");
    printf("],\n");
    printf("\"listOfSpecies\": [\n");
    if (json_display(data, list, is_correct_species))
        printf("\n");
    if (reaction_exists(data, list)) {
        printf("],\n");
        printf("\"listOfReactions\": [\n");
        if (json_display(data, list, is_correct_reaction))
            printf("\n");
        printf("]\n}\n");
    } else
        printf("]\n}\n");
}

void json_display_id_species(data_t *data, element_t *list)
{
    data->elements = list;
    data->flag_id_cpy = NULL;
    printf("{\n\"listOfCompartments\": [\n");
    if (json_display(data, list, is_species_compartment))
        printf("\n");
    free(data->flag_id);
    data->flag_id = strdup(data->flag_id_cpy);
    data->flag_id_cpy = NULL;
    printf("],\n");
    printf("\"listOfSpecies\": [\n");
    if (json_display(data, list, is_species_species))
        printf("\n");
    printf("],\n");
    printf("\"listOfReactions\": [\n");
    if (json_display(data, list, is_species_reaction))
        printf("\n");
    printf("]\n}\n");
}

void json_display_reaction(data_t *data, element_t *list)
{
    data->elements = list;
    reaction_t *reaction = data->reactions;
    for (; reaction != NULL && strcmp(reaction->id, data->flag_id) != 0;
    reaction = reaction->next);
    printf("{\n\"listOfReactants\": [\n");
    if (reaction && json_display_react(data, reaction->reactants, is_reaction))
        printf("\n");
    printf("],\n");
    printf("\"listOfProducts\": [\n");
    if (reaction && json_display_react(data, reaction->products, is_reaction))
        printf("\n");
    printf("]\n}\n");
}

void json_parser(data_t *data, element_t *list)
{
    if (id_exists(data, list)) {
        if (!strcmp(data->flag_id_type, "compartment"))
            json_display_id_compartment(data, list);
        if (!strcmp(data->flag_id_type, "species"))
            json_display_id_species(data, list);
        if (!strcmp(data->flag_id_type, "reaction"))
            json_display_reaction(data, list);
    } else
        display_species(list);
}
