/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_deal_with_n.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpolosuk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/01 13:34:10 by dpolosuk          #+#    #+#             */
/*   Updated: 2018/01/01 14:33:36 by dpolosuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

void	ft_pf_deal_with_n(t_format *all, va_list ap, unsigned int *len)
{
	int		*n;
	short	*sn;
	long	*ln;

	n = NULL;
	sn = NULL;
	ln = NULL;
	if ((*all).t_size != h && (*all).t_size != l)
	{
		n = ft_pf_normal_n(all, ap);
		*n = *len;
	}
	if ((*all).t_size == h)
	{
		sn = ft_pf_short_n(all, ap);
		*sn = *len;
	}
	if ((*all).t_size == l)
	{
		ln = ft_pf_long_n(all, ap);
		*ln = *len;
	}
}
