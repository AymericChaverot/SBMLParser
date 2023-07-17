/*
** EPITECH PROJECT, 2022
** sbmlparser
** File description:
** id_parser.c
*/

#include "sbmlparser.h"

int content_check(data_t *data, content_t *content, char **name, bool *valid)
{
    if (strcmp(content->name, "name") == 0) {
        *name = strdup(content->value);
        if (*valid == true) {
            printf("--->%s\n", *name);
            return (1);
        }
    }
    if (strcmp(content->name, data->flag_id_type) == 0 &&
        strcmp(content->value, data->flag_id) == 0) {
        if (*name == NULL)
            *valid = true;
        else {
            printf("--->%s\n", *name);
            return (1);
        }
    }
    return (0);
}

void which_reaction(data_t *data)
{
    if (data->flag_e == false)
        display_id_reaction(data);
    else
        display_reaction_equation(data);
}

void display_only_id(data_t *data, element_t *list)
{
    if (id_exists(data, list)) {
        if (!strcmp(data->flag_id_type, "compartment"))
            display_id_compartment(data, list);
        if (!strcmp(data->flag_id_type, "species"))
            display_id_species(data);
        if (!strcmp(data->flag_id_type, "reaction"))
            which_reaction(data);
    } else
        display_species(list);
}

void id_parser(data_t *data)
{
    char **tags = extract_tags(read_file(data->filepath));

    if (data->flag_json) {
        element_t *list = make_list(tags);
        create_reactions(data, tags, list);
        json_parser(data, list);
    } else {
        element_t *list = make_list(order_alpha(tags));
        create_reactions(data, tags, list);
        display_only_id(data, list);
    }
}
