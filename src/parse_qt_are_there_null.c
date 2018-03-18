/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_qt_are_there_null.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpolosuk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/17 11:34:24 by dpolosuk          #+#    #+#             */
/*   Updated: 2018/03/18 17:23:58 by dpolosuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <msh.h>

static int		parse_qt_are_there_null_if(char *s, int i, t_cli *cli)
{
	int		qt;

	qt = i;
	while (s[i])
	{
		i++;
		if (s[i] == '\'')
			return (0);
		else if (s[i] == '\0')
		{
			BS = qt;
			s[i] = '\n';
			return (1);
		}
	}
	return (0);
}

static int		parse_qt_are_there_null_elif(char *s, int i, t_cli *cli)
{
	int		qt;

	qt = i;
	while (s[i])
	{
		i++;
		if (s[i] == '\"' && s[i - 1] != '\\')
			return (0);
		else if (s[i] == '\0')
		{
			BS = qt;
			s[i] = '\n';
			return (1);
		}
	}
	return (0);
}

/*
** If there is no matching char for ' or " and there is \0 after \ - return 1
** and save cursor position into BS
*/

int				parse_qt_are_there_null(char *s, int i, t_cli *cli)
{
	int		qt;

	qt = i;
	if (s[i] == '\'')
		return (parse_qt_are_there_null_if(s, i, cli));
	else if (s[i] == '\"')
		return (parse_qt_are_there_null_elif(s, i, cli));
	else if (s[i] == '\\')
	{
		if (s[i + 1] == '\0')
		{
			BS = qt;
			return (1);
		}
	}
	return (0);
}
