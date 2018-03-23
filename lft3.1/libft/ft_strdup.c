/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpolosuk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 16:51:26 by dpolosuk          #+#    #+#             */
/*   Updated: 2018/03/23 10:52:19 by dpolosuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strdup(const char *src)
{
	char	*cp;

	if (src == NULL)
		return (NULL);
	cp = (char*)malloc(sizeof(char) * (ft_strlen(src) + 1));
	if (cp == NULL)
		return (NULL);
	ft_strcpy(cp, src);
	cp[ft_strlen(cp)] = '\0';
	return (cp);
}
