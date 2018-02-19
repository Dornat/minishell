/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_deal_with_percent.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpolosuk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/28 14:22:40 by dpolosuk          #+#    #+#             */
/*   Updated: 2017/12/28 14:27:55 by dpolosuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

void	ft_pf_deal_with_percent(const char **format, t_format *all, \
		va_list ap, unsigned int *len)
{
	char	*res;

	ap = NULL;
	res = NULL;
	res = ft_pf_res_shitty_type_width(format, all);
	res = ft_pf_res_shitty_type_flags(res, all);
	ft_putstr(res);
	*len = *len + ft_strlen(res);
	ft_strdel(&res);
}
