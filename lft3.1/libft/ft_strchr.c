/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpolosuk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 14:52:11 by dpolosuk          #+#    #+#             */
/*   Updated: 2017/12/09 12:25:57 by dpolosuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strchr(const char *s, int c)
{
	int		j;

	j = 0;
	while (s[j] != '\0')
	{
		if (s[j] == c)
			return ((char*)(s + j));
		j++;
	}
	if (s[j] == '\0' && c == '\0')
		return ((char*)(s + j));
	if (s[j] == '\0')
		return (NULL);
	return (NULL);
}
