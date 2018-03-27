/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_strparse.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpolosuk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 15:44:47 by dpolosuk          #+#    #+#             */
/*   Updated: 2018/03/27 16:48:00 by dpolosuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <msh.h>

static void		msh_strparse_if(char **s, int *beg, int *i, int *end)
{
	*beg = *i;
	*end = parse_quote(*s, *i) - 1;
	ft_memmove(*s + *beg, *s + *beg + 1, ft_strlen(*s));
	*end = *end - 1;
	ft_memmove(*s + *end, *s + *end + 1, ft_strlen(*s));
	*i = *end;
}

static void		msh_strparse_elif1(char **s, int *beg, int *i, int *end)
{
	*beg = *i;
	*end = parse_dquote(*s, *i) - 1;
}

static void		msh_strparse_elif2(char **s, int *beg, int *i, int *end)
{
	ft_memmove(*s + *beg, *s + *beg + 1, ft_strlen(*s));
	end--;
	ft_memmove(*s + *end, *s + *end + 1, ft_strlen(*s));
	*i = *end;
}

char		*msh_strparse(char *s, t_cli *cli, int beg, int end)
{
	int		i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '\'')
			msh_strparse_if(&s, &beg, &i, &end);
		else if (s[i] == '\"')
		{
			msh_strparse_elif1(&s, &beg, &i, &end);
			msh_strparse_in_dquote(&s, cli, beg, &end);
			msh_strparse_elif2(&s, &beg, &i, &end);
		}
		else if (s[i] == '\\')
		{
			ft_memmove(s + i, s + i + 1, ft_strlen(s + i));
			i++;
		}
		else if (s[i] == '$')
		{
			beg = i;
			msh_replace_var_in_str(&s, cli, beg, &end);
		}
		else if (s[i] == '~')
		{
			beg = i;
			msh_replace_tilde_in_str(&s, cli, beg);
		}
		else
			i++;
	}
	return (s);
}
