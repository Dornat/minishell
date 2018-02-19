/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_deal_with_d_i.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpolosuk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/22 17:31:23 by dpolosuk          #+#    #+#             */
/*   Updated: 2017/12/22 17:31:43 by dpolosuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

void	ft_pf_deal_with_d_i(t_format *all, va_list ap, unsigned int *len)
{
	char	*res;

	res = ft_pf_res_d_i_raw(all, ap);
	res = ft_pf_res_d_i_precision(res, all);
	res = ft_pf_res_d_i_width(res, all);
	res = ft_pf_res_d_i_flags(res, all);
	ft_putstr(res);
	*len = *len + ft_strlen(res);
	ft_strdel(&res);
}
