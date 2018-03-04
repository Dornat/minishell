/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpolosuk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/27 16:08:10 by dpolosuk          #+#    #+#             */
/*   Updated: 2018/03/04 16:29:42 by dpolosuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MSH_H
# define MSH_H

# include <curses.h>
# include <term.h>
# include <sys/ioctl.h>
# include <stdio.h>
# include <libft.h>

/*
** Defines for capabilities in termcap
*/

# define MV_LEFT			"le"
# define MV_RIGHT			"nd"
# define MV_DOWN			"do"
# define MV_BEG				"cr"
# define DEL_CHR			"dc"
# define ENT_INS_MODE		"im"
# define LEAVE_INS_MODE		"ei"
# define ENT_STOUT_MODE		"so"
# define LEAVE_STOUT_MODE	"se"

/*
** Defines for keys
*/

# define LEFT_ARROW		"\e[D"
# define RIGHT_ARROW	"\e[C"
# define CTRL_B			"\x02"
# define CTRL_F			"\x06"
# define CTRL_A			"\x01"
# define CTRL_E			"\x05"
# define DEL_KEY		"\x7f"

#endif
