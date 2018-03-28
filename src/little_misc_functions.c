/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   little_misc_functions.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpolosuk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 12:06:22 by dpolosuk          #+#    #+#             */
/*   Updated: 2018/03/28 15:33:04 by dpolosuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <msh.h>

int		envlen(char *s)
{
	int		i;

	i = 0;
	while (ft_isalpha(s[i]) || s[i] == '_' || ft_isdigit(s[i]))
		i++;
	return (i);
}

/*
** lcins checks if last char in the string is equal to given char
*/

int		lcins(char c, char *s)
{
	if (s[ft_strlen(s) - 1] == c)
		return (1);
	return (0);
}

/*
** peekb does sneak peek backwards one char from last char in a string.
** If string has less than 2 chars in it, it's not good to go to that memory,
** this function helps to prevent doing that.
*/

int		peekb(char c, char *s)
{
	int		len;

	len = ft_strlen(s);
	if (len < 2)
		return (0);
	if (s[len - 2] == c)
		return (1);
	return (0);
}

void	free_double_ptr(char ***s)
{
	int		i;

	i = 0;
	if (!s || !*s)
		return ;
	while ((*s)[i])
	{
		ft_strdel(&(*s)[i]);
		i++;
	}
	free(*s);
	*s = NULL;
}

void	msh_strparse_elif4(char **s, t_cli *cli, t_norm *n)
{
	if ((*s)[n->i + 1] == '\0' || (*s)[n->i + 1] == ' ')
		n->i++;
	else
	{
		n->beg = n->i;
		msh_replace_var_in_str(s, cli, n->beg, &n->end);
	}
}
