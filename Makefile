##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## makefile root my_ls
##

SRC	=	main.c	\
		my_ls.c

NAME	=	my_ls

all:	$(NAME)

libmy:
	@make -sC lib/my/

$(NAME):	libmy
	@gcc -o $(NAME) $(SRC) -L./lib -lmy -g3
	@echo -e "\033[05m\033[32mCompilation done => ${NAME}\033[00m"

clean:
	@rm -f *~
	@make -sC lib/my clean
	@rm -f vgcor.*

fclean:	clean
	@rm -f $(NAME)
	@make -sC lib/my/ fclean
	clear

re:	fclean all
