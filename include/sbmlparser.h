/*
** EPITECH PROJECT, 2022
** sbmlparser
** File description:
** sbmlparser.h
*/

#ifndef SBMLPARSER_H
    #define SBMLPARSER_H

    #include <stdio.h>
    #include <stdlib.h>
    #include <unistd.h>
    #include <string.h>
    #include <fcntl.h>
    #include <sys/types.h>
    #include <sys/stat.h>
    #include <stdbool.h>

    #define BOOL char
    #define TRUE 1
    #define FALSE 0

typedef struct content_s {
    char *name;
    char *value;
    struct content_s *next;
} content_t;

typedef struct element_s {
    char *name;
    content_t *content;
    char marks_end;
    char orphan;
    char disp;
    struct element_s *next;
} element_t;

typedef struct reaction_s {
    char *name;
    char *id;
    bool reversible;
    element_t *reactants;
    element_t *products;
    struct reaction_s *next;
} reaction_t;

typedef struct data_s {
    char *filepath;
    char *flag_id;
    char *flag_id_cpy;
    char *flag_id_type;
    bool flag_i;
    bool flag_e;
    bool flag_json;
    reaction_t *reactions;
    element_t *elements;
} data_t;

// main.c
void print_help(void);

// json_reaction.c
element_t *is_reaction(data_t *data, element_t *element);

// json_specis_utils2.c
int get_compartment_value(data_t *data, content_t *content, element_t *tmp);

// json_species_utils.c
bool is_species_compartment(data_t *data, element_t *element);
bool is_species_species(data_t *data, element_t *elements);
bool is_species_reaction(data_t *data, element_t *element);

// json_containers_utils.c
bool check_compartment(data_t *data, element_t *element);
bool is_correct_compartment(data_t *data, element_t *element);
bool is_correct_species(data_t *data, element_t *element);
bool is_correct_reaction(data_t *data, element_t *element);

// json_display.c
int json_display
(data_t *data, element_t *list, bool valid(data_t *, element_t *));
int json_display_react
(data_t *data, element_t *list, element_t *valid(data_t *, element_t *));

// json_convert.c
void json_parser(data_t *data, element_t *list);

// simple_parser_utils.c
void display_only_args_elems(element_t *start);

// id_parser.c
int content_check(data_t *data, content_t *content, char **name, bool *valid);
void id_parser(data_t *data);

// linked_list_cpy.c
element_t *cpy_element(element_t *start, element_t *to_cpy);

// id_disp.c
void display_id_species2(data_t *data, element_t *element, int *count);
void display_id_compartment(data_t *data, element_t *list);
void display_species(element_t *list);
void display_id_species(data_t *data);
void display_id_reaction(data_t *data);
void display_reaction_equation(data_t *data);

// id_check.c
int id_exists(data_t *data, element_t *list);

// reactions_build_utils.c
void create_reaction_node(data_t *data, char *tag);
size_t tab_len(char **tab);

// reactions_build2.c
void add_reactant(data_t *data, char *tag, element_t *list);
void add_product(data_t *data, char *tag, element_t *list);

// reactions_build.c
char *get_species(char *tag);
void create_reactions(data_t *data, char **tags, element_t *list);

// flags.c
data_t *get_flags(int ac, char **av);

// simple_parser.c
void mark_as_displayed(element_t *list, char *name);
char **order_alpha(char **tab);
void simple_parser(char *filepath);

// utils/my_strlen.c
int my_strlen(char const *str);

// utils/my_strcmp.c
int my_strcmp(char const *s1, char const *s2);

// utils/full_tag_parsing.c
char *extract_name(char *full_tag);
content_t *get_content(char *full_tag);

// utils/elements_list.c
element_t *create_elem(element_t *start, char *full_tag);
element_t *make_list(char **tags);

// utils/alphanum.c
int is_alphanum(char c);

// utils/readfile.c
char *read_file(char *filepath);

// utils/sbml_parsing.c
char **extract_tags(char *str);

#endif //SBMLPARSER_H
