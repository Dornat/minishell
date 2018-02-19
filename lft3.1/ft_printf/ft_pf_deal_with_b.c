/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_deal_with_b.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpolosuk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/02 11:23:14 by dpolosuk          #+#    #+#             */
/*   Updated: 2018/01/02 11:39:41 by dpolosuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

void	ft_pf_deal_with_b(t_format *all, va_list ap, unsigned int *len)
{
	char	*res;

	res = ft_pf_res_b_raw(all, ap);
	res = ft_pf_res_d_i_precision(res, all);
	(*all).len_of_raw_s = ft_strlen(res);
	res = ft_pf_res_d_i_width(res, all);
	res = ft_pf_res_b_flags(res, all);
	ft_putstr(res);
	*len = *len + ft_strlen(res);
	ft_strdel(&res);
}
