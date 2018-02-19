/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_res_d_i_flags_space.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpolosuk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/22 17:38:12 by dpolosuk          #+#    #+#             */
/*   Updated: 2017/12/29 12:48:17 by dpolosuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

static int		ft_pf_if_check(char *s, int i)
{
	if (i > 0)
	{
		if (s[i - 1] == ' ')
			return (1);
	}
	return (0);
}

char			*ft_pf_res_d_i_flags_space(char *s, t_format *all)
{
	char	*res;
	int		i;

	res = NULL;
	if ((*all).flag_plus)
		return (s);
	i = ft_pf_find_digit_index(s);
	if (ft_pf_find_minus(s) || ft_pf_if_check(s, i))
		return (s);
	if (s[i] == '0' && s[i + 1] != '\0' && !(*all).precision_field_identifier)
	{
		s[i] = ' ';
		return (s);
	}
	else if (s[i] != '0' || (s[i] == '0' && s[i + 1] == '\0') || \
		(s[i] == '0' && (*all).precision_field_identifier))
	{
		res = ft_strnew(ft_strlen(s) + 1);
		ft_strlcat(res + 1, s, ft_strlen(s) + 1);
		res[0] = ' ';
	}
	ft_strdel(&s);
	return (res);
}
