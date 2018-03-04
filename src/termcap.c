/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   termcap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpolosuk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/22 12:00:08 by dpolosuk          #+#    #+#             */
/*   Updated: 2018/03/04 12:26:01 by dpolosuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <curses.h>
#include <term.h>
//#include <termcap.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <unistd.h>
#include <libft.h>
#include <msh.h>

void	enable_raw_mode(void)
{
	struct termios		raw;

	tcgetattr(0, &raw);
	raw.c_lflag &= ~(ICANON);
	//raw.c_lflag &= ~(ISIG); for disabling C-c (maybe other SIGNALS)
	raw.c_lflag &= ~(ECHO);
	raw.c_oflag &= ~(OPOST);
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

int		main(void)
{
	char	buf[2048];
	char	*termtype = getenv("tty");
	printf("%s\n", termtype);
	tgetent(buf, termtype);
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
	char	*prompt;
	int		i = 0;

	prompt = ft_strdup("[msh] $> \0");
	ft_putstr(prompt);
	enable_raw_mode();
	while (1)
	{
		ft_bzero(c, 5);
		read(0, c, 5);
		if (!ft_isnotprint(c[0]))
		{
			tputs(tgetstr(ENT_INS_MODE, NULL), 0, ft_putcchar);
			ft_putstr_fd(c, 0);
			tputs(tgetstr(LEAVE_INS_MODE, NULL), 0, ft_putcchar);
			++p;
			++tp;
		}
		else if ((!ft_strcmp(c, LEFT_ARROW) || !ft_strcmp(c, CTRL_B)) && tp)
		{
			tputs(tgetstr(MV_LEFT, NULL), 0, ft_putcchar);
			--tp;
		}
		else if ((tp < p) && (!ft_strcmp(c, RIGHT_ARROW) || !ft_strcmp(c, CTRL_F)))
		{
			tputs(tgetstr(MV_RIGHT, NULL), 0, ft_putcchar);
			++tp;
		}
		else if (!ft_strcmp(c, CTRL_A))
		{
			i = 0;
			int len = ft_strlen(prompt);
			tputs(tgetstr(MV_BEG, NULL), 0, ft_putcchar);
			while (i < len)
			{
				tputs(tgetstr(MV_RIGHT, NULL), 0, ft_putcchar);
				i++;
			}
			tp = 0;
		}
		else if (!ft_strcmp(c, CTRL_E))
		{
			i = tp;
			while (i < 50)
			{
				tputs(tgetstr(MV_RIGHT, NULL), 0, ft_putcchar);
				i++;
			}
			tp = i;
			/* tputs(tgoto(tgetstr("cm", NULL), 15, 73), 1, ft_putcchar); */
			/* tputs(tgetstr("dl", NULL), 1, ft_putcchar); */
			/* tputs(tgetstr("im", NULL), 1, ft_putcchar); */
		}
		else if (!ft_strcmp(c, DEL_KEY) && p && tp)
		{
			tputs(tgetstr(MV_LEFT, NULL), 0, ft_putcchar);
			tputs(tgetstr(DEL_CHR, NULL), 0, ft_putcchar);
			--p;
			--tp;
		}
	}
	scanf("%s", s);
	if (!ft_isnotprint(s[0]))
	{
		//printf("%s\n", s);
		ft_putendl(s);
		//ft_printf("%S", c);
	}
	return(0);
}
