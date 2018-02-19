/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_res_p_flags.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpolosuk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/27 10:25:06 by dpolosuk          #+#    #+#             */
/*   Updated: 2017/12/27 10:56:45 by dpolosuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

char	*ft_pf_res_p_flags(char *s, t_format *all)
{
	char	*res;

	res = s;
	if ((*all).flag_zero)
		res = ft_pf_res_x_flags_zero(res, all);
	res = ft_pf_res_p_flags_hash(res, all);
	if ((*all).flag_minus)
		res = ft_pf_res_d_i_flags_minus(res, all);
	return (res);
}
