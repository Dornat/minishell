/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_put_everything_together.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpolosuk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/01 15:41:49 by dpolosuk          #+#    #+#             */
/*   Updated: 2018/02/02 15:34:56 by dpolosuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

static void		ft_pf_pet_extention(const char **format, t_format *all, \
		va_list ap, unsigned int *len)
{
	if (!ft_pf_check_for_every_type(**format))
		ft_pf_deal_with_shitty_type(format, all, ap, len);
	if (**format == '%')
		ft_pf_deal_with_percent(format, all, ap, len);
	if (**format == 'd' || **format == 'i' || **format == 'D')
		ft_pf_deal_with_d_i(all, ap, len);
	if (**format == 'u' || **format == 'U')
		ft_pf_deal_with_u(all, ap, len);
	if (**format == 'o' || **format == 'O')
		ft_pf_deal_with_o(all, ap, len);
	if (**format == 'x' || **format == 'X')
	{
		if (**format == 'X')
			(*all).big_x = 1;
		ft_pf_deal_with_x(all, ap, len);
	}
	if (**format == 'p')
		ft_pf_deal_with_p(all, ap, len);
	if (**format == 'c' || **format == 'C')
		ft_pf_deal_with_c(all, ap, len);
	if (**format == 's' || **format == 'S')
		ft_pf_deal_with_s(all, ap, len);
	if (**format == 'n')
		ft_pf_deal_with_n(all, ap, len);
}

void			ft_pf_put_everything_together(const char **format, \
		t_format *all, va_list ap, unsigned int *len)
{
	ft_pf_pet_extention(format, all, ap, len);
	if (**format == 'b')
		ft_pf_deal_with_b(all, ap, len);
	if (**format)
		*format = *format + 1;
}
