/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_split.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpolosuk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 12:47:00 by dpolosuk          #+#    #+#             */
/*   Updated: 2018/03/27 19:58:22 by dpolosuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <msh.h>

static int		find_whitespace(char *s)
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
		else if (s[i] == ' ' || s[i] == '\t')
			return (i);
		else
			i++;
	}
	return (i);
}

static char		*extract_value_from_env(char *env)
{
	int		i;
	char	*res;

	i = 0;
	res = NULL;
	while (env[i])
	{
		if (env[i] == '=')
		{
			i++;
			break ;
		}
		i++;
	}
	if (env[i] == '\0')
		return (NULL);
	res = ft_strdup(env + i);
	return (res);
}

char			*grep_envvalue(char *env_name, t_cli *cli)
{
	char		*res;
	char		*tmp;
	t_list		*ptr;

	tmp = ft_strjoin(env_name, "=");
	if (!(ptr = bi_find_env(ENV, tmp)))
	{
		ft_strdel(&tmp);
		return (NULL);
	}
	res = extract_value_from_env((char*)ptr->content);
	ft_strdel(&tmp);
	return (res);
}

char			*msh_strsplit(char *s, t_cli *cli, int *beg, int *end)
{
	char	*res;

	res = NULL;
	while (s[*beg] == ' ' || s[*beg] == '\t')
		*beg = *beg + 1;
	*end = find_whitespace(s + *beg) + *beg;
	res = ft_strsub(s, *beg, *end - *beg);
	res = msh_strparse(res, cli);
	*beg = *end + 1;
	return (res);
}

char			**msh_split(char *s, t_cli *cli)
{
	char	**res;
	int		i;
	int		len;
	int		beg;
	int		end;

	len = msh_split_arg_num(s);
	i = 0;
	beg = 0;
	end = 0;
	if (!(res = (char**)malloc(sizeof(char*) * (len + 1))))
		return (NULL);
	while (i < len)
	{
		res[i] = msh_strsplit(s, cli, &beg, &end);
		i++;
	}
	res[i] = NULL;
	return (res);
}
