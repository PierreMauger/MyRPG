##
## EPITECH PROJECT, 2020
## Base
## File description:
## Main Makefile
##

SRC			=	src/fight/anim_elems/anim_all.c				\
				src/fight/anim_elems/anim_mons.c			\
				src/fight/anim_elems/move_rect.c			\
				src/fight/db_elems/db_mons.c				\
				src/fight/db_elems/db_skill.c				\
				src/fight/destroy_elems/destroy_fight.c		\
				src/fight/destroy_elems/destroy_ind.c		\
				src/fight/destroy_elems/destroy_mons.c		\
				src/fight/destroy_elems/destroy_set.c		\
				src/fight/destroy_elems/destroy_shader.c	\
				src/fight/destroy_elems/destroy_skill.c		\
				src/fight/destroy_elems/destroy_status.c	\
				src/fight/draw_elems/draw_fight.c			\
				src/fight/draw_elems/draw_attack.c			\
				src/fight/draw_elems/draw_ind.c				\
				src/fight/draw_elems/draw_mons.c			\
				src/fight/draw_elems/draw_skill.c			\
				src/fight/fight_elems/atb.c					\
				src/fight/fight_elems/attack_hit.c			\
				src/fight/fight_elems/cooldown.c			\
				src/fight/fight_elems/fight_loop.c			\
				src/fight/fight_elems/kill.c				\
				src/fight/fight_elems/passive.c				\
				src/fight/fight_elems/turn.c				\
				src/fight/fight_elems/update_fight.c		\
				src/fight/get_elems/get_event_fight.c		\
				src/fight/get_elems/get_skill.c				\
				src/fight/init_elems/init_fight.c			\
				src/fight/init_elems/init_ind.c				\
				src/fight/init_elems/init_mons.c			\
				src/fight/init_elems/init_shader.c			\
				src/fight/init_elems/init_set.c				\
				src/fight/init_elems/init_status.c			\
				src/fight/init_elems/init_text.c			\
				src/fight/set_elems/set_attack_anim_pos.c	\
				src/fight/set_elems/set_attack.c			\
				src/fight/set_elems/set_texture_mons.c		\
				src/parser/json_parser.c					\
				src/game/init_elems/init_game.c				\
				src/game/init_elems/init_time.c				\
				src/game/init_elems/init_window.c			\
				src/game/game_elems/main_loop.c				\
				src/game/game_elems/start_fight.c			\
				src/game/get_elems/get_event.c				\
				src/game/destroy_elems/destroy_game.c		\
				src/game/destroy_elems/destroy_time.c		\
				src/game/destroy_elems/destroy_window.c		\

SRC_MAIN	=	main.c				\

SRC_TEST	=	tests/test_main.c	\

NAME		=	my_rpg

NAME_TEST	=	unit_tests

OBJ			=	$(SRC:.c=.o)

OBJ_MAIN	=	$(SRC_MAIN:.c=.o)

OBJ_TEST	=	$(SRC_TEST:.c=.o)

CFLAGS		=	-L lib/my -I include -lblib -lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio

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
