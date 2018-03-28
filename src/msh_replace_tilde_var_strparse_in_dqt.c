/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_replace_tilde_var_strparse_in_dqt.c            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpolosuk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 19:37:26 by dpolosuk          #+#    #+#             */
/*   Updated: 2018/03/28 12:29:01 by dpolosuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <msh.h>

#define M ft_memmove
#define NORM (*s)[beg + 1]

static void		msh_replvins_if(char **s, char **env, int beg, int *end)
{
	M(*s + beg - 1, *s + beg + envlen(*s + beg), ft_strlen(*s + beg) + 1);
	*end = *end - (ft_strlen(*env) + 1);
	ft_strdel(env);
}

void			msh_replace_var_in_str(char **s, t_cli *cli, int beg, int *end)
{
	char	*env_val;
	char	*env;
	char	*tmp;

	tmp = NULL;
	beg++;
	env = ft_strsub(*s, beg, envlen(*s + beg));
	if ((env_val = grep_envvalue(env, cli)) == NULL)
		return (msh_replvins_if(s, &env, beg, end));
	tmp = *s;
	if (ft_strlen(*s + beg) - envlen(*s + beg) == 0)
		ft_bzero(*s + beg - 1, envlen(*s + beg));
	else
		M(*s + beg - 1, *s + beg + envlen(*s + beg), ft_strlen(*s + beg) + 1);
	*s = ft_strnew(ft_strlen(tmp) + ft_strlen(env_val));
	ft_strncpy(*s, tmp, beg - 1);
	ft_strcat(*s, env_val);
	ft_strcat(*s, tmp + beg - 1);
	if (envlen(*s + beg) + 1 < (int)ft_strlen(env_val))
		*end = *end + ft_strlen(env_val) - ft_strlen(env) - 1;
	else
		*end = *end - ((ft_strlen(env) + 1) - ft_strlen(env_val));
	ft_strdel(&env);
	ft_strdel(&tmp);
	ft_strdel(&env_val);
}

void			msh_strparse_in_dquote(char **s, t_cli *cli, int beg, int *end)
{
	beg++;
	while (beg < *end)
	{
		if ((*s)[beg] != '\\' && (*s)[beg] != '$')
			beg++;
		if ((*s)[beg] == '\\')
		{
			if ((*s)[beg + 1] == '$' || (*s)[beg + 1] == '\\' ||
				(*s)[beg + 1] == '\"')
			{
				ft_memmove(*s + beg, *s + beg + 1, ft_strlen(*s));
				beg++;
				*end = *end - 1;
			}
			else
				beg += 2;
		}
		else if ((*s)[beg] == '$')
		{
			if (NORM == '\0' || NORM == ' ' || NORM == '\"')
				beg++;
			else
				msh_replace_var_in_str(s, cli, beg, end);
		}
	}
}

void			msh_replace_tilde_in_str(char **s, t_cli *cli, int beg)
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
	ft_strncpy(*s, tmp, beg);
	ft_strcat(*s, home);
	ft_strcat(*s, tmp + beg);
	ft_strdel(&home);
	ft_strdel(&tmp);
}
