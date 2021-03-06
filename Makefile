# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dpolosuk <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/09 13:27:26 by dpolosuk          #+#    #+#              #
#    Updated: 2018/03/28 12:11:22 by dpolosuk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

SRC = basic_tab_completion.c \
		bi_cd.c \
		bi_echo_exit_env.c \
		bi_setenv.c \
		bi_unsetenv.c \
		copy_find_env.c \
		crs_move_right_left.c \
		del_chr_from_cmdl.c \
		ent_key_processing.c \
		exec_prog.c \
		find_executable.c \
		init_term.c \
		insert_chr_in_cmdl.c \
		key_process.c \
		little_misc_functions.c \
		main.c \
		misc.c \
		msh_replace_tilde_var_strparse_in_dqt.c \
		msh_split.c \
		msh_split_arg_num.c \
		msh_strparse.c \
		parse_cmd.c \
		parse_qt_are_there_null.c \
		parse_qt_bs.c \
		refresh_cli.c \
		split_semicol.c \
		swap_pwd_oldpwd.c \

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
