/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_res_shitty_type_flags_zero.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpolosuk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/27 15:49:46 by dpolosuk          #+#    #+#             */
/*   Updated: 2017/12/27 16:00:50 by dpolosuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

char	*ft_pf_res_shitty_type_flags_zero(char *s, t_format *all)
{
	int		len;
	int		i;

	len = (*all).width_field - 1;
	i = 0;
	while (i < len)
		s[i++] = '0';
	return (s);
}
