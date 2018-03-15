/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ent_key_processing.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpolosuk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/11 13:38:21 by dpolosuk          #+#    #+#             */
/*   Updated: 2018/03/15 16:35:15 by dpolosuk         ###   ########.fr       */
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

int		parse_qt_bc(char *s)
{
	int		i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
	{
		if (s[i] == '\\' || s[i] == '\'' || s[i] == '\"')
			return (1);
		i++;
	}
	return (0);
}

int		ent_key_processing(t_cli *cli)
{
	rfrsh_for_ent(cli);
	if (TMP[0] == '\0' && CMD[0])
		ft_memcpy(TMP, CMD, ft_strlen(CMD));
	else if (CMD[0])
		ft_strcat(TMP, CMD);
	if (parse_qt_bc(TMP))
	{
		if (PRT.tp == NULL)
		{
			PRT.tp = PRT.p;
			PRT.p = ft_strdup("> \0");
		}
	}
	else
	{
		if (PRT.tp)
		{
			ft_strdel(&PRT.p);
			PRT.p = PRT.tp;
			PRT.len = ft_strlen(PRT.p);
		}
		CRS.col = PRT.len;
		CRS.row = 0;
	}
	return (1);
}
