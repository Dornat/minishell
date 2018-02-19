/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_res_x_flags_minus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpolosuk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/30 19:07:56 by dpolosuk          #+#    #+#             */
/*   Updated: 2017/12/30 19:35:16 by dpolosuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

char	*ft_pf_res_x_flags_minus(char *s)
{
	int		len_raw;
	int		index_last;
	int		index_first;

	index_last = ft_strlen(s);
	index_first = ft_pf_find_hex_index(s);
	if (index_first == -1)
		return (s);
	len_raw = index_last - index_first;
	s = ft_memmove(s, s + index_first, len_raw);
	while (s[len_raw])
		s[len_raw++] = ' ';
	return (s);
}
