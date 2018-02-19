/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_res_x_flags_zero.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpolosuk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/26 11:23:34 by dpolosuk          #+#    #+#             */
/*   Updated: 2017/12/26 11:29:38 by dpolosuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

char	*ft_pf_res_x_flags_zero(char *s, t_format *all)
{
	int		i;
	int		digit_index;

	if ((*all).precision_field_identifier || (*all).flag_minus)
		return (s);
	i = 0;
	digit_index = ft_pf_find_hex_index(s);
	while (i < digit_index)
	{
		s[i] = '0';
		i++;
	}
	return (s);
}
