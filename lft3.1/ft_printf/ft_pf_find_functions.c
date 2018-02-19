/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_find_functions.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpolosuk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/22 17:35:05 by dpolosuk          #+#    #+#             */
/*   Updated: 2017/12/26 11:28:43 by dpolosuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

static int	ft_pf_ishex(char c)
{
	if (c == 'a' || c == 'b' || c == 'c' || c == 'd' || c == 'e' || c == 'f' \
	|| c == '0' || c == '1' || c == '2' || c == '3' || c == '4' || c == '5' || \
	c == '6' || c == '7' || c == '8' || c == '9')
		return (1);
	return (0);
}

int			ft_pf_find_minus(char *s)
{
	int		i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '-')
			return (1);
		i++;
	}
	return (0);
}

int			ft_pf_find_digit_index(char *s)
{
	int		i;

	i = 0;
	while (s[i])
	{
		if (ft_isdigit(s[i]))
			return (i);
		i++;
	}
	return (0);
}

int			ft_pf_find_hex_index(char *s)
{
	int		i;

	i = 0;
	while (s[i])
	{
		if (ft_pf_ishex(s[i]))
			return (i);
		i++;
	}
	return (0);
}
