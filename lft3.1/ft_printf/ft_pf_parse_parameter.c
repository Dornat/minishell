/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_parse_parameter.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpolosuk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/22 17:07:32 by dpolosuk          #+#    #+#             */
/*   Updated: 2017/12/27 17:34:56 by dpolosuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

int				ft_pf_everything_failed(char c)
{
	if (!ft_pf_check_for_type(c) && !ft_pf_check_for_flag(c) && \
		!ft_pf_check_for_t_size(c) && !ft_pf_check_for_big_sdouxc(c) && \
		!ft_pf_check_for_every_type(c) && !ft_isdigit(c))
		return (1);
	return (0);
}

static int		ft_pf_are_there_dolar(const char *s)
{
	int		i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '$')
			return (1);
		i++;
	}
	return (0);
}

int				ft_pf_parse_parameter(const char **format)
{
	char	params[3];
	int		i;

	i = 0;
	if (!ft_pf_are_there_dolar(*format))
		return (0);
	while ((*format)[i] != '$')
	{
		if (ft_pf_check_for_type((*format)[i]) || (*format)[i] == '.' || \
			ft_pf_check_for_flag((*format)[i]) || \
			ft_pf_check_for_t_size((*format)[i]) || \
			ft_pf_check_for_big_sdouxc((*format)[i]) || (*format)[i] == '\0' \
			|| ft_pf_everything_failed((*format)[i]))
			return (0);
		params[i] = (*format)[i];
		i++;
	}
	params[i] = '\0';
	*format = *format + i + 1;
	return (ft_atoi(params));
}
