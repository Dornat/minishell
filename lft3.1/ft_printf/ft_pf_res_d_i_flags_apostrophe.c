/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_res_d_i_flags_apostrophe.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpolosuk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/22 17:32:48 by dpolosuk          #+#    #+#             */
/*   Updated: 2017/12/25 12:21:47 by dpolosuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

static void		ft_pf_remove_zeroes(char **dst, t_format *all)
{
	int		len;
	int		i;

	len = ft_strlen(*dst) - (*all).precision_field;
	i = 0;
	while (i < len && ((*dst)[i] == '0' || (*dst)[i] == ' '))
	{
		(*dst)[i] = ' ';
		i++;
	}
}

static char		*ft_pf_put_commas(char *dst, char *src, t_format *all, \
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
		if (count != 0 && count % 3 == 0)
			dst[len_of_dst--] = ',';
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
		ft_pf_remove_zeroes(&dst, all);
	return (dst);
}

char			*ft_pf_res_d_i_flags_apostrophe(char *s, t_format *all)
{
	char	*res;
	int		i;
	int		count;
	int		num_of_ap;
	int		len_of_dst;

	res = NULL;
	i = ft_strlen(s);
	count = (*all).len_of_raw_s;
	if (count % 3 == 0)
		num_of_ap = (count / 3) - 1;
	else
		num_of_ap = count / 3;
	(i > count + ft_pf_find_minus(s) + num_of_ap) ? (res = \
	ft_strnew(i)) : (res = ft_strnew(count + ft_pf_find_minus(s) + num_of_ap));
	(i > count + ft_pf_find_minus(s) + num_of_ap) ? (len_of_dst = \
			i) : (len_of_dst = count + ft_pf_find_minus(s) + num_of_ap);
	res = ft_pf_put_commas(res, s, all, len_of_dst);
	ft_strdel(&s);
	return (res);
}
