/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_deal_with_x.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpolosuk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/26 10:29:57 by dpolosuk          #+#    #+#             */
/*   Updated: 2017/12/30 18:55:12 by dpolosuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

void	ft_pf_deal_with_x(t_format *all, va_list ap, unsigned int *len)
{
	char	*res;
	int		zero;

	zero = 0;
	res = ft_pf_res_x_raw(all, ap);
	if (res[0] == '0')
		zero = 1;
	res = ft_pf_res_d_i_precision(res, all);
	res = ft_pf_res_d_i_width(res, all);
	res = ft_pf_res_x_flags(res, all, zero);
	ft_putstr(res);
	*len = *len + ft_strlen(res);
	ft_strdel(&res);
}
