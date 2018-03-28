/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpolosuk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 15:44:21 by dpolosuk          #+#    #+#             */
/*   Updated: 2018/03/28 13:08:34 by dpolosuk         ###   ########.fr       */
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

void	*ft_memmove2(void *dst, const void *src, size_t len)
{
	char		*d;
	const char	*s;
	size_t		i;
	size_t		j;
	size_t		len_src;

	d = dst;
	s = src;
	i = 0;
	j = 0;
	len_src = ft_strlen(s);
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
			if (j < len_src)
				j++;
		}
	}
	return (dst);
}
