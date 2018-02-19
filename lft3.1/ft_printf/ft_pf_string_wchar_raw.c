/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_string_wchar_raw.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpolosuk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/30 11:38:47 by dpolosuk          #+#    #+#             */
/*   Updated: 2017/12/30 16:59:28 by dpolosuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

#define NULL_CHECK(val) if(val == NULL) return (NULL);
#define PF (*all).precision_field

static int		ft_pf_wcharlen(wchar_t *s)
{
	int		i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

static char		*ft_pf_sw_prec(wchar_t *ws, t_format *all, int len_ws, int i)
{
	char	*to_free;
	char	*to_free_uni;
	char	*res;

	res = ft_strnew(1);
	to_free = res;
	while (i < len_ws)
	{
		to_free_uni = (char*)ft_pf_res_unicode((unsigned int)ws[i]);
		res = ft_strjoin(res, to_free_uni);
		if ((PF = PF - ft_strlen(to_free_uni)) < 0)
		{
			ft_strdel(&res);
			ft_strdel(&to_free_uni);
			return (to_free);
		}
		if (to_free)
			ft_strdel(&to_free);
		to_free = res;
		ft_strdel(&to_free_uni);
		i++;
	}
	return (res);
}

char			*ft_pf_string_wchar_raw(wchar_t *ws, t_format *all)
{
	char	*to_free;
	char	*to_free_uni;
	char	*res;
	int		len_ws;
	int		i;

	NULL_CHECK(ws);
	to_free = NULL;
	res = NULL;
	i = 0;
	len_ws = ft_pf_wcharlen(ws);
	if ((*all).precision_field_identifier)
		return (ft_pf_sw_prec(ws, all, len_ws, i));
	res = ft_strnew(1);
	while (i < len_ws)
	{
		to_free = res;
		to_free_uni = (char*)ft_pf_res_unicode((unsigned int)ws[i]);
		res = ft_strjoin(res, to_free_uni);
		ft_strdel(&to_free_uni);
		if (to_free)
			ft_strdel(&to_free);
		i++;
	}
	return (res);
}
