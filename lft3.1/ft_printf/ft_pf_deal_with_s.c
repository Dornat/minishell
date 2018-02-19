/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_deal_with_s.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpolosuk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/29 20:07:39 by dpolosuk          #+#    #+#             */
/*   Updated: 2017/12/30 17:31:41 by dpolosuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

void	ft_pf_deal_with_s(t_format *all, va_list ap, unsigned int *len)
{
	char	*res;

	res = NULL;
	res = ft_pf_res_s_raw(all, ap);
	(*all).len_of_raw_s = ft_strlen(res);
	if ((*all).precision_field_identifier && (*all).t_size != l)
		res = ft_pf_res_s_precision(res, all);
	res = ft_pf_res_s_width(res, all);
	res = ft_pf_res_s_flags(res, all);
	ft_putstr(res);
	*len = *len + ft_strlen(res);
	ft_strdel(&res);
}
