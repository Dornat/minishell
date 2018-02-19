/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_res_s_flags.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpolosuk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/30 12:40:33 by dpolosuk          #+#    #+#             */
/*   Updated: 2017/12/30 17:46:45 by dpolosuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

char	*ft_pf_res_s_flags(char *s, t_format *all)
{
	char	*res;
	int		space;

	res = s;
	space = 0;
	if (!(*all).flag_minus && !(*all).flag_zero)
		return (s);
	if ((*all).flag_zero && (*all).width_field > (*all).len_of_raw_s && \
			!(*all).flag_minus)
		res = ft_pf_res_s_flags_zero(res, all);
	if ((*all).flag_minus && ((*all).width_field > (*all).len_of_raw_s))
		res = ft_pf_res_s_flags_minus(res, all);
	return (res);
}
