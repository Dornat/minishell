/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_dec_to_oct_functions.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpolosuk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/25 18:11:24 by dpolosuk          #+#    #+#             */
/*   Updated: 2017/12/26 16:25:33 by dpolosuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

char		*ft_pf_dec_to_oct_ui(unsigned int dec)
{
	char	*res;
	int		bits_num;
	int		res_len;
	int		i;

	i = 0;
	bits_num = ft_count_bits(dec);
	res_len = (bits_num % 3 == 0) ? (bits_num / 3) : ((bits_num / 3) + 1);
	res = ft_strnew(res_len);
	while (i < res_len)
	{
		res[i] = (dec & 7) + '0';
		dec = dec >> 3;
		i++;
	}
	ft_strrev(res);
	return (res);
}

char		*ft_pf_dec_to_oct_us(unsigned short dec)
{
	char	*res;
	int		bits_num;
	int		res_len;
	int		i;

	i = 0;
	bits_num = ft_count_bits(dec);
	res_len = (bits_num % 3 == 0) ? (bits_num / 3) : ((bits_num / 3) + 1);
	res = ft_strnew(res_len);
	while (i < res_len)
	{
		res[i] = (dec & 7) + '0';
		dec = dec >> 3;
		i++;
	}
	ft_strrev(res);
	return (res);
}

char		*ft_pf_dec_to_oct_uss(unsigned char dec)
{
	char	*res;
	int		bits_num;
	int		res_len;
	int		i;

	i = 0;
	bits_num = ft_count_bits(dec);
	res_len = (bits_num % 3 == 0) ? (bits_num / 3) : ((bits_num / 3) + 1);
	res = ft_strnew(res_len);
	while (i < res_len)
	{
		res[i] = (dec & 7) + '0';
		dec = dec >> 3;
		i++;
	}
	ft_strrev(res);
	return (res);
}

char		*ft_pf_dec_to_oct_ull(unsigned long long dec)
{
	char	*res;
	int		bits_num;
	int		res_len;
	int		i;

	i = 0;
	bits_num = ft_count_bits(dec);
	res_len = (bits_num % 3 == 0) ? (bits_num / 3) : ((bits_num / 3) + 1);
	res = ft_strnew(res_len);
	while (i < res_len)
	{
		res[i] = (dec & 7) + '0';
		dec = dec >> 3;
		i++;
	}
	ft_strrev(res);
	return (res);
}
