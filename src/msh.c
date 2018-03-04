/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpolosuk <hmarvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/27 15:58:07 by dpolosuk          #+#    #+#             */
/*   Updated: 2018/03/04 19:07:18 by dpolosuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <msh.h>

#define CONV_MAX_BUFF 2048

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

void	init_term_data(void)
{
	char	buf[CONV_MAX_BUFF];
	char	*termtype;

	termtype = find_term_type();
	tgetent(buf, termtype);
	enable_raw_mode();
}

int		main(void)
{
	char	c[5];
	int		p;
	int		tp;
	char	*prompt;
	unsigned int		i = 0;
	int		prompt_len;
	struct winsize ws;

	ioctl(0, TIOCGWINSZ, &ws);
	p = 0;
	tp = 0;
	printf("term_width: %d\n", ws.ws_col);
	prompt = ft_strdup("[msh] $> \0");
	prompt_len = ft_strlen(prompt);
	ft_putstr(prompt);
	init_term_data();
	while (1)
	{
		ft_bzero(c, 5);
		read(0, c, 5);
		if (!ft_isnotprint(c[0]))
		{
			tputs(tgetstr(ENT_INS_MODE, NULL), 0, ft_putcchar);
			ft_putstr_fd(c, 0);
			++p;
			++tp;
			if ((tp + prompt_len) % ws.ws_col == 0)
			{
				ft_putstr_fd(" ", 0);
				tputs(tgetstr(MV_LEFT, NULL), 0, ft_putcchar);
			}
			tputs(tgetstr(LEAVE_INS_MODE, NULL), 0, ft_putcchar);
		}
		else if ((!ft_strcmp(c, LEFT_ARROW) || !ft_strcmp(c, CTRL_B)) && tp)
		{
			tputs(tgetstr(MV_LEFT, NULL), 0, ft_putcchar);
			--tp;
		}
		else if ((tp < p) && (!ft_strcmp(c, RIGHT_ARROW) || !ft_strcmp(c, CTRL_F)))
		{
			if ((tp + prompt_len + 1) % ws.ws_col == 0)
				tputs(tgetstr(MV_DOWN, NULL), 0, ft_putcchar);
			else
				tputs(tgetstr(MV_RIGHT, NULL), 0, ft_putcchar);
			++tp;
		}
		else if (!ft_strcmp(c, CTRL_A))
		{
			i = tp;
			while (i--)
				tputs(tgetstr(MV_LEFT, NULL), 0, ft_putcchar);
			tp = 0;
		}
		else if (!ft_strcmp(c, CTRL_E))
		{
			/* i = tp; */
			/* while (i < p) */
			/* { */
			/* 	tputs(tgetstr(MV_RIGHT, NULL), 0, ft_putcchar); */
			/* 	i++; */
			/* } */
			/* tp = i; */
			//ft_putstr("\x1b[1;1H");
			//tputs(tgoto("cm", 1, 1), 0, ft_putcchar);
			//tputs(tgoto(tgetstr("cm", NULL), 0, 150), 0, ft_putcchar); // it's definitely works
			tputs(tgetstr("do", NULL), 0, ft_putcchar);
		}
		else if (!ft_strcmp(c, DEL_KEY) && p && tp)
		{
			if ((tp + prompt_len + 1) % ws.ws_col == 0)
			{
				tputs(tgetstr(ENT_INS_MODE, NULL), 0, ft_putcchar);
				ft_putstr_fd(" ", 0);
				tputs(tgetstr(LEAVE_INS_MODE, NULL), 0, ft_putcchar);
				tputs(tgetstr(MV_LEFT, NULL), 0, ft_putcchar);
			}
			else
				tputs(tgetstr(MV_LEFT, NULL), 0, ft_putcchar);
			tputs(tgetstr(DEL_CHR, NULL), 0, ft_putcchar);
			--p;
			--tp;
			/* if ((tp + prompt_len) % ws.ws_col == 0) */
			/* { */
			/* 	tputs(tgetstr(DEL_CHR, NULL), 0, ft_putcchar); */
			/* 	tputs(tgetstr(DEL_CHR, NULL), 0, ft_putcchar); */
			/* } */
		}
	}
}
