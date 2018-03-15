/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpolosuk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 18:13:45 by dpolosuk          #+#    #+#             */
/*   Updated: 2018/03/15 16:36:33 by dpolosuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <msh.h>

int		main(void)
{
	char		c[5];
	t_cli		cli;

	init_term_data(&cli);
	while (1)
	{
		ft_putstr(cli.prt.p);
		while (1)
		{
			ft_bzero(c, 5);
			read(0, c, 5);
			if (key_process(c, &cli))
			{
				ft_bzero(cli.cmd, ft_strlen(cli.cmd));
				ft_putchar('\n');
				break ;
			}
		}
	}
}
