/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpolosuk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 18:13:45 by dpolosuk          #+#    #+#             */
/*   Updated: 2018/03/07 11:00:37 by dpolosuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <msh.h>

int		main(void)
{
	char	c[5];
	t_cli		cli;

	init_term_data(&cli);
	ft_putstr(cli.prt.p);
	while (1)
	{
		ft_bzero(c, 5);
		read(0, c, 5);
		key_process(c, &cli);
	}
}
