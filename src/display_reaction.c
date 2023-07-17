/*
** EPITECH PROJECT, 2022
** sbmlparser
** File description:
** display_reaction.c
*/

#include "sbmlparser.h"

void test_name2(content_t *content, char **name, int *count)
{
    if (strcmp(*name, content->value) == 0)
        *count += 1;
    else {
        printf("%d %s + ", *count, *name);
        free(*name);
        *name = strdup(content->value);
        *count = 1;
    }
}

void test_name(content_t *content, char **name, int *count)
{
    if (!strcmp(content->name, "id")) {
        if (*name == NULL) {
            *name = strdup(content->value);
            *count = 1;
        } else {
            test_name2(content, name, count);
        }
    }
}

void display_reaction_equation2(reaction_t *tmp, char **name, int *count)
{
    if (tmp->reversible == true)
        printf(" <-> ");
    else
        printf(" -> ");
    for (element_t *element = tmp->products; element != NULL;
    element = element->next) {
        for (content_t *content = element->content; content != NULL;
        content = content->next) {
            test_name(content, name, count);
        }
    }
    printf("%d %s\n", *count, *name);
}

void display_reaction_equation(data_t *data)
{
    reaction_t *tmp = data->reactions;
    int count = 0;
    char *name = NULL;

    for (; tmp && strcmp(tmp->id, data->flag_id) != 0; tmp = tmp->next);
    if (tmp == NULL)
        return;
    for (element_t *element = tmp->reactants; element != NULL;
    element = element->next) {
        for (content_t *content = element->content; content != NULL;
        content = content->next) {
            test_name(content, &name, &count);
        }
    }
    printf("%d %s", count, name);
    free(name);
    name = NULL;
    display_reaction_equation2(tmp, &name, &count);
}
