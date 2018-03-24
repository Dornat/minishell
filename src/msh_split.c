/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_split.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpolosuk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 12:47:00 by dpolosuk          #+#    #+#             */
/*   Updated: 2018/03/23 13:07:42 by dpolosuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <msh.h>

static int		arg_num(char *s)
{
	int		i;
	int		anum;

	i = 0;
	anum = 0;
	while (s[i])
	{
		while ((s[i] == ' ' || s[i] == '\t') && s[i])
			i++;
	}
	return (anum);
}

char		**msh_split(char *s, t_cli *cli)
{
	char	**res;

	res = NULL;
	return (res);
}
