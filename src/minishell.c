/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpolosuk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 17:40:04 by dpolosuk          #+#    #+#             */
/*   Updated: 2018/02/27 19:51:52 by dpolosuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <libft.h>
/*
1. print prompt
2. read command line (GNL)
3. parse command from line
4. record command in history list
5. check if it is builtin command
5.1. if true
5.1.1. exec command as builtin
5.2. else
5.2.1. do fork() and save pid of fork()
5.2.2. if pid == 0
5.2.2.1. do execv on command from parser
2.2.3. else
2.2.3.1. if command is in background job
2.2.3.1.1. record in list of background jobs
2.2.3.2. else
2.2.3.2.1. wait on pid of child process
*/

pid_t	g_pid;

void	signal_handler(int sig)
{
	if (!g_pid)
		exit(sig);
	else
		write(1, "\n", 1);
}

int		main(void)
{
	extern char		**environ;
	int				i;
	char			*line;

	i = 0;
	g_pid = 1;
	signal(SIGINT, signal_handler);
	while (1)
	{
		write(1, "[msh] $ ", 8);
		get_next_line(0, &line);
		if (!ft_strcmp(line, "env"))
		{
			i = 0;
			while (environ[i])
			{
				ft_putendl(environ[i]);
				i++;
			}
		}
		else if (!ft_strcmp(line, "exit"))
			exit(0);
		else if (!ft_strcmp(line, "ls"))
		{
			if ((g_pid = fork()) < 0)
				ft_putendl_fd("Fork returned error!!!", 2);
			else if (!g_pid)
			{
				char	*av[4] = {"/bin/ls", "-lR", "/usr", NULL};
				execve("/bin/ls", av, environ);
			}
			wait(NULL);
		}
		else if (!ft_strcmp(line, "clear") || !ft_strcmp(line, "\f"))
			ft_putstr("\e[1;1H\e[2J");
		else if (!ft_strcmp(line, "\0"))
			;
		else
		{
			ft_putstr_fd("minishell: ", 2);
			ft_putstr_fd(line, 2);
			ft_putendl_fd(": command not found", 2);
		}
	}
	return(0);
}
