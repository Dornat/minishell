/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpolosuk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 16:13:39 by dpolosuk          #+#    #+#             */
/*   Updated: 2018/03/18 19:10:44 by dpolosuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strrchr(const char *s, int c)
{
	size_t	j;

	if (!s)
		return (NULL);
	j = ft_strlen(s);
	if (s[j] == '\0' && c == '\0')
		return ((char*)(s + j));
	while (j--)
	{
		if (s[j] == c)
			return ((char*)(s + j));
	}
	if (s[j] == '\0')
		return (NULL);
	return (NULL);
}
