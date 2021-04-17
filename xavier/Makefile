##
## EPITECH PROJECT, 2020
## makefile
## File description:
## compil
##

SRCS =	map_main.c \
		load_obstacle.c \
		verif_obstacle.c \
		free.c \
		change_map.c \
		display_map_anim.c \
		my_itoa.c \
		create_obs_write.c \
		display_sprite.c \

OBJS = $(SRCS:.c=.o)

NAME = move_map

all : $(NAME)

$(NAME) :
	make -C lib/my
	gcc -g -o $(NAME) $(SRCS) -lcsfml-graphics -lcsfml-audio -lcsfml-system -lcsfml-window -L lib/ -lmy -I include/
	make clean -C lib/my

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all

x:
	gcc -o $(NAME) $(SRCS) -lcsfml-graphics -lcsfml-audio -lcsfml-system -lcsfml-window -I include/
	clear