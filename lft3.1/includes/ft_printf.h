/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpolosuk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/09 13:40:35 by dpolosuk          #+#    #+#             */
/*   Updated: 2018/01/02 11:33:58 by dpolosuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <libft.h>
# include <stdarg.h>

typedef struct		s_format
{
	unsigned int	parameter_field;
	unsigned int	flag_apostrophe:1;
	unsigned int	flag_minus:1;
	unsigned int	flag_plus:1;
	unsigned int	flag_space:1;
	unsigned int	flag_zero:1;
	unsigned int	flag_hash:1;
	unsigned int	precision_field_identifier:1;
	int				width_field;
	unsigned int	width_field_identifier:1;
	int				precision_field;
	enum			e_size
	{
		hh = 1, h, L, l, ll, z, j, t
	}				t_size;
	int				len_of_raw_s;
	unsigned int	big_x:1;
}					t_format;

/*
** Main functions
*/

int					ft_printf(const char *format, ...);
void				ft_pf_the_center(const char **format, t_format *all, \
					va_list ap, unsigned int *len);
void				ft_pf_put_everything_together(const char **format, \
					t_format *all, va_list ap, unsigned int *len);
void				ft_pf_deal_with_shitty_type(const char **format, \
					t_format *all, va_list ap, unsigned int *len);
void				ft_pf_deal_with_percent(const char **format, \
					t_format *all, va_list ap, unsigned int *len);
void				ft_pf_deal_with_d_i(t_format *all, va_list ap, \
					unsigned int *len);
void				ft_pf_deal_with_u(t_format *all, va_list ap, \
					unsigned int *len);
void				ft_pf_deal_with_o(t_format *all, va_list ap, \
					unsigned int *len);
void				ft_pf_deal_with_x(t_format *all, va_list ap, \
					unsigned int *len);
void				ft_pf_deal_with_p(t_format *all, va_list ap, \
					unsigned int *len);
void				ft_pf_deal_with_c(t_format *all, va_list ap, \
					unsigned int *len);
void				ft_pf_deal_with_s(t_format *all, va_list ap, \
					unsigned int *len);
void				ft_pf_deal_with_n(t_format *all, va_list ap, \
					unsigned int *len);
void				ft_pf_deal_with_b(t_format *all, va_list ap, \
					unsigned int *len);

/*
** Parsing
*/

int					ft_pf_parse_parameter(const char **format);
void				ft_pf_parse_flags(const char **format, t_format *all);
void				ft_pf_parse_width(const char **format, t_format *all, \
					va_list ap);
void				ft_pf_parse_precision(const char **format, t_format *all, \
					va_list ap);
void				ft_pf_parse_size(const char **format, t_format *all);

/*
** >d, i and D types dealing
*/

char				*ft_pf_res_d_i_raw(t_format *all, va_list ap);
int					ft_pf_normal_d_i(t_format *all, va_list ap);
char				ft_pf_short_short(t_format *all, va_list ap);
short				ft_pf_short(t_format *all, va_list ap);
long long int		ft_pf_long_long(t_format *all, va_list ap);
char				*ft_pf_res_d_i_precision(char *s, t_format *all);
char				*ft_pf_res_d_i_width(char *s, t_format *all);

/*
** >>d, i and D types flags dealing
*/

char				*ft_pf_res_d_i_flags(char *s, t_format *all);
char				*ft_pf_res_d_i_flags_apostrophe(char *s, t_format *all);
char				*ft_pf_res_d_i_flags_zero(char *s, t_format *all);
char				*ft_pf_res_d_i_flags_plus(char *s, t_format *all);
char				*ft_pf_res_d_i_flags_space(char *s, t_format *all);
char				*ft_pf_res_d_i_flags_minus(char *s, t_format *all);

/*
** >u and U types dealing
*/

char				*ft_pf_res_u_raw(t_format *all, va_list ap);
unsigned int		ft_pf_normal_u(t_format *all, va_list ap);
unsigned char		ft_pf_short_short_u(t_format *all, va_list ap);
unsigned short		ft_pf_short_u(t_format *all, va_list ap);
unsigned long long	ft_pf_long_long_u(t_format *all, va_list ap);

/*
** >>u and U types flags dealing
*/

char				*ft_pf_res_u_flags(char *s, t_format *all);
char				*ft_pf_res_u_flags_minus(char *s);

/*
** >o and O types dealing
*/

char				*ft_pf_res_o_raw(t_format *all, va_list ap);

/*
** >>o and O types flags dealing
*/

