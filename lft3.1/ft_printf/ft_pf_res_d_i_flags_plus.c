/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_res_d_i_flags_plus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpolosuk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/22 17:37:27 by dpolosuk          #+#    #+#             */
/*   Updated: 2017/12/27 09:44:06 by dpolosuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

static void		ft_pf_res_d_i_flag_plus_elif(char *s, char **res)
{
	*res = ft_strnew(ft_strlen(s) + 1);
	ft_strlcat(*res + 1, s, ft_strlen(s) + 1);
	(*res)[0] = '+';
	ft_strdel(&s);
}

char			*ft_pf_res_d_i_flags_plus(char *s, t_format *all)
{
	char	*res;
	int		i;

	res = NULL;
	i = ft_pf_find_digit_index(s);
	if (ft_pf_find_minus(s))
		return (s);
	if (i > 0)
	{
		if (s[i - 1] == ' ')
		{
			s[i - 1] = '+';
			return (s);
		}
	}
	if (s[i] == '0' && s[i + 1] != '\0' && !(*all).precision_field_identifier)
	{
		s[i] = '+';
		return (s);
	}
	else if (s[i] != '0' || (s[i] == '0' && s[i + 1] == '\0') || (s[i] == '0' \
				&& (*all).precision_field_identifier))
		ft_pf_res_d_i_flag_plus_elif(s, &res);
	return (res);
}
