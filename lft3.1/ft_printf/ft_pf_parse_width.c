/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_parse_width.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpolosuk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/22 17:13:33 by dpolosuk          #+#    #+#             */
/*   Updated: 2017/12/28 13:55:50 by dpolosuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

#define FPCT ft_pf_check_for_t_size((*format)[i])
#define FPCBX ft_pf_check_for_big_sdouxc((*format)[i])

static void		ft_pf_parse_width_elif(const char **format, t_format *all, \
				va_list ap, int i)
{
	int			param;
	int			tmp;
	va_list		bp;

	*format = *format + 1;
	va_copy(bp, ap);
	param = ft_pf_parse_parameter(format);
	while (i < param)
	{
		tmp = va_arg(bp, int);
		if (i == (param - 1))
		{
			if (((*all).width_field_identifier && tmp) || \
				(!(*all).width_field_identifier && tmp))
			{
				(*all).width_field = tmp;
				(*all).width_field_identifier = 1;
			}
		}
		i++;
	}
}

static void		ft_pf_pw_if(t_format *all, va_list ap)
{
	(*all).width_field = va_arg(ap, int);
	(*all).width_field_identifier = 1;
}

static void		ft_pf_pw_else(char *res, t_format *all)
{
	int		tmp;

	tmp = ft_atoi(res);
	if (((*all).width_field_identifier && tmp) || \
		(!(*all).width_field_identifier && tmp))
	{
		(*all).width_field = tmp;
		(*all).width_field_identifier = 1;
	}
}

void			ft_pf_parse_width(const char **format, t_format *all, \
				va_list ap)
{
	char	*res;
	int		i;

	i = 0;
	res = ft_strnew(9);
	if (!(*all).parameter_field && **format == '*')
	{
		ft_pf_pw_if(all, ap);
		*format = *format + 1;
	}
	else if ((*all).parameter_field && !ft_pf_check_for_type(**format) && \
			!ft_pf_check_for_t_size(**format) && **format == '*')
		ft_pf_parse_width_elif(format, all, ap, i);
	else
	{
		while (!ft_pf_check_for_type((*format)[i]) && (*format)[i] != '.' && \
				!FPCT && !FPCBX && (*format)[i] && ft_isdigit((*format)[i]))
		{
			res[i] = (*format)[i];
			i++;
		}
		ft_pf_pw_else(res, all);
		*format = *format + i;
	}
	ft_strdel(&res);
}
