/*
** EPITECH PROJECT, 2022
** sbmlparser
** File description:
** reactions_build_utils.c
*/

#include "sbmlparser.h"

char *get_reaction_name(char *tag)
{
    char *name = NULL;
    int i = 0;
    int size = 0;

    for (; tag[i] && strncmp(&tag[i], "name=\"", 6) != 0; i++);
    i += 6;
    for (; tag[i + size] && tag[i + size] != '\"'; size++);
    name = malloc(sizeof(char) * (size + 1));
    for (int j = 0; j < size; j++)
        name[j] = tag[i + j];
    name[size] = '\0';
    return (name);
}

char *get_reaction_id(char *tag)
{
    char *id = NULL;
    int i = 0;
    int size = 0;

    for (; tag[i] && strncmp(&tag[i], "id=\"", 4) != 0; i++);
    i += 4;
    for (; tag[i + size] && tag[i + size] != '\"'; size++);
    id = malloc(sizeof(char) * (size + 1));
    for (int j = 0; j < size; j++)
        id[j] = tag[i + j];
    id[size] = '\0';
    return (id);
}

bool is_reversible(char *tag)
{
    int i = 0;

    for (; tag[i] && strncmp(&tag[i], "reversible=\"", 11) != 0; i++);
    i += 11;
    if (!strncmp(&tag[i], "\"true", 5))
        return (true);
    return (false);
}

void create_reaction_node(data_t *data, char *tag)
{
    reaction_t *tmp = malloc(sizeof(reaction_t));

    tmp->name = get_reaction_name(&tag[9]);
    tmp->id = get_reaction_id(&tag[9]);
    tmp->reversible = (is_reversible(&tag[9])) ? true : false;
    tmp->reactants = NULL;
    tmp->products = NULL;
    tmp->next = data->reactions;
    data->reactions = tmp;
}

size_t tab_len(char **tab)
{
    size_t i = 0;

    if (tab == NULL)
        return (0);
    while (tab[i])
        i++;
    return (i);
}
