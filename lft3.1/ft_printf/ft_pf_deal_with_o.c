/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_deal_with_o.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpolosuk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/25 18:01:22 by dpolosuk          #+#    #+#             */
/*   Updated: 2017/12/25 18:48:30 by dpolosuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

void	ft_pf_deal_with_o(t_format *all, va_list ap, unsigned int *len)
{
	char	*res;

	res = ft_pf_res_o_raw(all, ap);
	res = ft_pf_res_d_i_precision(res, all);
	res = ft_pf_res_d_i_width(res, all);
	res = ft_pf_res_o_flags(res, all);
	ft_putstr(res);
	*len = *len + ft_strlen(res);
	ft_strdel(&res);
}
