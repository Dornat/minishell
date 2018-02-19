/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_res_d_i_raw.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpolosuk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/22 18:01:24 by dpolosuk          #+#    #+#             */
/*   Updated: 2017/12/29 18:44:22 by dpolosuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

char	*ft_pf_res_d_i_raw(t_format *all, va_list ap)
{
	char	*res;

	res = NULL;
	if (!(*all).t_size)
		res = ft_itoa(ft_pf_normal_d_i(all, ap));
	if ((*all).t_size == hh)
		res = ft_itoa(ft_pf_short_short(all, ap));
	if ((*all).t_size == h || (*all).t_size == L)
		res = ft_itoa(ft_pf_short(all, ap));
	if ((*all).t_size == l || (*all).t_size == ll || (*all).t_size == z || \
			(*all).t_size == j || (*all).t_size == t)
		res = ft_pf_itoa_long_long(ft_pf_long_long(all, ap));
	if (*res == '0' && (*all).precision_field_identifier == 1 && \
			(*all).precision_field == 0)
		res[0] = '\0';
	return (res);
}
