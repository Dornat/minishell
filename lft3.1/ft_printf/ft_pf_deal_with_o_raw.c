/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_deal_with_o_raw.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpolosuk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/25 18:04:02 by dpolosuk          #+#    #+#             */
/*   Updated: 2018/01/01 12:59:44 by dpolosuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

char	*ft_pf_res_o_raw(t_format *all, va_list ap)
{
	char	*res;

	res = NULL;
	if (!(*all).t_size)
		res = ft_pf_dec_to_oct_ui(ft_pf_normal_u(all, ap));
	if ((*all).t_size == hh)
		res = ft_pf_dec_to_oct_uss(ft_pf_short_short_u(all, ap));
	if ((*all).t_size == h)
		res = ft_pf_dec_to_oct_us(ft_pf_short_u(all, ap));
	if ((*all).t_size == l || (*all).t_size == ll || (*all).t_size == z || \
			(*all).t_size == j || (*all).t_size == t || (*all).t_size == L)
		res = ft_pf_dec_to_oct_ull(ft_pf_long_long_u(all, ap));
	if (*res == '0' && (*all).precision_field_identifier == 1 && \
			(*all).precision_field == 0)
		res[0] = '\0';
	return (res);
}
