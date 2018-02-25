# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dpolosuk <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/09 13:27:26 by dpolosuk          #+#    #+#              #
#    Updated: 2018/02/25 12:22:36 by dpolosuk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

SRC = termcap.c

INCLUDE = -I ./includes -I ./lft3.1/includes
CFLAGS = -g -Wall -Wextra #-Werror
LIB = -L ./lft3.1/ -lft -ltermcap

OBJ_PATH = ./src/
OBJ = $(addprefix $(OBJ_PATH), $(SRC:.c=.o))

.PHONY: all clean fclean re
all: $(NAME)

$(NAME): $(OBJ)
	@make -C ./lft3.1 all
	@echo library made
	@gcc $(CFLAGS) $(OBJ) $(INCLUDE) $(LIB) -o $(NAME)
	@echo minishell made

%.o: %.c
	@gcc $(CFLAGS) -c $< -o $@ $(INCLUDE)

clean:
	@make -C ./lft3.1 clean
	@echo library objectfiles cleaned
	@/bin/rm -f $(OBJ)
	@echo minishell objectfiles cleaned

fclean: clean
	@make -C ./lft3.1 fclean
	@echo library name cleaned
	@/bin/rm -f $(NAME)
	@echo minishell name cleaned

re: fclean all