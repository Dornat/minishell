/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpolosuk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 16:51:26 by dpolosuk          #+#    #+#             */
/*   Updated: 2017/12/29 20:36:23 by dpolosuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strdup(const char *src)
{
	char	*cp;

	if (src == NULL)
		return (NULL);
	cp = (char*)malloc(sizeof(char) * ft_strlen(src) + 1);
	if (cp == NULL)
		return (NULL);
	ft_strcpy(cp, src);
	return (cp);
}
