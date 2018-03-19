/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpolosuk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 16:13:39 by dpolosuk          #+#    #+#             */
/*   Updated: 2018/03/19 12:35:32 by dpolosuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strrchr(const char *s, int c)
{
	int		j;

	if (!s)
		return (NULL);
	j = (int)ft_strlen(s);
	if (s[j] == '\0' && c == '\0')
		return ((char*)(s + j));
	while (j)
	{
		if (s[j] == c)
			return ((char*)(s + j));
		j--;
	}
	if (j <= 0)
		return (NULL);
	if (s[j] == '\0')
		return (NULL);
	return (NULL);
}
