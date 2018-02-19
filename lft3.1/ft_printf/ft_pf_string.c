/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpolosuk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/29 20:15:49 by dpolosuk          #+#    #+#             */
/*   Updated: 2017/12/29 20:19:28 by dpolosuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

char		*ft_pf_string(t_format *all, va_list ap)
{
	char		*s;
	int			i;
	char		*tmp;
	int			param;
	va_list		bp;

	i = 0;
	tmp = 0;
	param = (*all).parameter_field;
	va_copy(bp, ap);
	if (!param)
		s = va_arg(ap, char*);
	else
	{
		while (i < param)
		{
			tmp = va_arg(bp, char*);
			if (i == (param - 1))
				s = tmp;
			i++;
		}
	}
	return (s);
}

wchar_t		*ft_pf_string_wchar(t_format *all, va_list ap)
{
	wchar_t		*ws;
	int			i;
	wchar_t		*tmp;
	int			param;
	va_list		bp;

	i = 0;
	tmp = 0;
	param = (*all).parameter_field;
	va_copy(bp, ap);
	if (!param)
		ws = va_arg(ap, wchar_t*);
	else
	{
		while (i < param)
		{
			tmp = va_arg(bp, wchar_t*);
			if (i == (param - 1))
				ws = tmp;
			i++;
		}
	}
	return (ws);
}
