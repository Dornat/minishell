/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_split.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpolosuk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 12:47:00 by dpolosuk          #+#    #+#             */
/*   Updated: 2018/03/24 21:03:37 by dpolosuk         ###   ########.fr       */
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

int			envlen(char *s)
{
	int		i;

	i = 0;
	while (ft_isalpha(s[i]) || s[i] == '_')
		i++;
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

char		*grep_envvalue(char *env_name, t_cli *cli)
{
	char		*res;
	char		*tmp;
	t_list		*ptr;

	tmp = ft_strjoin(env_name, "=");
	ptr = bi_find_env(ENV, tmp);
	res = extract_value_from_env((char*)ptr->content);
	ft_strdel(&tmp);
	return (res);
}

void		msh_replace_var_in_str(char **s, t_cli *cli, int beg, int *end)
{
	char	*env_val;
	char	*env;
	char	*tmp;
	int		len;
	int		tmpl;

	tmp = NULL;
	len = ft_strlen(*s);
	beg++;
	env = ft_strsub(*s, beg, envlen(*s + beg));
	if (!(env_val = grep_envvalue(env, cli)))
	{
		ft_memmove(*s + beg - 1, *s + beg + envlen(*s + beg), ft_strlen(*s + beg) + 1);
		return ;
	}
	tmpl = len - ft_strlen(env_val);
	if (envlen(*s + beg) + 1 < (int)ft_strlen(env_val))
	{
		tmp = *s;
		ft_memmove(*s + beg - 1, *s + beg + envlen(*s + beg), ft_strlen(*s + beg) + 1);
		*s = ft_strnew(ft_strlen(tmp) + ft_strlen(env_val));
		ft_memcpy(*s, tmp, ft_strlen(tmp));
		ft_memmove(*s + beg - 2 + ft_strlen(env_val), *s + beg - 2, ft_strlen(*s + beg - 2));
		ft_memcpy(*s + beg - 1, env_val, ft_strlen(env_val));
		ft_strdel(&tmp);
		*end = *end + ft_strlen(env_val) - ft_strlen(env) - 1;
	}
	else
	{
		ft_memmove(*s + beg - 1, *s + beg + envlen(*s + beg), ft_strlen(*s + beg) + 1);
		while (--len > tmpl)
			(*s)[len] = '\0';
		ft_memmove(*s + beg + ft_strlen(env_val) - 1, *s + beg - 1, ft_strlen(*s + beg - 1));
		ft_memcpy(*s + beg - 1, env_val, ft_strlen(env_val));
		*end = *end - ((ft_strlen(env) + 1) - ft_strlen(env_val));
	}
}

void		msh_strparse_in_dquote(char **s, t_cli *cli, int beg, int *end)
{
	beg++;
	while (beg < *end)
	{
		if ((*s)[beg] != '\\' || (*s)[beg] != '$')
			beg++;
		if ((*s)[beg] == '\\')
		{
			if ((*s)[beg + 1] == '$' || (*s)[beg + 1] == '\\' || (*s)[beg + 1] == '\"')
			{
				ft_memmove(*s + beg, *s + beg + 1, ft_strlen(*s));
				beg++;
				*end = *end - 1;
			}
			else
				beg += 2;
		}
		else if ((*s)[beg] == '$')
			msh_replace_var_in_str(s, cli, beg, end);
	}
}

void		msh_replace_tilde_in_str(char **s, t_cli *cli, int beg)
{
	char	*home;
	char	*tmp;
	int		len;

	home = grep_envvalue("HOME", cli);
	len = ft_strlen(home);
	tmp = *s;
	if (len == 1)
	{
		(*s)[beg] = home[0];
		return ;
	}
	ft_memmove(*s + beg, *s + beg + 1, ft_strlen(*s + beg));
	*s = ft_strnew(ft_strlen(tmp) + len);
	ft_memcpy(*s, tmp, ft_strlen(tmp));
	ft_memmove(*s + beg + len, *s + beg, ft_strlen(*s + beg));
	ft_memcpy(*s + beg, home, len);
	ft_strdel(&tmp);
}

char		*msh_strparse(char *s, t_cli *cli)
{
	int		i;
	int		beg;
	int		end;

	i = 0;
	beg = 0;
	end = 0;
	while (s[i])
	{
		if (s[i] == '\'')
		{
			beg = i;
			end = parse_quote(s, i) - 1;
			ft_memmove(s + beg, s + beg + 1, ft_strlen(s));
			end--;
			ft_memmove(s + end, s + end + 1, ft_strlen(s));
			i = end;
		}
		else if (s[i] == '\"')
		{
			beg = i;
			end = parse_dquote(s, i) - 1;
			msh_strparse_in_dquote(&s, cli, beg, &end);
			ft_memmove(s + beg, s + beg + 1, ft_strlen(s));
			end--;
			ft_memmove(s + end, s + end + 1, ft_strlen(s));
			i = end;
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

char		*msh_strsplit(char *s, t_cli *cli, int *beg, int *end)
{
	char	*res;

	res =  NULL;
	while (s[*beg] == ' ' || s[*beg] == '\t')
		*beg = *beg + 1;
	*end = find_whitespace(s + *beg) + *beg;
	res = ft_strsub(s, *beg, *end - *beg);
	res = msh_strparse(res, cli);
	*beg = *end + 1;
	return (res);
}

char		**msh_split(char *s, t_cli *cli)
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
