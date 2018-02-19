/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_res_s_raw.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpolosuk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/29 20:14:22 by dpolosuk          #+#    #+#             */
/*   Updated: 2017/12/30 17:33:40 by dpolosuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

char	*ft_pf_res_s_raw(t_format *all, va_list ap)
{
	char			*res;

	res = NULL;
	if ((*all).t_size != l)
	{
		if (!(res = ft_strdup(ft_pf_string(all, ap))))
			return (ft_strdup("(null)\0"));
		return (res);
	}
	else
	{
		if (!(res = ft_pf_string_wchar_raw(ft_pf_string_wchar(all, ap), all)))
		{
			(*all).t_size = 0;
			return (ft_strdup("(null)\0"));
		}
	}
	return (res);
}
