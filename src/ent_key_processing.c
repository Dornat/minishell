/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ent_key_processing.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpolosuk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/11 13:38:21 by dpolosuk          #+#    #+#             */
/*   Updated: 2018/03/27 11:23:42 by dpolosuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <msh.h>

static void		rfrsh_for_ent(t_cli *cli)
{
	reset_crs(cli);
	tputs(tgetstr(CLEAR_SCREEN, NULL), 0, ft_putcchar);
	tputs(tgetstr(ENT_INS_MODE, NULL), 0, ft_putcchar);
	ft_putstr_fd(PRT.p, 0);
	ft_putstr_fd(CMD, 0);
	tputs(tgetstr(LEAVE_INS_MODE, NULL), 0, ft_putcchar);
}

/*
** ent_key_processing processes ENTER key and handles quoting
*/

int		ent_key_processing(t_cli *cli)
{
	rfrsh_for_ent(cli);
	if (TMP[0] == '\0' && CMD[0])
		ft_memcpy(TMP, CMD, ft_strlen(CMD));
	else if (CMD[0])
		ft_strcat(TMP, CMD);
	if (parse_qt_bs(TMP, BS, cli))
	{
		if (PRT.tp == NULL)
		{
			PRT.tp = PRT.p;
			PRT.p = ft_strdup("> \0");
		}
		PRT.len = ft_strlen(PRT.p);
		CRS.col = PRT.len;
		CRS.row = 0;
		return (-1);
	}
	else
	{
		if (PRT.tp && PRT.p)
		{
			ft_strdel(&PRT.p);
			PRT.p = PRT.tp;
			PRT.tp = NULL;
		}
		CRS.col = PRT.len;
		CRS.row = 0;
		BS = 0;
	}
	return (1);
}
