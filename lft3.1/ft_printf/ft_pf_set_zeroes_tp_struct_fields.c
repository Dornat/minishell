/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_set_zeroes_tp_struct_fields.c                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpolosuk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/28 11:35:48 by dpolosuk          #+#    #+#             */
/*   Updated: 2017/12/28 15:08:31 by dpolosuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

void	ft_pf_set_zeros_to_struct_fields(t_format *all)
{
	(*all).parameter_field = 0;
	(*all).flag_apostrophe = 0;
	(*all).flag_minus = 0;
	(*all).flag_plus = 0;
	(*all).flag_space = 0;
	(*all).flag_zero = 0;
	(*all).flag_hash = 0;
	(*all).precision_field_identifier = 0;
	(*all).width_field = 0;
	(*all).width_field_identifier = 0;
	(*all).precision_field = 0;
	(*all).t_size = 0;
	(*all).len_of_raw_s = 0;
	(*all).big_x = 0;
}
