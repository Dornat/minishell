/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_res_s_precision.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpolosuk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/30 12:46:31 by dpolosuk          #+#    #+#             */
/*   Updated: 2017/12/30 18:13:00 by dpolosuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

char	*ft_pf_res_s_precision(char *s, t_format *all)
{
	char	*res;

	res = ft_strnew((*all).precision_field);
	res = ft_strncpy(res, s, (*all).precision_field);
	(*all).len_of_raw_s = ft_strlen(res);
	ft_strdel(&s);
	return (res);
}
