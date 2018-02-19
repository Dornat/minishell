/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_res_c_flags_minus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpolosuk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/28 20:27:24 by dpolosuk          #+#    #+#             */
/*   Updated: 2017/12/29 16:42:46 by dpolosuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

char	*ft_pf_res_c_flags_minus(char *s, int null, t_format *all)
{
	int		index;
	int		len_raw;

	len_raw = (*all).len_of_raw_s;
	index = ft_strlen(s) - len_raw + null;
	s = ft_memmove(s, s + index, len_raw);
	while (s[len_raw])
		s[len_raw++] = ' ';
	if (null)
		s[len_raw] = ' ';
	return (s);
}
