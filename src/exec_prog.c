/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_prog.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpolosuk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/17 16:10:44 by dpolosuk          #+#    #+#             */
/*   Updated: 2018/03/28 16:41:49 by dpolosuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <msh.h>

static char		**environ_from_t_list(t_list *env)
{
	char	**res;
	int		len;
	int		i;
	t_list	*p;

	len = ft_lstlen(env);
	i = 0;
	p = env;
	if ((res = (char**)malloc(sizeof(char*) * (len + 1))) == NULL)
		return (NULL);
	while (i < len)
	{
		res[i] = ft_strdup(p->content);
		i++;
		p = p->next;
	}
	res[i] = NULL;
	return (res);
}

void			exec_prog(t_cli *cli)
{
	extern pid_t			g_pid;
	extern struct termios	g_raw;
	extern char				**environ;
	char					**env;

	env = environ_from_t_list(ENV);
	if ((g_pid = fork()) < 0)
		ft_putendl_fd("Fork returned error!!!???", 2);
	else if (!g_pid)
	{
		disable_raw_mode();
		execve(PTH, ACMD, env);
	}
	wait(NULL);
	g_pid = 0;
	tcsetattr(0, TCSAFLUSH, &g_raw);
	free_double_ptr(&env);
}
