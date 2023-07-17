/*
** EPITECH PROJECT, 2022
** sbmlparser
** File description:
** simple_parser.c
*/

#include "sbmlparser.h"

void mark_as_displayed(element_t *list, char *name)
{
    element_t *tmp = list;

    for (; tmp; tmp = tmp->next)
        if (strcmp(tmp->name, name) == 0)
            tmp->disp = 1;
}

char **dup_tab(char **tab)
{
    char **new = malloc(sizeof(char *) * (tab_len(tab) + 1));
    int i = 0;

    if (new == NULL)
        return (NULL);
    for (; tab[i]; i++)
        new[i] = strdup(tab[i]);
    new[i] = NULL;
    return (new);
}

void swap_tab(char **tmp2, int i, int j)
{
    if (strcmp(tmp2[i], tmp2[j]) > 0) {
        char *tmp = tmp2[i];
        tmp2[i] = tmp2[j];
        tmp2[j] = tmp;
    }
}

char **order_alpha(char **tab)
{
    char **tmp2 = dup_tab(tab);

    for (int i = 1; tmp2[i]; i++) {
        for (int j = i + 1; tmp2[j]; j++) {
            swap_tab(tmp2, i, j);
        }
    }
    return (tmp2);
}

void simple_parser(char *filepath)
{
    char **tags = extract_tags(read_file(filepath));
    element_t *list = make_list(order_alpha(tags));
    display_only_args_elems(list);
    for (element_t *tmp2 = list; list; list = tmp2) {
        free(list->name);
        content_t *tmp3;
        for (content_t *tmp = list->content; tmp; tmp = tmp3) {
            free(tmp->name);
            tmp3 = tmp->next;
            free(tmp);
        }
        tmp2 = list->next;
        free(list);
    }
    for (int i = 0; tags[i]; i++)
        free(tags[i]);
    free(tags);
}
