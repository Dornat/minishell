/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_res_b_flags.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpolosuk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/02 11:28:22 by dpolosuk          #+#    #+#             */
/*   Updated: 2018/01/02 11:30:05 by dpolosuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

char	*ft_pf_res_b_flags(char *s, t_format *all)
{
	char	*res;

	res = s;
	if (!(*all).flag_minus && !(*all).flag_space)
		return (s);
	if ((*all).flag_space && (*all).len_of_raw_s > 4)
		res = ft_pf_res_b_flags_space(s, all);
	if ((*all).flag_minus)
		res = ft_pf_res_u_flags_minus(res);
	return (res);
}
