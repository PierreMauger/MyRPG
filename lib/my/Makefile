##
## EPITECH PROJECT, 2020
## Blib
## File description:
## Makefile
##

SRC		=	print/bfprintf/bfprint_char.c			\
			print/bfprintf/bfprint_nbr.c			\
			print/bfprintf/bfprint_str.c			\
			print/bfprintf/bfprintf.c				\
			print/bprintf/bprint_char.c				\
			print/bprintf/bprint_nbr.c				\
			print/bprintf/bprint_str.c				\
			print/bprintf/bprintf.c					\
			string/bstrlen.c						\
			string/bstrcmp.c						\
			string/bstrncmp.c						\
			string/bstrdup.c						\
			string/bstrndup.c						\
			string/bstrcat.c						\
			string/bstrncat.c						\
			string/bmemset.c						\
			string/bstrcpy.c						\
			string/bstrncpy.c						\
			string/brevstr.c						\
			string/bitoa.c							\
			string/batoi.c							\
			array/binit_array.c						\
			array/bstr_array.c						\
			array/badd_array.c						\
			array/barray_len.c						\
			array/barray_dup.c						\
			file/bread_file.c						\
			memory/calloc.c							\

OBJ		=	$(SRC:.c=.o)

CFLAGS	=	-I include -W -g

NAME	=	libblib.a

BUILDNAME	=	build

$(NAME):	$(OBJ)
	@ar rc $(NAME) $(OBJ)
	@cp include/blib.h ../../include
	@cp include/barray.h ../../include
	@cp include/bfile.h ../../include
	@cp include/bmemory.h ../../include
	@cp include/bprint.h ../../include
	@cp include/bstring.h ../../include
	@cp $(NAME) ../

all:	$(NAME)

clean:
	@rm -f $(OBJ)

fclean:	clean
	@rm -f $(NAME)
	@rm -f ../$(NAME)

re:	fclean all
