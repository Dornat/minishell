/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_res_o_flags_hash.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpolosuk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/25 18:56:04 by dpolosuk          #+#    #+#             */
/*   Updated: 2017/12/29 19:33:57 by dpolosuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

static void		ft_pf_res_o_flags_hash_elif(char *s, char **res)
{
	if (s[0] == '0' && s[1] == '\0')
	{
		*res = ft_strnew(1);
		(*res)[0] = '0';
	}
	else
	{
		*res = ft_strnew(ft_strlen(s) + 1);
		ft_strlcat(*res + 1, s, ft_strlen(s) + 1);
		(*res)[0] = '0';
	}
	ft_strdel(&s);
}

char			*ft_pf_res_o_flags_hash(char *s, t_format *all)
{
	char	*res;
	int		i;

	res = NULL;
	i = ft_pf_find_digit_index(s);
	if (ft_pf_find_minus(s) || (((*all).precision_field - (*all).len_of_raw_s) \
				>= 1))
		return (s);
	if (i > 0)
	{
		if (s[i - 1] == ' ')
		{
			s[i - 1] = '0';
			return (s);
		}
	}
	if (s[i] == '0' && s[i + 1] != '\0' && !(*all).precision_field_identifier)
	{
		s[i] = '0';
		return (s);
	}
	else if (s[i] != '0' || (s[i] == '0' && s[i + 1] == '\0') || (s[i] == '0' \
				&& (*all).precision_field_identifier))
		ft_pf_res_o_flags_hash_elif(s, &res);
	return (res);
}
