/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_res_d_i_precision.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpolosuk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/22 18:02:54 by dpolosuk          #+#    #+#             */
/*   Updated: 2017/12/25 12:39:55 by dpolosuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

static void		ft_pf_res_d_i_precision_while(char **res, char **s, \
				int *i, int *j)
{
	while (*i >= 0 && (*s)[*j] != '-' && *j >= 0)
	{
		(*res)[*i] = (*s)[*j];
		*i = *i - 1;
		*j = *j - 1;
		if (*j < 0)
			break ;
	}
}

char			*ft_pf_res_d_i_precision(char *s, t_format *all)
{
	char	*res;
	int		len;
	int		num_of_zeroes;
	int		i;
	int		j;

	num_of_zeroes = 0;
	j = ft_strlen(s) - 1;
	res = NULL;
	len = (*s == '-') ? (ft_strlen(s) - 1) : (ft_strlen(s));
	(*all).len_of_raw_s = len;
	if ((*all).precision_field <= len)
		return (s);
	num_of_zeroes = (*all).precision_field - len;
	i = ft_strlen(s) + num_of_zeroes;
	res = ft_strnew(i);
	--i;
	ft_pf_res_d_i_precision_while(&res, &s, &i, &j);
	while (num_of_zeroes--)
		res[i--] = '0';
	if (*s == '-')
		res[i] = '-';
	ft_strdel(&s);
	return (res);
}
