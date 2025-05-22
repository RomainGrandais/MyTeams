##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## Makefile for my_teams
##

MAKEFLAGS	=	--no-print-directory

SERV_BIN	=	myteams_server

CLI_BIN		=	myteams_cli

all:
	@make -C server
	@make -C client
	@cp server/$(SERV_BIN) .
	@cp client/$(CLI_BIN) .

clean:
	@make clean -C server
	@make clean -C client

fclean:
	@make fclean -C server
	@make fclean -C client
	@rm -f $(SERV_BIN)
	@rm -f $(CLI_BIN)

re:
	@make re -C server
	@make re -C client
	@cp server/$(SERV_BIN) .
	@cp client/$(CLI_BIN) .

.PHONY:	all clean fclean re
