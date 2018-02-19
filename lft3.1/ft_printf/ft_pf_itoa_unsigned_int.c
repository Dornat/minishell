/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_itoa_unsigned_int.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpolosuk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/19 12:53:34 by dpolosuk          #+#    #+#             */
/*   Updated: 2017/12/23 11:35:19 by dpolosuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

char			*ft_pf_itoa_unsigned_int(unsigned int ui)
{
	unsigned int		tmpn;
	unsigned int		len;
	char				*str;

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
