##
## EPITECH PROJECT, 2024
## B-NWP-400-REN-4-1-myteams-hugo.murat
## File description:
## Makefile
##

MAKEFLAGS	=	--no-print-directory

SRC	=	\
	src/main.c			\
	src/args.c			\
	src/socket.c		\
	src/connection.c	\
	src/client.c		\
	\
	src/server/run_server.c		\
	src/server/close_server.c	\
	\
	src/list/add_client.c		\
	src/list/remove_client.c	\
	\
	src/utils/exit.c		\
	src/utils/help.c		\
	src/utils/split_str.c	\
	src/utils/parsing.c		\
	src/utils/warray.c		\
	src/utils/stringify.c	\
	src/utils/uuid.c		\
	\
	src/commands/help.c		\
	src/commands/login.c	\
	src/commands/logout.c	\
	src/commands/users.c	\
	src/commands/user.c		\
	src/commands/send.c		\
	src/commands/messages.c	\
	\
	src/database/free_database.c				\
	src/database/database_utils.c				\
	src/database/database.c 					\
	src/database/database_to_file.c				\
	src/database/database_save.c				\
	src/database/fillers/fill_team.c			\
	src/database/fillers/fill_channel.c			\
	src/database/fillers/fill_thread.c			\
	src/database/fillers/fill_thread_reply.c	\
	src/database/fillers/fill_user.c			\
	src/database/fillers/fill_message.c			\
	src/database/fillers/fill_team_link.c 		\
	src/database/getters/get_channel.c			\
	src/database/getters/get_message.c			\
	src/database/getters/get_team_link.c		\
	src/database/getters/get_team.c				\
	src/database/getters/get_thread_reply.c		\
	src/database/getters/get_thread.c			\
	src/database/getters/get_user.c				\
	src/database/setters/add_channel.c			\
	src/database/setters/add_message.c			\
	src/database/setters/add_team_link.c		\
	src/database/setters/add_team.c				\
	src/database/setters/add_thread_reply.c		\
	src/database/setters/add_thread.c			\
	src/database/setters/add_user.c				\

BUILD	=	build

OBJ	=	$(SRC:%.c=$(BUILD)/%.o)

INC	=	-I./include -I../libs/myteams

CFLAGS	=	-luuid -L../libs/myteams -lmyteams -W -Wall -Wextra -Werror -g

NAME	=	myteams_server

DIE	=	exit 1

%.c:
	@echo -e "\033[1;31mFile not found: $@\033[0m" && $(DIE)

$(BUILD)/%.o: %.c
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) $(INC) -c $< -o $@ || $(DIE)

all:	$(NAME)

$(NAME):	$(OBJ)
	@gcc -o $(NAME) $(OBJ) $(INC) $(CFLAGS)
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
