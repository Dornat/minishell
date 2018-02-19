/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_functions_for_res_n.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpolosuk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/01 14:07:06 by dpolosuk          #+#    #+#             */
/*   Updated: 2018/01/01 14:34:17 by dpolosuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

int				*ft_pf_normal_n(t_format *all, va_list ap)
{
	int			*n;
	int			i;
	int			*tmp;
	int			param;
	va_list		bp;

	i = 0;
	tmp = 0;
	param = (*all).parameter_field;
	va_copy(bp, ap);
	if (!param)
		n = va_arg(ap, int*);
	else
	{
		while (i < param)
		{
			tmp = va_arg(bp, int*);
			if (i == (param - 1))
				n = tmp;
			i++;
		}
	}
	return (n);
}

short			*ft_pf_short_n(t_format *all, va_list ap)
{
	short		*sn;
	int			i;
	short		*tmp;
	int			param;
	va_list		bp;

	i = 0;
	tmp = 0;
	param = (*all).parameter_field;
	va_copy(bp, ap);
	if (!param)
		sn = va_arg(ap, short*);
	else
	{
		while (i < param)
		{
			tmp = va_arg(bp, short*);
			if (i == (param - 1))
				sn = tmp;
			i++;
		}
	}
	return (sn);
}

long			*ft_pf_long_n(t_format *all, va_list ap)
{
	long		*ln;
	int			i;
	long		*tmp;
	int			param;
	va_list		bp;

	i = 0;
	tmp = 0;
	param = (*all).parameter_field;
	va_copy(bp, ap);
	if (!param)
		ln = va_arg(ap, long*);
	else
	{
		while (i < param)
		{
			tmp = va_arg(bp, long*);
			if (i == (param - 1))
				ln = tmp;
			i++;
		}
	}
	return (ln);
}
