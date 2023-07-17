/*
** EPITECH PROJECT, 2022
** sbmlparser
** File description:
** reactions_build.c
*/

#include "sbmlparser.h"

char *get_species(char *tag)
{
    char *species = NULL;
    int i = 0;
    int size = 0;

    for (; tag[i] && strncmp(&tag[i], "species=\"", 9) != 0; i++);
    i += 9;
    for (; tag[i + size] && tag[i + size] != '\"'; size++);
    species = strndup(&tag[i], size);
    return (species);
}

void add_to_reaction(data_t *data, char *tag, int state, element_t *list)
{
    if (state == 0)
        return;
    if (state == 1) {
        add_reactant(data, tag, list);
    } else {
        add_product(data, tag, list);
    }
}

void get_state(data_t *data, char **tags, int i, element_t *list)
{
    int state = 0;
    for (int j = i; tags[j] &&
                    strncmp(tags[j], "/reaction", 9) != 0; j++) {
        if (strncmp(tags[j], "listOfReactants", 15) == 0) {
            state = 1;
        }
        if (strncmp(tags[j], "listOfProducts", 14) == 0) {
            state = 2;
        }
        if (strncmp(tags[j], "speciesReference", 16) == 0) {
            add_to_reaction(data, tags[j], state, list);
        }
    }
}

void create_reactions(data_t *data, char **tags, element_t *list)
{
    for (int i = 0; tags[i]; i++) {
        if (strncmp(tags[i], "reaction", 8) == 0) {
            create_reaction_node(data, tags[i]);
            get_state(data, tags, i, list);
        }
    }
}
