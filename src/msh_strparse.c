/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_strparse.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpolosuk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 15:44:47 by dpolosuk          #+#    #+#             */
/*   Updated: 2018/03/28 13:53:00 by dpolosuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <msh.h>

static void		msh_strparse_if(char **s, t_norm *n)
{
	n->beg = n->i;
	n->end = parse_quote(*s, n->i) - 1;
	ft_memmove(*s + n->beg, *s + n->beg + 1, ft_strlen(*s));
	n->end = n->end - 1;
	ft_memmove(*s + n->end, *s + n->end + 1, ft_strlen(*s));
	n->i = n->end;
}

static void		msh_strparse_elif1(char **s, t_cli *cli, t_norm *n)
{
	n->beg = n->i;
	n->end = parse_dquote(*s, n->i) - 1;
	msh_strparse_in_dquote(s, cli, n->beg, &n->end);
	ft_memmove(*s + n->beg, *s + n->beg + 1, ft_strlen(*s));
	n->end = n->end - 1;
	ft_memmove(*s + n->end, *s + n->end + 1, ft_strlen(*s));
	n->i = n->end;
}

static void		msh_strparse_elif2(char **s, t_norm *n)
{
	ft_memmove(*s + n->i, *s + n->i + 1, ft_strlen(*s + n->i));
	n->i++;
}

static void		msh_strparse_elif3(char **s, t_cli *cli, t_norm *n)
{
	n->beg = n->i;
	msh_replace_tilde_in_str(s, cli, n->beg);
}

char			*msh_strparse(char *s, t_cli *cli)
{
	t_norm		n;

	n.i = 0;
	n.beg = 0;
	n.end = 0;
	while (s[n.i])
	{
		if (s[n.i] == '\'')
			msh_strparse_if(&s, &n);
		else if (s[n.i] == '\"')
			msh_strparse_elif1(&s, cli, &n);
		else if (s[n.i] == '\\')
			msh_strparse_elif2(&s, &n);
		else if (s[n.i] == '$')
		{
			if (s[n.i + 1] == '\0' || s[n.i + 1] == ' ' )
				n.i++;
			else
			{
				n.beg = n.i;
				msh_replace_var_in_str(&s, cli, n.beg, &n.end);
			}
		}
		else if (s[n.i] == '~')
			msh_strparse_elif3(&s, cli, &n);
		else
			n.i++;
	}
	return (s);
}