char				*ft_pf_res_o_flags(char *s, t_format *all);
char				*ft_pf_res_o_flags_hash(char *s, t_format *all);
char				*ft_pf_res_o_flags_minus(char *s);

/*
** >x and X types dealing
*/

char				*ft_pf_res_x_raw(t_format *a, va_list ap);

/*
** >>x and X types flags dealing
*/

char				*ft_pf_res_x_flags(char *s, t_format *all, int zero);
char				*ft_pf_res_x_flags_zero(char *s, t_format *all);
char				*ft_pf_res_x_flags_hash(char *s, t_format *all);
char				*ft_pf_res_x_flags_minus(char *s);

/*
** >p type dealing
*/

char				*ft_pf_res_p_raw(t_format *all, va_list ap);
size_t				ft_pf_normal_p(t_format *all, va_list ap);

/*
** >>p type flags dealing
*/

char				*ft_pf_res_p_flags(char *s, t_format *all);
char				*ft_pf_res_p_flags_hash(char *s, t_format *all);

/*
** >c and C type dealing
*/

char				*ft_pf_res_c_raw(t_format *all, va_list ap);
char				*ft_pf_res_c_width(char *s, t_format *all, int null);
int					ft_pf_wchar(t_format *all, va_list ap);

/*
** >>c and C type flags dealing
*/

char				*ft_pf_res_c_flags(char *s, t_format *all, int null, \
					int space);
char				*ft_pf_res_c_flags_zero(char *s, int space);
char				*ft_pf_res_c_flags_minus(char *s, int null, t_format *all);

/*
** >s and S type dealing
*/

char				*ft_pf_res_s_raw(t_format *all, va_list ap);
char				*ft_pf_string(t_format *all, va_list ap);
wchar_t				*ft_pf_string_wchar(t_format *all, va_list ap);
char				*ft_pf_string_wchar_raw(wchar_t *ws, t_format *all);
char				*ft_pf_res_s_precision(char *s, t_format *all);
char				*ft_pf_res_s_width(char *s, t_format *all);

/*
** >>s and S type flags dealing
*/

char				*ft_pf_res_s_flags(char *s, t_format *all);
char				*ft_pf_res_s_flags_minus(char *s, t_format *all);
char				*ft_pf_res_s_flags_zero(char *s, t_format *all);

/*
** >>n type flags dealing
*/

int					*ft_pf_normal_n(t_format *all, va_list ap);
short				*ft_pf_short_n(t_format *all, va_list ap);
long				*ft_pf_long_n(t_format *all, va_list ap);

/*
** >>b type dealing
*/

char				*ft_pf_res_b_raw(t_format *all, va_list ap);

/*
** >>b type flags dealing
*/

char				*ft_pf_res_b_flags(char *s, t_format *all);
char				*ft_pf_res_b_flags_space(char *s, t_format *all);

/*
** >shitty type dealing
*/

char				*ft_pf_res_shitty_type_width(const char **format, \
					t_format *all);

/*
** >>shitty type flags dealing
*/

char				*ft_pf_res_shitty_type_flags(char *s, t_format *all);
char				*ft_pf_res_shitty_type_flags_zero(char *s, \
					t_format *all);
char				*ft_pf_res_shitty_type_flags_minus(char *s);

/*
** Other functions
*/

void				ft_pf_set_zeros_to_struct_fields(t_format *all);
unsigned char		*ft_pf_res_unicode(unsigned int b);
void				ft_pf_set_zeros_to_struct_fields(t_format *all);
char				*ft_pf_itoa_long_long(long long int ll);
char				*ft_pf_itoa_unsigned_int(unsigned int ui);
char				*ft_pf_itoa_unsigned_long_long(unsigned long long int ui);
int					ft_pf_check_for_big_sdouxc(char c);
int					ft_pf_check_for_type(char c);
int					ft_pf_check_for_every_type(char c);
int					ft_pf_check_for_the_center(char c);
int					ft_pf_check_for_t_size(char c);
int					ft_pf_check_for_flag(char c);
int					ft_pf_find_minus(char *s);
int					ft_pf_find_digit_index(char *s);
int					ft_pf_find_hex_index(char *s);
char				*ft_pf_dec_to_oct_ui(unsigned int dec);
char				*ft_pf_dec_to_oct_us(unsigned short dec);
char				*ft_pf_dec_to_oct_uss(unsigned char dec);
char				*ft_pf_dec_to_oct_ull(unsigned long long dec);
char				*ft_pf_dec_to_hex(unsigned long long int input);
int					ft_count_bits(unsigned long long dec);
int					ft_pf_everything_failed(char c);
char				*ft_pf_itob(unsigned long long int octet);

#endif
