##
## EPITECH PROJECT, 2020
## Lib
## File description:
## Makefile lib
##

SRC	=	my_getnbr.c					\
		my_printf.c					\
		my_put_nbr.c				\
		my_put_nbr_base.c			\
		my_putchar.c				\
		my_putstr.c					\
		my_revstr.c					\
		my_strcat.c					\
		my_strcmp.c					\
		my_strcpy.c					\
		my_strdup.c					\
		my_strlen.c					\
		my_strncat.c				\
		my_strncmp.c				\
		my_strncpy.c				\
		my_strndup.c				\
		nbr_to_str.c				\

OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-I include/

NAME	=	libmy.a

all:	$(NAME)

$(NAME):	$(OBJ)
		cp include/my.h ../../include/
		ar rc $(NAME) $(OBJ)
		cp $(NAME) ../

clean:
		@rm -f $(OBJ)

fclean:	clean
		@rm -f $(NAME)
		@rm -f ../$(NAME)

re:	fclean all
