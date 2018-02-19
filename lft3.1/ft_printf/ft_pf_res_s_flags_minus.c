/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_res_s_flags_minus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpolosuk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/30 13:18:25 by dpolosuk          #+#    #+#             */
/*   Updated: 2017/12/30 13:20:56 by dpolosuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

char	*ft_pf_res_s_flags_minus(char *s, t_format *all)
{
	int		index;
	int		len_raw;

	len_raw = (*all).len_of_raw_s;
	index = ft_strlen(s) - len_raw;
	s = ft_memmove(s, s + index, len_raw);
	while (s[len_raw])
		s[len_raw++] = ' ';
	return (s);
}
