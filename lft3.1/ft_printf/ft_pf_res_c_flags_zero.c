/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_res_c_flags_zero.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpolosuk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/28 19:22:25 by dpolosuk          #+#    #+#             */
/*   Updated: 2017/12/29 16:09:59 by dpolosuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

char	*ft_pf_res_c_flags_zero(char *s, int space)
{
	int		i;
	int		len;

	len = ft_strlen(s);
	i = 0;
	while (s[len] != ' ' && len > 0)
		len--;
	if (space)
		len--;
	while (i <= len)
	{
		s[i] = '0';
		i++;
	}
	return (s);
}
