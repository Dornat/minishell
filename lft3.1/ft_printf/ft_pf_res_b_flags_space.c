/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_res_b_flags_space.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpolosuk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/02 11:30:18 by dpolosuk          #+#    #+#             */
/*   Updated: 2018/01/02 11:36:09 by dpolosuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

static void		ft_pf_remove_zers(char **dst, t_format *all)
{
	int		len;
	int		i;

	len = ft_strlen(*dst) - (*all).precision_field;
	i = 0;
	while (i < len && ((*dst)[i] == ' '))
	{
		(*dst)[i] = ' ';
		i++;
	}
}

static char		*ft_pf_put_spaces(char *dst, char *src, t_format *all, \
				int len_of_dst)
{
	int		count;
	int		len_of_src;
	int		len_of_raw;

	len_of_src = ft_strlen(src);
	len_of_raw = (*all).len_of_raw_s;
	count = 0;
	len_of_dst--;
	len_of_src--;
	while (len_of_raw > 0)
	{
		if (count != 0 && count % 4 == 0)
			dst[len_of_dst--] = ' ';
		dst[len_of_dst] = src[len_of_src];
		len_of_raw--;
		len_of_dst--;
		len_of_src--;
		count++;
	}
	while (len_of_src >= 0 && len_of_dst >= 0)
		dst[len_of_dst--] = src[len_of_src--];
	if (((int)ft_strlen(dst) - \
				ft_pf_find_digit_index(dst) + 1) >= (*all).precision_field)
		ft_pf_remove_zers(&dst, all);
	return (dst);
}

char			*ft_pf_res_b_flags_space(char *s, t_format *all)
{
	char	*res;
	int		i;
	int		count;
	int		num_of_ap;
	int		len_of_dst;

	res = NULL;
	i = ft_strlen(s);
	count = (*all).len_of_raw_s;
	if (count % 4 == 0)
		num_of_ap = (count / 4) - 1;
	else
		num_of_ap = count / 4;
	(i > count + ft_pf_find_minus(s) + num_of_ap) ? (res = \
	ft_strnew(i)) : (res = ft_strnew(count + ft_pf_find_minus(s) + num_of_ap));
	(i > count + ft_pf_find_minus(s) + num_of_ap) ? (len_of_dst = \
			i) : (len_of_dst = count + ft_pf_find_minus(s) + num_of_ap);
	res = ft_pf_put_spaces(res, s, all, len_of_dst);
	ft_strdel(&s);
	return (res);
}
