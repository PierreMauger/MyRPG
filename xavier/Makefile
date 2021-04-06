##
## EPITECH PROJECT, 2020
## makefile
## File description:
## compil
##

SRCS =	map_main.c \
		obstacle.c \

OBJS = $(SRCS:.c=.o)

NAME = move_map

all : $(NAME)

$(NAME) :
	gcc -g -o $(NAME) $(SRCS) -lcsfml-graphics -lcsfml-audio -lcsfml-system -lcsfml-window -I include/

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all

x:
	gcc -o $(NAME) $(SRCS) -lcsfml-graphics -lcsfml-audio -lcsfml-system -lcsfml-window -I include/
	clear