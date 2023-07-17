/*
** EPITECH PROJECT, 2022
** sbmlparser
** File description:
** json_display.c
*/

#include "sbmlparser.h"

void json_display2(element_t *tmp, bool *not_first)
{
    if (*not_first)
        printf(",\n\t{\n");
    else {
        printf("\t{\n");
        *not_first = true;
    }
    for (content_t *content = tmp->content; content != NULL;
    content = content->next) {
        printf("\t\t\"%s\": \"%s\"", content->name, content->value);
        if (content->next != NULL)
            printf(",\n");
    }
    printf("\n\t}");
}

int json_display
(data_t *data, element_t *list, bool valid(data_t *, element_t *))
{
    element_t *tmp = list;
    bool not_first = false;
    int ret = 0;

    for (; tmp; tmp = tmp->next) {
        if (valid(data, tmp)) {
            json_display2(tmp, &not_first);
            ret = 1;
        }
    }
    return (ret);
}

void json_display_reaction3(content_t *content)
{
    if (!strcmp(content->name, "species") ||
    !strcmp(content->name, "stoichiometry")) {
        printf("\t\t\"%s\": \"%s\"", content->name, content->value);
        if (content->next != NULL)
            printf(",\n");
    }
}

void json_display_reaction2(element_t *tmp, bool *not_first)
{
    if (*not_first)
        printf(",\n\t{\n");
    else {
        printf("\t{\n");
        *not_first = true;
    }
    for (content_t *content = tmp->content; content != NULL;
    content = content->next)
        json_display_reaction3(content);
    printf("\n\t}");
}

int json_display_react
(data_t *data, element_t *list, element_t *valid(data_t *, element_t *))
{
    element_t *tmp = list;
    element_t *to_display = NULL;
    bool not_first = false;
    int ret = 0;

    for (; tmp; tmp = tmp->next) {
        to_display = valid(data, tmp);
        json_display_reaction2(to_display, &not_first);
        ret = 1;
    }
    return (ret);
}
