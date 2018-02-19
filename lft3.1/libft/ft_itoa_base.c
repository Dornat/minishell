/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpolosuk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 12:04:00 by dpolosuk          #+#    #+#             */
/*   Updated: 2017/12/13 13:19:15 by dpolosuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static int		ft_count_c(unsigned long nb, int base)
{
	int		i;

	i = 0;
	while (nb != 0)
	{
		nb = nb / base;
		i++;
	}
	return (i);
}

char			*ft_itoa_base(unsigned int nb, int base)
{
	char		*ret;
	int			size;
	char		tab[17];
	int			i;

	if (nb == 0)
	{
		ret = (char *)malloc(sizeof(char) * 2);
		ret = "0";
		return (ret);
	}
	ft_strcpy(tab, "0123456789abcdef");
	size = ft_count_c(nb, base);
	ret = malloc(size + 1);
	i = 1;
	while (nb != 0)
	{
		ret[size - i] = tab[nb % base];
		nb = nb / base;
		i++;
	}
	ret[size] = '\0';
	return (ret);
}
