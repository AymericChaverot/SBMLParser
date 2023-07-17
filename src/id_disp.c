/*
** EPITECH PROJECT, 2022
** sbmlparser
** File description:
** id_disp.c
*/

#include "sbmlparser.h"

void display_id_compartment2
(data_t *data, element_t *tmp, char **name, bool *valid)
{
    for (content_t *content = tmp->content; content;
    content = content->next) {
        if (content_check(data, content, name, valid))
            break;
    }
}

void display_id_compartment(data_t *data, element_t *list)
{
    char *name = NULL;
    bool valid = false;

    printf("List of species in compartment %s\n", data->flag_id);
    for (element_t *tmp = list; tmp; tmp = tmp->next) {
        if (strcmp(tmp->name, "species") == 0)
            display_id_compartment2(data, tmp, &name, &valid);
        if (name != NULL) {
            free(name);
            name = NULL;
        }
    }
}

void display_species2(element_t *tmp)
{
    for (content_t *content = tmp->content; content;
    content = content->next) {
        if (!strcmp(content->name, "name")) {
            printf("--->%s\n", content->value);
            break;
        }
    }
}

void display_species(element_t *list)
{
    printf("List of species\n");
    for (element_t *tmp = list; tmp; tmp = tmp->next) {
        if (strcmp(tmp->name, "species") == 0) {
            display_species2(tmp);
        }
    }
}

void display_id_species2(data_t *data, element_t *element, int *count)
{
    for (content_t *content = element->content; content != NULL;
    content = content->next) {
        if (!strcmp(content->name, "id") &&
            !strcmp(content->value, data->flag_id)) {
            *count += 1;
        }
    }
}
