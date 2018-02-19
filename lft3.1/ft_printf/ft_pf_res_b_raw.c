/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_res_b_raw.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpolosuk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/02 11:25:02 by dpolosuk          #+#    #+#             */
/*   Updated: 2018/01/02 11:26:50 by dpolosuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

char	*ft_pf_res_b_raw(t_format *all, va_list ap)
{
	char	*res;

	res = ft_pf_itob(ft_pf_long_long_u(all, ap));
	if (*res == '0' && (*all).precision_field_identifier == 1 && \
			(*all).precision_field == 0)
		res[0] = '\0';
	return (res);
}
