/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_dec_to_hex_functions.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpolosuk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/26 10:35:45 by dpolosuk          #+#    #+#             */
/*   Updated: 2017/12/26 16:13:08 by dpolosuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

char	*ft_pf_dec_to_hex(unsigned long long int input)
{
	char	*output;
	char	hex[16];
	int		i;
	int		bits_num;
	int		res_len;

	i = 0;
	bits_num = ft_count_bits(input);
	res_len = (bits_num % 4 == 0) ? (bits_num / 4) : ((bits_num / 4) + 1);
	output = ft_strnew(res_len);
	ft_strcpy(hex, "0123456789abcdef");
	while (i < res_len)
	{
		output[i++] = hex[(input % 16)];
		input >>= 4;
	}
	ft_strrev(output);
	return (output);
}
