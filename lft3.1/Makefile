# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dpolosuk <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/09 13:27:26 by dpolosuk          #+#    #+#              #
#    Updated: 2018/02/19 17:35:05 by dpolosuk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC_LIB =	ft_atoi.c \
		ft_bubsort_intarr.c \
		ft_bzero.c \
		ft_isalnum.c \
		ft_isalpha.c \
		ft_isascii.c \
		ft_isdigit.c \
		ft_isprint.c \
		ft_itoa.c \
		ft_itoa_base.c \
		ft_lstadd.c \
		ft_lstadd_atend.c \
		ft_lstdel.c \
		ft_lstdelfunc.c \
		ft_lstdelone.c \
		ft_lstiter.c \
		ft_lstmap.c \
		ft_lstnew.c \
		ft_lstrev.c \
		ft_memalloc.c \
		ft_memccpy.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_memcpy.c \
		ft_memdel.c \
		ft_memmove.c \
		ft_memset.c \
		ft_merge.c \
		ft_mergesort_intarr.c \
		ft_power.c \
		ft_putchar.c \
		ft_putchar_fd.c \
		ft_putendl.c \
		ft_putendl_fd.c \
		ft_putnbr.c \
		ft_putnbr_fd.c \
		ft_putstr.c \
		ft_putstr_fd.c \
		ft_sqrt.c \
		ft_strcat.c \
		ft_strchr.c \
		ft_strclr.c \
		ft_strcmp.c \
		ft_strcpy.c \
		ft_strdel.c \
		ft_strdup.c \
		ft_strequ.c \
		ft_striter.c \
		ft_striteri.c \
		ft_strjoin.c \
		ft_strlcat.c \
		ft_strlen.c \
		ft_strmap.c \
		ft_strmapi.c \
		ft_strncat.c \
		ft_strncmp.c \
		ft_strncpy.c \
		ft_strnequ.c \
		ft_strnew.c \
		ft_strnstr.c \
		ft_strrchr.c \
		ft_strrev.c \
		ft_strsplit.c \
		ft_strstr.c \
		ft_strsub.c \
		ft_strtrim.c \
		ft_swap_i.c \
		ft_swap_s.c \
		ft_tolower.c \
		ft_toupper.c \
		get_next_line.c \

SRC =	ft_count_bits.c \
		ft_pf_check_functions.c \
		ft_pf_deal_with_b.c \
		ft_pf_deal_with_c.c \
		ft_pf_deal_with_d_i.c \
		ft_pf_deal_with_n.c \
		ft_pf_deal_with_o.c \
		ft_pf_deal_with_o_raw.c \
		ft_pf_deal_with_p.c \
		ft_pf_deal_with_p_raw.c \
		ft_pf_deal_with_percent.c \
		ft_pf_deal_with_s.c \
		ft_pf_deal_with_shitty_type.c \
		ft_pf_deal_with_shitty_type_flags.c \
		ft_pf_deal_with_u.c \
		ft_pf_deal_with_x.c \
		ft_pf_deal_with_x_raw.c \
		ft_pf_dec_to_hex_functions.c \
		ft_pf_dec_to_oct_functions.c \
		ft_pf_find_functions.c \
		ft_pf_functions_for_res_d_i.c \
		ft_pf_functions_for_res_n.c \
		ft_pf_functions_for_res_p.c \
		ft_pf_functions_for_res_u.c \
		ft_pf_itoa_long_long.c \
		ft_pf_itoa_unsigned_int.c \
		ft_pf_itoa_unsigned_long_long.c \
		ft_pf_itob.c \
		ft_pf_parse_flags.c \
		ft_pf_parse_parameter.c \
		ft_pf_parse_precision.c \
		ft_pf_parse_size.c \
		ft_pf_parse_width.c \
		ft_pf_put_everything_together.c \
		ft_pf_res_b_flags.c \
		ft_pf_res_b_flags_space.c \
		ft_pf_res_b_raw.c \
		ft_pf_res_c_flags.c \
		ft_pf_res_c_flags_minus.c \
		ft_pf_res_c_flags_zero.c \
		ft_pf_res_c_raw.c \
		ft_pf_res_c_width.c \
		ft_pf_res_d_i_flags.c \
		ft_pf_res_d_i_flags_apostrophe.c \
		ft_pf_res_d_i_flags_minus.c \
		ft_pf_res_d_i_flags_plus.c \
		ft_pf_res_d_i_flags_space.c \
		ft_pf_res_d_i_flags_zero.c \
		ft_pf_res_d_i_precision.c \
		ft_pf_res_d_i_raw.c \
		ft_pf_res_d_i_width.c \
		ft_pf_res_o_flags.c \
		ft_pf_res_o_flags_hash.c \
		ft_pf_res_o_flags_minus.c \
		ft_pf_res_p_flags.c \
		ft_pf_res_p_flags_hash.c \
		ft_pf_res_s_flags.c \
		ft_pf_res_s_flags_minus.c \
		ft_pf_res_s_flags_zero.c \
		ft_pf_res_s_precision.c \
		ft_pf_res_s_raw.c \
		ft_pf_res_s_width.c \
		ft_pf_res_shitty_type_flags_minus.c \
		ft_pf_res_shitty_type_flags_zero.c \
		ft_pf_res_shitty_type_width.c \
		ft_pf_res_u_flags.c \
		ft_pf_res_u_flags_minus.c \
		ft_pf_res_u_raw.c \
		ft_pf_res_unicode.c \
		ft_pf_res_x_flags.c \
		ft_pf_res_x_flags_hash.c \
		ft_pf_res_x_flags_minus.c \
		ft_pf_res_x_flags_zero.c \
		ft_pf_set_zeroes_tp_struct_fields.c \
		ft_pf_string.c \
		ft_pf_string_wchar_raw.c \
		ft_pf_wchar.c \
		ft_printf.c \

OBJ_PATH = ./ft_printf/
OBJ_LIB_PATH = ./libft/

INCLUDE = -I ./includes
OBJ = $(addprefix $(OBJ_PATH), $(SRC:.c=.o))
OBJ_LIB = $(addprefix $(OBJ_LIB_PATH), $(SRC_LIB:.c=.o))
CFLAGS = -g -Wall -Wextra -Werror

.PHONY: all clean fclean re
all: $(NAME)

$(NAME): $(OBJ) $(OBJ_LIB)
	@ar rc $(NAME) $(OBJ) $(OBJ_LIB)
	@ranlib $(NAME)

%.o: %.c
	@gcc $(CFLAGS) -c $< -o $@ $(INCLUDE)

clean:
	@/bin/rm -f $(OBJ) $(OBJ_LIB)

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all
