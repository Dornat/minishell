/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_wchar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpolosuk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/28 17:58:48 by dpolosuk          #+#    #+#             */
/*   Updated: 2017/12/28 18:01:28 by dpolosuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

int		ft_pf_wchar(t_format *all, va_list ap)
{
	wchar_t		wc;
	int			i;
	wchar_t		tmp;
	int			param;
	va_list		bp;

	i = 0;
	tmp = 0;
	param = (*all).parameter_field;
	va_copy(bp, ap);
	if (!param)
		wc = va_arg(ap, wchar_t);
	else
	{
		while (i < param)
		{
			tmp = va_arg(bp, wchar_t);
			if (i == (param - 1))
				wc = tmp;
			i++;
		}
	}
	return (wc);
}
