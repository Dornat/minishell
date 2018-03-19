/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpolosuk <hmarvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/27 15:58:07 by dpolosuk          #+#    #+#             */
/*   Updated: 2018/03/19 12:08:06 by dpolosuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <msh.h>

void	disable_raw_mode(void)
{
	extern struct termios 		g_orig_termios;

	tcsetattr(0, TCSANOW, &g_orig_termios);
}

void	enable_raw_mode(void)
{
	extern struct termios		g_raw;
	extern struct termios		g_orig_termios;

	tcgetattr(0, &g_raw);
	g_orig_termios = g_raw;
	g_raw.c_lflag &= ~(ICANON);
	//raw.c_lflag &= ~(ISIG);
	g_raw.c_lflag &= ~(ECHO);
	//raw.c_oflag &= ~(OPOST);
	//g_raw.c_cc[VTIME] = 0;
	g_raw.c_cc[VMIN] = 1;
	tcsetattr(0, TCSAFLUSH, &g_raw);
	//tcsetattr(0, TCSANOW, &raw);
}

int		ft_putcchar(int c)
{
	write(1, &c, 1);
	return (1);
}

int		ft_isnotprint(int c)
{
	if ((c >= 0 && c <= 31) || c == 127)
		return (1);
	else
		return (0);
}

char	*find_term_type()
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

void	init_cpos(t_cli *cli)
{
	struct winsize		ws;

	ioctl(0, TIOCGWINSZ, &ws);
	cli->crs.w_cols = ws.ws_col;
	cli->crs.w_rows = ws.ws_row;
	cli->crs.col = cli->prt.len;
	cli->crs.row = 0;
}

char	**copy_env()
{
	extern char		**environ;
	char			**cp;
	int				len;
	int				i;

	if (!environ)
		return (NULL);
	len = 0;
	i = 0;
	while (environ[len])
		len++;
	if (!(cp = (char**)malloc(sizeof(char*) * (len + 1))))
		return (NULL);
	while (i < len)
	{
		cp[i] = ft_strdup(environ[i]);
		i++;
	}
	cp[i] = NULL;
	return (cp);
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

/*
** lcins checks if last char in the string is equal to given char
*/

int		lcins(char c, char *s)
{
	if (s[ft_strlen(s) - 1] == c)
		return (1);
	return (0);
}

void	init_term_data(t_cli *cli)
{
	char	buf[CONV_MAX_BUFF];
	char*	termtype;

	termtype = find_term_type();
	tgetent(buf, termtype);
	ft_strdel(&termtype);
	enable_raw_mode();
	cli->prt.p = ft_strdup("[msh] $> \0");
	cli->prt.tp = NULL;
	cli->prt.len = ft_strlen(cli->prt.p);
	cli->cmd = ft_strnew(CMD_LEN);
	cli->tcmd = ft_strnew(CMD_LEN);
	cli->bs = 0;
	cli->brk = 0;
	cli->dqt = 0;
	cli->env = copy_env();
	cli->epth = NULL;
	cli->pth = ft_strnew(PATH_LEN);
	init_cpos(cli);
}

void	put_zeros_until_zero(char *c)
{
	int		i;

	i = 0;
	while (c[i])
	{
		c[i] = '\0';
		i++;
	}
}
