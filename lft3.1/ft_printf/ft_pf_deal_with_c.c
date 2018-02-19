/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_deal_with_c.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpolosuk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/28 16:32:34 by dpolosuk          #+#    #+#             */
/*   Updated: 2017/12/29 16:42:08 by dpolosuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

static void		ft_pf_print_c_ifnull(t_format *all, char *res, \
				unsigned int *len)
{
	int		i;
	int		len_for_null;

	i = 0;
	len_for_null = ((*all).width_field > 1) ? (*all).width_field : 1;
	while (i < len_for_null)
	{
		ft_putchar(res[i]);
		*len = *len + 1;
		i++;
	}
}

void			ft_pf_deal_with_c(t_format *all, va_list ap, unsigned int *len)
{
	char	*res;
	int		null;
	int		space;

	null = 0;
	space = 0;
	res = ft_pf_res_c_raw(all, ap);
	if (res[0] == '\0')
		null = 1;
	if (res[0] == ' ')
		space = 1;
	res = ft_pf_res_c_width(res, all, null);
	res = ft_pf_res_c_flags(res, all, null, space);
	if (null)
		ft_pf_print_c_ifnull(all, res, len);
	else
	{
		ft_putstr(res);
		*len = *len + ft_strlen(res);
	}
	ft_strdel(&res);
}
