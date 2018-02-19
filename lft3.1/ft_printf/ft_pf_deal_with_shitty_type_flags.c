/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_deal_with_shitty_type_flags.c                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpolosuk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/27 13:07:08 by dpolosuk          #+#    #+#             */
/*   Updated: 2017/12/27 16:35:28 by dpolosuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

char	*ft_pf_res_shitty_type_flags(char *s, t_format *all)
{
	char	*res;

	res = s;
	if (!(*all).flag_minus && !(*all).flag_zero)
		return (s);
	if ((*all).flag_zero && (*all).width_field > 1 && !(*all).flag_minus)
		res = ft_pf_res_shitty_type_flags_zero(res, all);
	if ((*all).flag_minus)
		res = ft_pf_res_shitty_type_flags_minus(res);
	return (res);
}
