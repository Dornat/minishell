/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpolosuk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 15:44:21 by dpolosuk          #+#    #+#             */
/*   Updated: 2018/03/27 17:48:55 by dpolosuk         ###   ########.fr       */
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
