/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_deal_with_x_raw.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpolosuk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/26 10:31:10 by dpolosuk          #+#    #+#             */
/*   Updated: 2018/01/01 13:14:14 by dpolosuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

char	*ft_pf_res_x_raw(t_format *all, va_list ap)
{
	char	*res;

	res = NULL;
	if (!(*all).t_size)
		res = ft_pf_dec_to_hex(ft_pf_normal_u(all, ap));
	if ((*all).t_size == hh)
		res = ft_pf_dec_to_hex(ft_pf_short_short_u(all, ap));
	if ((*all).t_size == h)
		res = ft_pf_dec_to_hex(ft_pf_short_u(all, ap));
	if ((*all).t_size == l || (*all).t_size == ll || (*all).t_size == z || \
			(*all).t_size == j || (*all).t_size == t || (*all).t_size == L)
		res = ft_pf_dec_to_hex(ft_pf_long_long_u(all, ap));
	if (*res == '0' && (*all).precision_field_identifier == 1 && \
			(*all).precision_field == 0)
		res[0] = '\0';
	return (res);
}
