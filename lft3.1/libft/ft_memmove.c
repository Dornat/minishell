/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpolosuk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 15:44:21 by dpolosuk          #+#    #+#             */
/*   Updated: 2018/03/28 14:05:00 by dpolosuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*d;
	const char	*s;
	size_t		i;

	d = dst;
	s = src;
	i = -1;
	if (s < d)
	{
		while ((int)--len >= 0)
			*(d + len) = *(s + len);
	}
	else
	{
		while (++i < len)
			*(d + i) = *(s + i);
	}
	return (dst);
}

void	*ft_memmove4(char *d, const char *s, size_t len, size_t slen)
{
	size_t		i;
	size_t		j;

	i = 0;
	j = 0;
	if (s < d)
	{
		while ((int)--len >= 0)
			d[len] = s[len];
	}
	else
	{
		while (i < len)
		{
			d[i] = s[j];
			i++;
			if (j < slen)
				j++;
		}
	}
	return (d);
}
