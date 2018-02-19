/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_res_x_flags_hash.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpolosuk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/26 12:15:20 by dpolosuk          #+#    #+#             */
/*   Updated: 2018/01/01 12:40:04 by dpolosuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

#define LORS (*all).len_of_raw_s
#define WF (*all).width_field
#define PF (*all).precision_field
#define PFI (*all).precision_field_identifier

static void		ft_pf_res_x_flags_hash_elif1(char *s, char **res, t_format *all)
{
	int		i;
	int		j;
	int		len_s;

	len_s = ft_strlen(s);
	i = (*all).len_of_raw_s + 2;
	*res = ft_strnew(i);
	j = len_s - 1;
	i--;
	while (j >= (len_s - (*all).len_of_raw_s) && i >= 0)
		(*res)[i--] = s[j--];
	(*res)[i--] = 'x';
	(*res)[i] = '0';
	ft_strdel(&s);
}

static void		ft_pf_res_x_flags_hash_elif2_elif(char **res, t_format *all, \
				int *i, int len_s)
{
	*res = ((((*all).width_field - (*all).precision_field) == 2) && \
			(((*all).width_field - (*all).len_of_raw_s) \
			>= 2)) ? (ft_strnew(len_s)) : (ft_strnew(len_s + 1));
	*i = ((((*all).width_field - (*all).precision_field) == 2) && \
			(((*all).width_field - (*all).len_of_raw_s) \
			>= 2)) ? (len_s - 1) : (len_s);
}

static void		ft_pf_res_x_flags_hash_elif2(char *s, char **res, \
				t_format *all, int len_s)
{
	int		i;
	int		j;

	if ((LORS == len_s) || (LORS > WF && LORS > PF))
	{
		*res = ft_strnew(len_s + 2);
		i = len_s + 1;
	}
	else if ((*all).width_field > (*all).precision_field)
		ft_pf_res_x_flags_hash_elif2_elif(res, all, &i, len_s);
	else
	{
		*res = ft_strnew(len_s + 2);
		i = len_s + 1;
	}
	j = len_s - 1;
	while (j >= 0 && s[j] != ' ' && i >= 0)
	{
		(*res)[i--] = s[j--];
		if (j < 0)
			break ;
	}
	(*res)[i--] = 'x';
	(*res)[i] = '0';
	ft_strdel(&s);
}

static void		ft_pf_res_x_flags_hash_if(char **s)
{
	int		hi;

	hi = ft_pf_find_hex_index(*s);
	if ((*s)[hi] == '0' && (*s)[hi + 1] == '0')
		(*s)[hi + 1] = 'x';
	else
	{
		(*s)[hi - 1] = 'x';
		(*s)[hi - 2] = '0';
	}
}

char			*ft_pf_res_x_flags_hash(char *s, t_format *all)
{
	char	*res;
	int		len_s;

	res = NULL;
	len_s = ft_strlen(s);
	if ((s[0] == '0' && s[1] == '\0') || s[0] == '\0')
		return (s);
	if (len_s >= ((*all).len_of_raw_s + 2) && !PFI)
	{
		ft_pf_res_x_flags_hash_if(&s);
		return (s);
	}
	else if (len_s < ((*all).len_of_raw_s + 2) && !PFI)
		ft_pf_res_x_flags_hash_elif1(s, &res, all);
	else if ((!(*all).width_field || (*all).width_field <= \
		(2 + (*all).precision_field)) && (*all).precision_field_identifier)
		ft_pf_res_x_flags_hash_elif2(s, &res, all, len_s);
	else if ((*all).width_field > ((*all).precision_field + 2) && PFI)
	{
		s[ft_pf_find_hex_index(s) - 1] = 'x';
		s[ft_pf_find_hex_index(s) - 2] = '0';
		return (s);
	}
	return (res);
}
