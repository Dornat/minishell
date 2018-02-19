/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_parse_precision.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpolosuk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/22 17:15:41 by dpolosuk          #+#    #+#             */
/*   Updated: 2017/12/30 18:11:25 by dpolosuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

#define FPCFC ft_pf_check_for_the_center(**format)
#define FPCFB ft_pf_check_for_big_sdouxc(**format)
#define FPCFF ft_pf_check_for_flag_except_zero(**format)

static int		ft_pf_check_for_flag_except_zero(char c)
{
	if (c == '\'' || c == '#' || c == ' ' || c == '-' || c == '+')
		return (1);
	return (0);
}

static void		ft_pf_parse_precision_elif(const char **format, t_format *all, \
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
			(*all).precision_field = tmp;
		i++;
	}
}

static void		ft_pf_parse_precision_if(const char **format, t_format *all, \
				va_list ap)
{
	(*all).precision_field = va_arg(ap, int);
	if ((*all).precision_field < 0)
		(*all).precision_field_identifier = 0;
	else
		(*all).precision_field_identifier = 1;
	*format = *format + 1;
}

void			ft_pf_parse_precision(const char **format, t_format *all, \
				va_list ap)
{
	char	res[9];
	int		i;

	i = 0;
	if (**format != '.')
		return ;
	while (**format == '.')
		*format = *format + 1;
	if (!(*all).parameter_field && **format == '*')
		ft_pf_parse_precision_if(format, all, ap);
	else if ((*all).parameter_field && **format == '*')
		ft_pf_parse_precision_elif(format, all, ap, i);
	else
	{
		while (!ft_pf_check_for_type(**format) && FPCFC && **format != '.' && \
				!ft_pf_check_for_t_size(**format) && !FPCFB && !FPCFF)
		{
			res[i] = **format;
			i++;
			*format = *format + 1;
		}
		res[i] = '\0';
		(*all).precision_field = ft_atoi(res);
		(*all).precision_field_identifier = 1;
	}
}
