/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_res_s_flags_zero.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpolosuk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/30 17:44:29 by dpolosuk          #+#    #+#             */
/*   Updated: 2017/12/30 17:47:42 by dpolosuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

char	*ft_pf_res_s_flags_zero(char *s, t_format *all)
{
	int		i;
	int		len;

	len = ft_strlen(s) - (*all).len_of_raw_s - 1;
	i = 0;
	while (i <= len)
	{
		s[i] = '0';
		i++;
	}
	return (s);
}
