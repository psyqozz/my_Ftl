##
## ETNA PROJECT, 12/11/2018 by juzain_d
## Makefile
## File description:
##      ...
##

CC = gcc
NAME = my_ftl
RM = rm -f
CFLAGS = -Wall -Wextra -Werror -std=c99 
SRC =	main.c \
		air_shed.c	\
		my_readline.c \
		my_string.c	\
		container.c \
		system_control.c \
		system_repair.c \
		enemy.c \
		player_action.c \
		secondary_function.c

OBJ =  $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
		$(CC) $(CFLAGS) $(OBJ) -o $(NAME) 

clean:
		$(RM) $(OBJ)

fclean: clean
		$(RM) $(NAME)

re: fclean all

.PRONY: all $(NAME) clean fclean re
