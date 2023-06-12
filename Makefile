##
## EPITECH PROJECT, 2023
## palindrome
## File description:
## Makefile
##

CC ?=	gcc

SRC = 	src/error.c \
		src/palindrome.c \
		src/wraper.c

OBJ =	$(SRC:.c=.o)

MAIN =	src/main.c

OBJ_MAIN =	$(MAIN:.c=.o)

NAME =	palindrome

EXEC = ./$(NAME)

VALGRIND_PARAMS ?= '-h'

CFLAGS = -Wall -Wextra -g3
CPPFLAGS = -iquote include

MKDIR = mkdir -p

all: $(NAME)


$(NAME): 	$(OBJ) $(OBJ_MAIN)
			$(CC) $(OBJ_MAIN) $(OBJ) -o $(NAME) $(CFLAGS)

clean:
		$(RM) $(OBJ) $(MAIN:.c=.o)

fclean: clean
		$(RM) $(NAME) vg*

re: fclean
	$(MAKE) all

valgrind: 	re
			valgrind $(EXEC) $(VALGRIND_PARAMS)

.PHONY: all lib clean fclean re valgrind
