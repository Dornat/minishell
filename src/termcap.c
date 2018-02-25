/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   termcap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpolosuk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/22 12:00:08 by dpolosuk          #+#    #+#             */
/*   Updated: 2018/02/25 22:06:36 by dpolosuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <curses.h>
#include <term.h>
//#include <termcap.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <libft.h>

void enableRawMode()
{
	struct termios		raw;

	tcgetattr(0, &raw);
	raw.c_lflag &= ~(ICANON);
	raw.c_lflag &= ~(ECHO);
	raw.c_cc[VTIME] = 1;
	raw.c_cc[VMIN] = 0;
	//raw.c_cc[VERASE] = 0177;
	//raw.c_cc[VINTR] = 3;
	//tcsetattr(STDIN_FILENO, TCSANOW, &raw);
	tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw);
}

int		ft_putcchar(int c)
{
	write(0, &c, 1);
	return (1);
}

int		ft_isnotprint(int c)
{
	if ((c >= 0 && c <= 31) || c == 127)
		return (1);
	else
		return (0);
}

int		main(void)
{
	int		success;
	char	buf[2048];
	char	*termtype = getenv("TERM");
	printf("%s\n", termtype);

	success = tgetent(buf, termtype);
	printf("termlines %d\n", tgetnum("li"));
	printf("termcolumns %d\n", tgetnum("co"));

	char	*cm_gs;
	char	*nd_gs, *le_gs;
	extern char *UP;
	char	c[5];
	char	s[100];
	unsigned int		p;
	unsigned int		tp;

	p = 0;
	tp = 0;
	//cm_gs = tgetstr("cm", &area);
	//printf("|%s|\n", cm_gs);
	/*
	le_gs = tgetstr("dc", NULL);
	printf("|%s|\n", le_gs);
	printf("%llu\n", (unsigned long long int)*le_gs);
	 * */
	char	*prompt;

	prompt = ft_strdup("[msh] $> \0");
	ft_putstr(prompt);
	enableRawMode();
	while (1)
	{
		ft_bzero(c, 5);
		read(0, c, 5);
		if (!ft_isnotprint(c[0]))
		{
			tputs(tgetstr("im", NULL), 1, ft_putcchar);
			ft_putstr_fd(c, 0);
			tputs(tgetstr("ei", NULL), 1, ft_putcchar);
			++p;
			++tp;
		}
		else if ((!ft_strcmp(c, "\e[D") || !ft_strcmp(c, "\x02")) && tp)
		{
			tputs(tgetstr("le", NULL), 1, ft_putcchar);
			--tp;
		}
		else if ((tp < p) && (!ft_strcmp(c, "\e[C") || !ft_strcmp(c, "\x06")))
		{
			tputs(tgetstr("nd", NULL), 1, ft_putcchar);
			++tp;
		}
		else if (!ft_strcmp(c, "\x01"))
		{
			int i = 0;
			int len = ft_strlen(prompt);
			tputs(tgetstr("cr", NULL), 1, ft_putcchar);
			while (i < len)
			{
				tputs(tgetstr("nd", NULL), 1, ft_putcchar);
				i++;
			}
			tp = 0;
		}
		else if (!ft_strcmp(c, "\x7f") && p && tp)
		{
			tputs(tgetstr("le", NULL), 1, ft_putcchar);
			tputs(tgetstr("dc", NULL), 1, ft_putcchar);
			--p;
			--tp;
		}
	}
	/*
	scanf("%s", s);
	if (!ft_isnotprint(s[0]))
	{
		//printf("%s\n", s);
		ft_putendl(s);
		//ft_printf("%S", c);
	}
	 * */
	return(0);
}
