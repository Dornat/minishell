/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_res_d_i_flags.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpolosuk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/22 17:39:44 by dpolosuk          #+#    #+#             */
/*   Updated: 2017/12/22 17:39:56 by dpolosuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

char	*ft_pf_res_d_i_flags(char *s, t_format *all)
{
	char	*res;

	res = s;
	if (!(*all).flag_apostrophe && !(*all).flag_minus && !(*all).flag_plus && \
	!(*all).flag_space && !(*all).flag_zero && !(*all).flag_hash)
		return (s);
	if ((*all).flag_apostrophe && (*all).len_of_raw_s > 3)
		res = ft_pf_res_d_i_flags_apostrophe(s, all);
	if ((*all).flag_zero)
		res = ft_pf_res_d_i_flags_zero(res, all);
	if ((*all).flag_plus)
		res = ft_pf_res_d_i_flags_plus(res, all);
	if ((*all).flag_space)
		res = ft_pf_res_d_i_flags_space(res, all);
	if ((*all).flag_minus)
		res = ft_pf_res_d_i_flags_minus(res, all);
	return (res);
}
