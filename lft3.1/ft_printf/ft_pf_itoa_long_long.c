/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_itoa_long_long.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpolosuk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/19 11:16:16 by dpolosuk          #+#    #+#             */
/*   Updated: 2017/12/22 13:47:53 by dpolosuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

static void		itoa_isnegative(long long int *ll, long long int *negative)
{
	if (*ll < 0)
	{
		*ll *= -1;
		*negative = 1;
	}
}

static int		fc(int long long ll)
{
	unsigned long long tmpll;

	tmpll = ll;
	if (tmpll == -9223372036854775808U)
		return (1);
	else if (ll < -9223372036854775807 || ll > 9223372036854775807)
		return (2);
	return (0);
}

char			*ft_pf_itoa_long_long(int long long ll)
{
	long long int		tmpn;
	long long int		len;
	long long int		negative;
	char				*str;

	if (fc(ll))
		return ((fc(ll) == 1) ? (ft_strdup("-9223372036854775808")) : (NULL));
	tmpn = ll;
	len = 2;
	negative = 0;
	itoa_isnegative(&ll, &negative);
	while (tmpn /= 10)
		len++;
	len += negative;
	if ((str = (char*)malloc(sizeof(char) * len)) == NULL)
		return (NULL);
	str[--len] = '\0';
	while (len--)
	{
		str[len] = ll % 10 + '0';
		ll = ll / 10;
	}
	if (negative)
		str[0] = '-';
	return (str);
}
