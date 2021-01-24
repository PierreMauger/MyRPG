##
## EPITECH PROJECT, 2020
## Base
## File description:
## Main Makefile
##

SRC			=	src/game.c			\
				src/play.c			\
				src/mons.c			\
				src/mons_list.c		\
				src/turn.c			\
				src/ind.c			\

SRC_MAIN	=	main.c				\

SRC_TEST	=	tests/test_main.c	\

NAME		=	game

NAME_TEST	=	unit_tests

OBJ			=	$(SRC:.c=.o)

OBJ_MAIN	=	$(SRC_MAIN:.c=.o)

OBJ_TEST	=	$(SRC_TEST:.c=.o)

CFLAGS		=	-L lib/my -I include -lmy -lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio

CFLAGS_TEST	=	--coverage -lcriterion -I include

CFLAGS_DEBUG=	-Wall -Wextra -W -g

ECHO =	/bin/echo -e

GREEN =	"\033[1;32m"

DEFAULT =	"\033[00m"

CLEAR =	"\033[H\033[2J"

$(NAME):	$(OBJ) $(OBJ_MAIN)
	@(make -C lib/my) > /dev/null
	@(gcc $(OBJ) $(OBJ_MAIN) -o $(NAME) $(CFLAGS)) > /dev/null

all:	$(NAME)

clean:
	@(make clean -C lib/my) > /dev/null
	@(rm -f $(OBJ) $(OBJ_MAIN)) > /dev/null
	@find . -name "*.gcno" -delete
	@find . -name "*.gcda" -delete
	@find . -name "*.o" -delete

fclean:	clean
	@(make fclean -C lib/my) > /dev/null
	@(rm -f $(NAME) $(NAME_TEST)) > /dev/null
	@(rm -rf tests/coverage) > /dev/null
	@$(ECHO) $(CLEAR)

re:	fclean all

debug:
	make -C lib/my
	gcc $(SRC) $(SRC_MAIN) -o $(NAME) $(CFLAGS) $(CFLAGS_DEBUG)

tests_run:	fclean $(OBJ_TEST)
	@(make -C lib/my) > /dev/null
	@(gcc -o $(NAME_TEST) $(OBJ_TEST) $(SRC) $(CFLAGS_TEST) $(CFLAGS)) > /dev/null
	./$(NAME_TEST)

gcovr: tests_run
	@$(ECHO) $(CLEAR)
	@$(ECHO) $(GREEN) "LINES:\n" $(DEFAULT)
	@gcovr --exclude tests
	@$(ECHO) $(GREEN) "\nBRANCHING:\n" $(DEFAULT)
	@gcovr --exclude tests --branch

gen_html: tests_run
	@(mkdir -p tests/coverage) > /dev/null
	@(lcov -c -d . --output-file tests/coverage/lcov) > /dev/null
	@(genhtml tests/coverage/lcov --output-directory tests/coverage) > /dev/null

html_run: gen_html
	@(firefox tests/coverage/index.html) > /dev/null
