/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_split_arg_num.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpolosuk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/24 13:21:59 by dpolosuk          #+#    #+#             */
/*   Updated: 2018/03/28 11:32:09 by dpolosuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <msh.h>

static void		anum_incr(char *s, int i, int *anum)
{
	if (i == 0)
		*anum = *anum + 1;
	else
	{
		if (i == 1)
		{
			if (s[i - 1] == ' ' || s[i - 1] == '\t')
				*anum = *anum + 1;
		}
		else
		{
			if ((s[i - 1] == ' ' || s[i - 1] == '\t') && s[i - 2] != '\\')
				*anum = *anum + 1;
		}
	}
}

static void		arg_num_elif1(char *s, int *i, int *anum)
{
	anum_incr(s, *i, anum);
	*i = *i + 1;
	while (s[*i] != '\'')
		*i = *i + 1;
	*i = *i + 1;
}

static void		arg_num_elif2(char *s, int *i, int *anum)
{
	anum_incr(s, *i, anum);
	*i = *i + 1;
	while (1)
	{
		if (s[*i] == '\"' && s[*i - 1] != '\\')
			break ;
		*i = *i + 1;
	}
	*i = *i + 1;
}

static void		arg_num_elif3(char *s, int *i, int *anum)
{
	anum_incr(s, *i, anum);
	while (s[*i] != '\'' && s[*i] != '\\' && s[*i] != '\"' && s[*i] != ' '
			&& s[*i] != '\t' && s[*i])
		*i = *i + 1;
}

int				msh_split_arg_num(char *s)
{
	int		i;
	int		anum;

	i = 0;
	anum = 0;
	while (s[i])
	{
		if (s[i] == '\\')
		{
			anum_incr(s, i, &anum);
			i += 2;
		}
		else if (s[i] == '\'')
			arg_num_elif1(s, &i, &anum);
		else if (s[i] == '\"')
			arg_num_elif2(s, &i, &anum);
		else if (s[i] != '\'' && s[i] != '\\' && s[i] != '\"' && s[i] != ' '
											&& s[i] != '\t')
			arg_num_elif3(s, &i, &anum);
		else
			while ((s[i] == ' ' || s[i] == '\t') && s[i])
				i++;
	}
	return (anum);
}
