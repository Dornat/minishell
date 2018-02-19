/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_deal_with_p_raw.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpolosuk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/27 10:19:17 by dpolosuk          #+#    #+#             */
/*   Updated: 2017/12/27 10:29:31 by dpolosuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

char	*ft_pf_res_p_raw(t_format *all, va_list ap)
{
	char	*res;

	res = NULL;
	res = ft_pf_dec_to_hex(ft_pf_normal_p(all, ap));
	if (*res == '0' && (*all).precision_field_identifier == 1 && \
			(*all).precision_field == 0)
		res[0] = '\0';
	return (res);
}
