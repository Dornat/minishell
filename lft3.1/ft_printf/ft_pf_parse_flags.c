/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_parse_flags.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpolosuk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/22 17:11:42 by dpolosuk          #+#    #+#             */
/*   Updated: 2017/12/22 17:12:21 by dpolosuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

void	ft_pf_parse_flags(const char **format, t_format *all)
{
	while (**format != '*' && !ft_pf_check_for_t_size(**format) && \
				!ft_pf_check_for_type(**format) && **format != '.')
	{
		if (ft_pf_check_for_flag(**format))
		{
			if (**format == '\'')
				(*all).flag_apostrophe = 1;
			if (**format == '-')
				(*all).flag_minus = 1;
			else if (**format == '0')
				(*all).flag_zero = 1;
			if (**format == '+')
				(*all).flag_plus = 1;
			if (**format == ' ')
				(*all).flag_space = 1;
			if (**format == '#')
				(*all).flag_hash = 1;
			*format = *format + 1;
		}
		else
			break ;
	}
}
