/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_functions_for_res_p.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpolosuk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/27 10:21:04 by dpolosuk          #+#    #+#             */
/*   Updated: 2017/12/27 10:32:01 by dpolosuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

size_t		ft_pf_normal_p(t_format *all, va_list ap)
{
	size_t		p;
	int			i;
	size_t		tmp;
	int			param;
	va_list		bp;

	i = 0;
	tmp = 0;
	param = (*all).parameter_field;
	va_copy(bp, ap);
	if (!param)
		p = va_arg(ap, size_t);
	else
	{
		while (i < param)
		{
			tmp = va_arg(bp, size_t);
			if (i == (param - 1))
				p = tmp;
			i++;
		}
	}
	return (p);
}
