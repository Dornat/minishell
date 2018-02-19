/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_res_o_flags_minus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpolosuk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/01 12:51:03 by dpolosuk          #+#    #+#             */
/*   Updated: 2018/01/01 12:52:33 by dpolosuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

char	*ft_pf_res_o_flags_minus(char *s)
{
	int		len_raw;
	int		index_last;
	int		index_first;

	index_last = ft_strlen(s);
	(ft_pf_find_minus(s)) ? (index_first = ft_pf_find_digit_index(s) \
	- 1) : (index_first = ft_pf_find_digit_index(s));
	if (index_first == -1)
		return (s);
	len_raw = index_last - index_first;
	s = ft_memmove(s, s + index_first, len_raw);
	while (s[len_raw])
		s[len_raw++] = ' ';
	return (s);
}
