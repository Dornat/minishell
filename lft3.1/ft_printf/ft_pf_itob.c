/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_itob.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpolosuk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/02 11:20:34 by dpolosuk          #+#    #+#             */
/*   Updated: 2018/01/02 11:44:42 by dpolosuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

char	*ft_pf_itob(unsigned long long int octet)
{
	unsigned long long int		shifter;
	short						num_of_bits;
	char						*res;
	int							i;

	shifter = 1;
	num_of_bits = ft_count_bits(octet);
	shifter = shifter << (num_of_bits - 1);
	res = ft_strnew(num_of_bits);
	i = 0;
	if (octet & shifter)
		res[i++] = '1';
	while (shifter >>= 1)
	{
		if (octet & shifter)
			res[i] = '1';
		else
			res[i] = '0';
		i++;
	}
	return (res);
}
