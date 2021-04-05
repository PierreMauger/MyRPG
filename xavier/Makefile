##
## EPITECH PROJECT, 2020
## makefile
## File description:
## compil
##

SRCS =	main.c \
		text_defil.c \

OBJS = $(SRCS:.c=.o)

NAME = text

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
	make -C lib/my
	gcc -o $(NAME) $(SRCS) -lcsfml-graphics -lcsfml-audio -lcsfml-system -lcsfml-window -L lib/ -lmy -I include/
	make clean -C lib/my
	clear