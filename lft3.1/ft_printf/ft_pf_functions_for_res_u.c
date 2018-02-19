/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_functions_for_res_u.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpolosuk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/25 13:11:25 by dpolosuk          #+#    #+#             */
/*   Updated: 2017/12/25 18:10:26 by dpolosuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

unsigned int		ft_pf_normal_u(t_format *all, va_list ap)
{
	unsigned int	u;
	int				i;
	unsigned int	tmp;
	int				param;
	va_list			bp;

	i = 0;
	tmp = 0;
	param = (*all).parameter_field;
	va_copy(bp, ap);
	if (!param)
		u = va_arg(ap, unsigned int);
	else
	{
		while (i < param)
		{
			tmp = va_arg(bp, unsigned int);
			if (i == (param - 1))
				u = tmp;
			i++;
		}
	}
	return (u);
}

unsigned char		ft_pf_short_short_u(t_format *all, va_list ap)
{
	unsigned char	hh;
	int				i;
	unsigned char	tmp;
	int				param;
	va_list			bp;

	i = 0;
	tmp = 0;
	param = (*all).parameter_field;
	va_copy(bp, ap);
	if (!param)
		hh = va_arg(ap, unsigned int);
	else
	{
		while (i < param)
		{
			tmp = va_arg(bp, unsigned int);
			if (i == (param - 1))
				hh = tmp;
			i++;
		}
	}
	return (hh);
}

unsigned short		ft_pf_short_u(t_format *all, va_list ap)
{
	unsigned short	h;
	int				i;
	unsigned short	tmp;
	int				param;
	va_list			bp;

	i = 0;
	tmp = 0;
	param = (*all).parameter_field;
	va_copy(bp, ap);
	if (!param)
		h = va_arg(ap, unsigned int);
	else
	{
		while (i < param)
		{
			tmp = va_arg(bp, unsigned int);
			if (i == (param - 1))
				h = tmp;
			i++;
		}
	}
	return (h);
}

unsigned long long	ft_pf_long_long_u(t_format *all, va_list ap)
{
	long long int	ll;
	int				i;
	long long int	tmp;
	int				param;
	va_list			bp;

	i = 0;
	tmp = 0;
	param = (*all).parameter_field;
	va_copy(bp, ap);
	if (!param)
		ll = va_arg(ap, unsigned long long);
	else
	{
		while (i < param)
		{
			tmp = va_arg(bp, unsigned long long);
			if (i == (param - 1))
				ll = tmp;
			i++;
		}
	}
	return (ll);
}
