##
## EPITECH PROJECT, 2023
## palindrome
## File description:
## Makefile
##

CC ?=	gcc

SRC = 	src/error.c \
		src/palindrome.c \
		src/wraper.c \
		src/wrapper_p.c \
		src/palindrome_p.c

TU_SRC = 	tests/test_palindrome.c

OBJ =	$(SRC:.c=.o)
TU_OBJ =	$(TU_SRC:.c=.o)

MAIN =	src/main.c

OBJ_MAIN =	$(MAIN:.c=.o)

NAME =	palindrome
TU_NAME =		unit_tests

EXEC = ./$(NAME)
TU_EXEC = ./$(TU_NAME)

VALGRIND_PARAMS ?= '-h'

CFLAGS = -Wall -Wextra -g3
CPPFLAGS = -iquote include

GCOVR = gcovr --exclude tests/

MKDIR = mkdir -p

all: $(NAME)


$(NAME): 	$(OBJ) $(OBJ_MAIN)
			$(CC) $(OBJ_MAIN) $(OBJ) -o $(NAME) $(CFLAGS)

clean:
		$(RM) $(OBJ) $(MAIN:.c=.o) $(TU_OBJ) $(TU_NAME) *gc*

fclean: clean
		$(RM) $(NAME) vg*

re: fclean
	$(MAKE) all

valgrind: 	re
			valgrind $(EXEC) $(VALGRIND_PARAMS)

unit_tests: CFLAGS += --coverage
unit_tests: LDLIBS += -lcriterion
unit_tests: $(SRC) $(TU_SRC) lib
			$(CC) -o $(TU_NAME) $(SRC) $(TU_SRC) $(LDFLAGS) $(LDLIBS) \
			$(CFLAGS) $(CPPFLAGS)

tests_run: 	unit_tests
			$(TU_EXEC)
			$(GCOVR) --branches

.PHONY: all lib clean fclean re valgrind unit_tests tests_run tests_coverage
