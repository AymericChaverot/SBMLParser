##
## EPITECH PROJECT, 2022
## my_rpg
## File description:
## Makefile
##

SRC = $(wildcard src/*.c) \
	  $(wildcard src/utils/*.c)

OBJ = $(SRC:.c=.o)

NAME = SBMLparser

CC = gcc

CFLAGS = -Wall -Werror -Wextra -I./include

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
