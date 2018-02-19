/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_itoa_unsigned_long_long.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpolosuk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/19 13:07:15 by dpolosuk          #+#    #+#             */
/*   Updated: 2017/12/23 11:35:46 by dpolosuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

char			*ft_pf_itoa_unsigned_long_long(unsigned long long int ui)
{
	unsigned long long int		tmpn;
	unsigned long long int		len;
	char						*str;

	tmpn = ui;
	len = 2;
	while (tmpn /= 10)
		len++;
	if ((str = (char*)malloc(sizeof(char) * len)) == NULL)
		return (NULL);
	str[--len] = '\0';
	while (len--)
	{
		str[len] = ui % 10 + '0';
		ui = ui / 10;
	}
	return (str);
}
