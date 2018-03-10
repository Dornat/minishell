/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpolosuk <hmarvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/27 15:58:07 by dpolosuk          #+#    #+#             */
/*   Updated: 2018/03/07 12:09:20 by dpolosuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <msh.h>

void	enable_raw_mode(void)
{
	struct termios		raw;

	tcgetattr(0, &raw);
	raw.c_lflag &= ~(ICANON);
	//raw.c_lflag &= ~(ISIG);
	raw.c_lflag &= ~(ECHO);
	//raw.c_oflag &= ~(OPOST);
	raw.c_cc[VTIME] = 0;
	raw.c_cc[VMIN] = 1;
	//tcsetattr(0, TCSAFLUSH, &raw);
	tcsetattr(0, TCSANOW, &raw);
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
	cli->crs.prmt_l = cli->prt.len;
	cli->crs.col = cli->crs.prmt_l;
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
	if (!(cp = (char**)malloc(sizeof(char*) * len + 1)))
		return (NULL);
	while (i < len)
	{
		cp[i] = ft_strdup(environ[i]);
		i++;
	}
	cp[i] = NULL;
	return (cp);
}

void	init_term_data(t_cli *cli)
{
	char	buf[CONV_MAX_BUFF];
	char*	termtype;

	termtype = find_term_type();
	tgetent(buf, termtype);
	enable_raw_mode();
	cli->prt.p = ft_strdup("[msh] $> \0");
	cli->prt.len = ft_strlen(cli->prt.p);
	cli->cmd = ft_strnew(256);
	cli->env = copy_env();
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
