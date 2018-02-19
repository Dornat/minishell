/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_res_shitty_type_width.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpolosuk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/27 13:11:06 by dpolosuk          #+#    #+#             */
/*   Updated: 2017/12/27 15:09:41 by dpolosuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

char	*ft_pf_res_shitty_type_width(const char **format, t_format *all)
{
	char	*res;

	if (!(*all).width_field || **format == '\0')
	{
		res = ft_strnew(1);
		res[0] = **format;
		return (res);
	}
	res = ft_strnew((*all).width_field);
	res = (char*)ft_memset(res, ' ', (*all).width_field - 1);
	res[(*all).width_field - 1] = **format;
	return (res);
}
