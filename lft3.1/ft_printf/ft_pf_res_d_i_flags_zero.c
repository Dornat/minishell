/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_res_d_i_flags_zero.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpolosuk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/22 17:36:09 by dpolosuk          #+#    #+#             */
/*   Updated: 2017/12/22 17:36:17 by dpolosuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

char	*ft_pf_res_d_i_flags_zero(char *s, t_format *all)
{
	int		minus;
	int		i;
	int		digit_index;

	if ((*all).precision_field_identifier || (*all).flag_minus)
		return (s);
	i = 0;
	minus = 0;
	digit_index = ft_pf_find_digit_index(s);
	if (ft_pf_find_minus(s))
		minus = 1;
	while (i < digit_index)
	{
		s[i] = '0';
		i++;
	}
	if (minus)
		s[0] = '-';
	return (s);
}
