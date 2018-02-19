/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_functions_for_res_d_i.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpolosuk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/22 17:42:45 by dpolosuk          #+#    #+#             */
/*   Updated: 2017/12/23 11:36:19 by dpolosuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

int				ft_pf_normal_d_i(t_format *all, va_list ap)
{
	int			d_i;
	int			i;
	int			tmp;
	int			param;
	va_list		bp;

	i = 0;
	tmp = 0;
	param = (*all).parameter_field;
	va_copy(bp, ap);
	if (!param)
		d_i = va_arg(ap, int);
	else
	{
		while (i < param)
		{
			tmp = va_arg(bp, int);
			if (i == (param - 1))
				d_i = tmp;
			i++;
		}
	}
	return (d_i);
}

char			ft_pf_short_short(t_format *all, va_list ap)
{
	char		hh;
	int			i;
	char		tmp;
	int			param;
	va_list		bp;

	i = 0;
	tmp = 0;
	param = (*all).parameter_field;
	va_copy(bp, ap);
	if (!param)
		hh = va_arg(ap, int);
	else
	{
		while (i < param)
		{
			tmp = va_arg(bp, int);
			if (i == (param - 1))
				hh = tmp;
			i++;
		}
	}
	return (hh);
}

short			ft_pf_short(t_format *all, va_list ap)
{
	short		h;
	int			i;
	short		tmp;
	int			param;
	va_list		bp;

	i = 0;
	tmp = 0;
	param = (*all).parameter_field;
	va_copy(bp, ap);
	if (!param)
		h = va_arg(ap, int);
	else
	{
		while (i < param)
		{
			tmp = va_arg(bp, int);
			if (i == (param - 1))
				h = tmp;
			i++;
		}
	}
	return (h);
}

long long int	ft_pf_long_long(t_format *all, va_list ap)
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
		ll = va_arg(ap, long long);
	else
	{
		while (i < param)
		{
			tmp = va_arg(bp, long long);
			if (i == (param - 1))
				ll = tmp;
			i++;
		}
	}
	return (ll);
}
