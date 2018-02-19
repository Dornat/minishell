/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_res_s_width.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpolosuk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/30 12:33:10 by dpolosuk          #+#    #+#             */
/*   Updated: 2017/12/30 12:35:19 by dpolosuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

static void		ft_pf_check_for_n_w(t_format *all)
{
	if ((*all).width_field < 0)
	{
		(*all).flag_minus = 1;
		(*all).width_field *= -1;
	}
}

char			*ft_pf_res_s_width(char *s, t_format *all)
{
	int		num_of_spaces;
	char	*res;
	int		i;
	int		j;

	res = NULL;
	i = 0;
	j = 0;
	ft_pf_check_for_n_w(all);
	if ((*all).width_field <= ((int)ft_strlen(s)))
		return (s);
	num_of_spaces = (*all).width_field - ft_strlen(s);
	res = ft_strnew((*all).width_field);
	while (i < num_of_spaces)
		res[i++] = ' ';
	while (s[j])
		res[i++] = s[j++];
	ft_strdel(&s);
	return (res);
}
