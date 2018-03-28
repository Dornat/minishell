/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpolosuk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 12:03:15 by dpolosuk          #+#    #+#             */
/*   Updated: 2018/03/28 12:11:00 by dpolosuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <msh.h>

char	*find_term_type(void)
{
	extern char		**environ;
	int				i;
	char			*res;

	i = 0;
	res = NULL;
	while (environ[i])
	{
		if (environ[i][0] == 'T')
		{
			if (!ft_strncmp(environ[i], "TERM=", 5))
			{
				res = ft_strdup(environ[i] + 5);
				return (res);
			}
		}
		i++;
	}
	return (NULL);
}

void	check_for_realloc(t_cli *cli)
{
	char	*tmp1;
	char	*tmp2;

	tmp1 = CMD;
	tmp2 = TMP;
	if ((ft_strlen(CMD) % 256 > 242) || (ft_strlen(TMP) % 256 > 242))
	{
		CMD = ft_strnew(ft_strlen(tmp1) * 2);
		ft_memcpy(CMD, tmp1, ft_strlen(tmp1));
		TMP = ft_strnew(ft_strlen(tmp2) * 2);
		ft_memcpy(TMP, tmp2, ft_strlen(tmp2));
		ft_strdel(&tmp1);
		ft_strdel(&tmp2);
	}
}

void	loops_elif_while(t_cli *cli, int no_such_file)
{
	if ((no_such_file = parse_cmd(cli)))
	{
		if (no_such_file == -1)
			ft_printf("msh: %s: Permission denied\n", ACMD[0]);
		else if (no_such_file == -2)
			ft_printf("msh: %s: No such file or directory\n", ACMD[0]);
		else if (ACMD[0])
			ft_printf("msh: %s: command not found\n", ACMD[0]);
	}
	else if (TMP[0])
	{
		if (BIF)
		{
			exec_builtin(cli);
			BIF = 0;
		}
		else
			exec_prog(cli);
	}
}

char	**fill_bi_names(void)
{
	char	**bis;

	bis = (char**)malloc(sizeof(char*) * 7);
	bis[0] = ft_strdup("exit");
	bis[1] = ft_strdup("cd");
	bis[2] = ft_strdup("env");
	bis[3] = ft_strdup("setenv");
	bis[4] = ft_strdup("unsetenv");
	bis[5] = ft_strdup("echo");
	bis[6] = NULL;
	return (bis);
}

void	init_prompt(t_cli *cli)
{
	char		*buf;
	char		*home;

	buf = NULL;
	ft_bzero(PRT.p, ft_strlen(PRT.p));
	home = grep_envvalue("HOME", cli);
	buf = getcwd(buf, PATH_LEN);
	ft_strcat(PRT.p, "\x1B[36m[");
	if (home != NULL)
	{
		if (!ft_strncmp(home, buf, ft_strlen(home)))
		{
			ft_strcat(PRT.p, "~");
			ft_strcat(PRT.p, buf + ft_strlen(home));
		}
		else
			ft_strcat(PRT.p, buf);
	}
	else
		ft_strcat(PRT.p, buf);
	ft_strcat(PRT.p, "]\x1B[0m $> ");
	ft_strdel(&buf);
	ft_strdel(&home);
}
