/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_semicol.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpolosuk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 18:18:00 by dpolosuk          #+#    #+#             */
/*   Updated: 2018/03/23 12:27:31 by dpolosuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <msh.h>

static int		semicol_num(char *s)
{
	int		i;
	int		num;

	i = 0;
	num = 1;
	while (s[i])
	{
		if (s[i] == '\'')
			i = parse_quote(s, i);
		else if (s[i] == '\"')
			i = parse_dquote(s, i);
		else if (s[i] == '\\')
			i = i + 2;
		else if (s[i] == ';')
		{
			num++;
			i++;
		}
		else
			i++;
	}
	return (num);
}

static int		find_semicol(char *s)
{
	int		i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '\'')
			i = parse_quote(s, i);
		else if (s[i] == '\"')
			i = parse_dquote(s, i);
		else if (s[i] == '\\')
			i = i + 2;
		else if (s[i] == ';')
			return (i);
		else
			i++;
	}
	return (i);
}

static char		*split_sem(char *s, int *beg, int *end)
{
	char	*res;
	int		len;

	*end = find_semicol(s + *beg) + *beg;
	len = *end - *beg;
	res = ft_strsub(s, *beg, len);
	*beg = *end + 1;
	return (res);
}

char			**split_semicol(char *s)
{
	char	**res;
	int		len;
	int		i;
	int		j;
	int		k;

	if (!s)
		return (NULL);
	i = 0;
	j = 0;
	k = 0;
	len = semicol_num(s);
	if (!(res = (char**)malloc(sizeof(char*) * (len + 1))))
		return (NULL);
	while (i < len)
	{
		res[i] = split_sem(s, &j, &k);
		i++;
	}
	res[i] = NULL;
	return (res);
}
