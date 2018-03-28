/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_qt_bs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpolosuk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/17 11:29:51 by dpolosuk          #+#    #+#             */
/*   Updated: 2018/03/28 11:23:13 by dpolosuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <msh.h>

int		parse_quote(char *s, int i)
{
	int		flag;

	flag = 0;
	while (s[i])
	{
		if (s[i] == '\'' && !flag)
			flag = 1;
		else if (s[i] == '\'' && flag)
			break ;
		i++;
	}
	i++;
	return (i);
}

int		parse_dquote(char *s, int i)
{
	int		flag;

	flag = 0;
	while (s[i])
	{
		if (s[i] == '\"' && !flag)
			flag = 1;
		else if (s[i] == '\\')
		{
			if (s[i + 1] == '\"' || s[i + 1] == '$' || s[i + 1] == '\\')
				i++;
		}
		else if (s[i] == '\"' && flag)
			break ;
		i++;
	}
	i++;
	return (i);
}

/*
** parse_qt_bs checks whether there are matching quoting chars or there are not
** and moves iterator and if there are no matching char it returns 1
*/

int		parse_qt_bs(char *s, int i, t_cli *cli)
{
	while (s[i])
	{
		if (s[i] == '\'')
		{
			if (parse_qt_are_there_null(s, i, cli))
				return (1);
			i = parse_quote(s, i);
		}
		else if (s[i] == '\"')
		{
			if (parse_qt_are_there_null(s, i, cli))
				return (1);
			i = parse_dquote(s, i);
		}
		else if (s[i] == '\\')
		{
			if (parse_qt_are_there_null(s, i, cli))
				return (1);
			i = i + 2;
		}
		else
			i++;
	}
	return (0);
}
