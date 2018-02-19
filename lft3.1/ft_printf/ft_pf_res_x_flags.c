/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_res_x_flags.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpolosuk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/26 11:15:03 by dpolosuk          #+#    #+#             */
/*   Updated: 2017/12/30 19:22:25 by dpolosuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

static int		ft_pf_hex_for_tou(char c)
{
	if (c == 'x' || c == 'a' || c == 'b' || c == 'c' || c == 'd' || c == 'e' \
		|| c == 'f')
		return (1);
	return (0);
}

static void		ft_pf_hex_to_upper(char **res)
{
	int		i;

	i = 0;
	while ((*res)[i])
	{
		if (ft_pf_hex_for_tou((*res)[i]))
			(*res)[i] = (*res)[i] - 32;
		i++;
	}
}

char			*ft_pf_res_x_flags(char *s, t_format *all, int zero)
{
	char	*res;

	res = s;
	if (!(*all).flag_apostrophe && !(*all).flag_minus && !(*all).flag_plus && \
	!(*all).flag_space && !(*all).flag_zero && !(*all).flag_hash && \
	!(*all).big_x)
		return (s);
	if ((*all).flag_zero)
		res = ft_pf_res_x_flags_zero(res, all);
	if ((*all).flag_hash && !zero)
		res = ft_pf_res_x_flags_hash(res, all);
	if ((*all).flag_minus && (*all).width_field > (*all).len_of_raw_s)
		res = ft_pf_res_x_flags_minus(res);
	if ((*all).big_x)
		ft_pf_hex_to_upper(&res);
	return (res);
}
