/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_semicol.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpolosuk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 18:18:00 by dpolosuk          #+#    #+#             */
/*   Updated: 2018/03/24 20:10:48 by dpolosuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <msh.h>

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

/*
** is there alphabetic character (other then ' ' or '\t') between semicolons
*/

static int		isalpha_betw_sc(char *s, int beg, int end)
{
	while (beg < end)
	{
		if (s[beg] != ' ' && s[beg] != '\t')
			return (1);
		beg++;
	}
	return (0);
}

/*
** if there are no chars other then ' ' or '\t' between semicols split_sem will
** skip it and won't allocate memory for empty space
*/

static char		*split_sem(char *s, int *beg, int *end)
{
	char	*res;
	int		len;

	res = NULL;
	while (1)
	{
		while (s[*beg] == ';')
			(*beg)++;
		*end = find_semicol(s + *beg) + *beg;
		if (isalpha_betw_sc(s, *beg, *end))
			break ;
		else
		{
			if (s[*end] == '\0')
				return (NULL);
			*beg = *end + 1;
		}
	}
	len = *end - *beg;
	res = ft_strsub(s, *beg, len);
	*beg = *end + 1;
	return (res);
}

static int		semicolarg_num(char *s, int beg, int end)
{
	int		num;

	num = 0;
	while (s[end])
	{
		while (1)
		{
			while (s[beg] == ';')
				beg++;
			end = find_semicol(s + beg) + beg;
			if (isalpha_betw_sc(s, beg, end))
				break ;
			else
			{
				if (s[end] == '\0')
					return (num);
				beg = end + 1;
			}
		}
		num++;
		beg = end + 1;
	}
	return (num);
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
	len = semicolarg_num(s, 0, 0);
	if (len == 0)
		len = 1;
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
