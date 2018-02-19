/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_res_shitty_type_flags_minus.c                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpolosuk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/27 16:27:19 by dpolosuk          #+#    #+#             */
/*   Updated: 2017/12/27 16:39:26 by dpolosuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

char	*ft_pf_res_shitty_type_flags_minus(char *s)
{
	int		index_first;
	int		len;
	int		len_s;
	int		i;

	index_first = ft_strlen(s) - 1;
	len = ft_strlen(s) - 1;
	len_s = ft_strlen(s);
	i = 1;
	s = ft_memmove(s, s + index_first, len);
	while (i < len_s)
		s[i++] = ' ';
	return (s);
}
