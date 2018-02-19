/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_res_c_flags.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpolosuk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/28 19:15:30 by dpolosuk          #+#    #+#             */
/*   Updated: 2017/12/29 16:42:22 by dpolosuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

char	*ft_pf_res_c_flags(char *s, t_format *all, int null, int space)
{
	char	*res;

	res = s;
	if (!(*all).flag_minus && !(*all).flag_zero)
		return (s);
	if ((*all).flag_zero && (*all).width_field > (*all).len_of_raw_s && \
			!(*all).flag_minus)
		res = ft_pf_res_c_flags_zero(res, space);
	if ((*all).flag_minus && (*all).width_field > 1 && ((int)ft_strlen(s) > \
				(*all).len_of_raw_s))
		res = ft_pf_res_c_flags_minus(res, null, all);
	return (res);
}
