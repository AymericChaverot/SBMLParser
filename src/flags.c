/*
** EPITECH PROJECT, 2022
** sbmlparser
** File description:
** flags.c
*/

#include "sbmlparser.h"

void get_flag_i(data_t *data, int ac, char **av, int *i)
{
    data->flag_i = true;
    if (*i + 1 < ac && av[*i + 1][0] != '-') {
        data->flag_id = strdup(av[*i + 1]);
        *i += 1;
    } else
        data->flag_id = strdup("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa");
}

data_t *init_flags(void)
{
    data_t *data = malloc(sizeof(data_t));

    data->flag_i = false;
    data->flag_e = false;
    data->flag_json = false;
    data->flag_id = NULL;
    data->flag_id_cpy = NULL;
    data->flag_id_type = NULL;
    data->filepath = NULL;
    data->elements = NULL;
    data->reactions = NULL;
    return (data);
}

data_t *get_flags(int ac, char **av)
{
    data_t *data = init_flags();

    for (int i = 1; i < ac; i++) {
        if (my_strcmp(av[i], "-i") == 0) {
            get_flag_i(data, ac, av, &i);
            continue;
        }
        if (my_strcmp(av[i], "-e") == 0) {
            data->flag_e = true;
            continue;
        }
        if (my_strcmp(av[i], "-json") == 0) {
            data->flag_json = true;
            continue;
        }
        if (my_strcmp(av[i], "-h") == 0)
            print_help();
        data->filepath = strdup(av[i]);
    }
    return (data);
}
