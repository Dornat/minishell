/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_res_c_raw.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpolosuk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/28 16:42:47 by dpolosuk          #+#    #+#             */
/*   Updated: 2017/12/29 15:27:12 by dpolosuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

char	*ft_pf_res_c_raw(t_format *all, va_list ap)
{
	char			*res;

	res = NULL;
	if ((*all).t_size != l)
	{
		res = ft_strnew(1);
		res[0] = ft_pf_short_short(all, ap);
		(*all).len_of_raw_s = 1;
		return (res);
	}
	else
	{
		res = (char*)ft_pf_res_unicode(ft_pf_wchar(all, ap));
		(*all).len_of_raw_s = ft_strlen(res);
	}
	return (res);
}
