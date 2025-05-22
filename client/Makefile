##
## EPITECH PROJECT, 2024
## B-NWP-400-REN-4-1-myteams-hugo.murat
## File description:
## Makefile
##

MAKEFLAGS	=	--no-print-directory

SRC	=	\
	src/main.c	\
	src/args.c	\
	src/connection.c	\
	src/commands_gestion.c	\
	src/parsing.c	\
	src/handle_response.c	\
	src/response_handlers.c	\
	\
	src/utils/exit.c	\
	src/utils/help.c	\

BUILD	=	build

OBJ	=	$(SRC:%.c=$(BUILD)/%.o)

INC	=	-I./include -I../libs/myteams

CFLAGS	=	-luuid -L../libs/myteams -lmyteams -W -Wall -Wextra -Werror -g

NAME	=	myteams_cli

DIE	=	exit 1

%.c:
	@echo -e "\033[1;31mFile not found: $@\033[0m" && $(DIE)

$(BUILD)/%.o: %.c
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) $(INC) -c $< -o $@ || $(DIE)

all:	$(NAME)

$(NAME):	$(OBJ)
	@gcc -o $(NAME) $(OBJ) $(CFLAGS) $(INC)
	@echo -e "\033[1;36m[$(NAME)]: Successfully build\033[0m"
	@echo -e "\033[1;36mCompiled $(shell echo "$?" | wc -w) file(s)\033[0m"

clean:
	@rm -f $(OBJ)
	@echo -e "\033[1;33m[$(NAME)]: Object files successfully cleaned\033[0m"

fclean:	clean
	@rm -f $(NAME)
	@echo -e "\033[1;33m[$(NAME)]: Binary file successfully cleaned\033[0m"

re:	fclean all

.PHONY:	all clean fclean re
