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
				src/fight/draw_elems/draw_attack.c			\
				src/fight/draw_elems/draw_fight.c			\
				src/fight/draw_elems/draw_ind.c				\
				src/fight/draw_elems/draw_mons.c			\
				src/fight/draw_elems/draw_skill.c			\
				src/fight/draw_elems/draw_status.c			\
				src/fight/fight_elems/atb.c					\
				src/fight/fight_elems/attack_hit.c			\
				src/fight/fight_elems/cooldown.c			\
				src/fight/fight_elems/fight_loop.c			\
				src/fight/fight_elems/kill.c				\
				src/fight/fight_elems/level_up.c			\
				src/fight/fight_elems/passive.c				\
				src/fight/fight_elems/status_apply.c		\
				src/fight/fight_elems/status_reduce.c		\
				src/fight/fight_elems/turn.c				\
				src/fight/fight_elems/update_fight.c		\
				src/fight/get_elems/get_event_fight.c		\
				src/fight/get_elems/get_skill.c				\
				src/fight/init_elems/init_fight.c			\
				src/fight/init_elems/init_ind.c				\
				src/fight/init_elems/init_mons.c			\
				src/fight/init_elems/init_set.c				\
				src/fight/init_elems/init_shader.c			\
				src/fight/init_elems/init_status.c			\
				src/fight/init_elems/init_text.c			\
				src/fight/set_elems/set_attack_anim_pos.c	\
				src/fight/set_elems/set_attack.c			\
				src/fight/set_elems/set_texture_mons.c		\
				src/game/init_elems/init_game.c				\
				src/game/init_elems/init_time.c				\
				src/game/init_elems/init_window.c			\
				src/game/init_elems/init_map.c			 	\
				src/game/init_elems/init_text.c			 	\
				src/game/init_elems/init_menu.c			 	\
				src/game/init_elems/init_rectangle.c		\
				src/game/game_elems/main_loop.c				\
				src/game/game_elems/start_fight.c			\
				src/game/get_elems/get_event.c				\
				src/game/destroy_elems/destroy_game.c		\
				src/game/destroy_elems/destroy_time.c		\
				src/game/destroy_elems/destroy_menu.c		\
				src/game/destroy_elems/destroy_window.c		\
				src/game/pause/pause.c						\
				src/game/pause/display_pause_elem.c			\
				src/game/save/save_elem.c					\
				src/game/save/load_save.c					\
				src/parser/json_parser.c					\
				src/parser/parser_write.c					\
				src/quest/destroy_elems/destroy_quest.c		\
				src/quest/draw_elems/draw_quest_text.c		\
				src/quest/init_elems/init_quest.c			\
				src/inventory/inventory.c					\
				src/inventory/liblist.c						\
				src/inventory/inv_events.c					\
				src/inventory/cleaning.c					\
				src/map/change_map.c						\
				src/map/chest_open.c						\
				src/map/display_map_anim.c					\
				src/map/display_sprite.c					\
				src/map/event.c								\
				src/map/free.c								\
				src/map/init_obstacle.c						\
				src/map/load_obstacle.c						\
				src/map/map_main.c							\
				src/map/pnj_interaction.c					\
				src/map/pnj.c								\
				src/map/text_defil.c						\
				src/map/verif_obstacle.c					\
				src/map/my_itoa.c							\
				src/map/enemy.c								\
				src/map/victory.c							\
				src/map/music.c								\
				src/map/enemy_fight.c						\
				src/inventory/drawing.c						\
				src/inventory/drawing_utils.c				\
				src/inventory/stats.c						\
				src/menu/parallax.c							\
				src/menu/menu_loop.c						\
				src/menu/button_system.c 					\
				src/menu/main_menu.c 						\
				src/menu/menu_button_part.c 				\
				src/menu/system_font.c 						\
				src/menu/button_creation.c 					\


SRC			+=	src/main.c				\

SRC_TEST	=	tests/test_main.c	\

NAME		=	my_rpg

NAME_TEST	=	unit_tests

OBJ			=	$(SRC:.c=.o)

OBJ_TEST	=	$(SRC_TEST:.c=.o)

CFLAGS		=	-L lib/my -I include -lblib -lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio -Wall -Wextra -W

CFLAGS_TEST	=	--coverage -lcriterion -I include

CFLAGS_DEBUG=	-g

$(NAME):	$(OBJ)
	@(make -C lib/my) > /dev/null
	@(g++ $(OBJ) -o $(NAME) $(CFLAGS)) > /dev/null

all:	$(NAME)

clean:
	@(make clean -C lib/my) > /dev/null
	@(rm -f $(OBJ)) > /dev/null
	@find . -name "*.gcno" -delete
	@find . -name "*.gcda" -delete
	@find . -name "*.o" -delete

fclean:	clean
	@(make fclean -C lib/my) > /dev/null
	@(rm -f $(NAME) $(NAME_TEST)) > /dev/null
	@(rm -rf tests/coverage) > /dev/null

re:	fclean all

debug:
	make -C lib/my
	gcc $(SRC) -o $(NAME) $(CFLAGS) $(CFLAGS_DEBUG)

tests_run:	fclean $(OBJ_TEST)
	@(make -C lib/my) > /dev/null
	@(gcc -o $(NAME_TEST) $(OBJ_TEST) $(SRC) $(CFLAGS_TEST) $(CFLAGS)) > /dev/null
	./$(NAME_TEST)
