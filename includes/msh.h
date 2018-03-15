/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpolosuk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/27 16:08:10 by dpolosuk          #+#    #+#             */
/*   Updated: 2018/03/15 12:30:03 by dpolosuk         ###   ########.fr       */
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
** Max buffer for termtype according to convention (from termcap man)
*/

# define CONV_MAX_BUFF 2048

/*
** Defines for capabilities in termcap
*/

# define MV_LEFT			"le"
# define MV_RIGHT			"nd"
# define MV_DOWN			"do"
# define MV_UP				"up"
# define MV_BEG				"cr"
# define DEL_CHR			"dc"
# define ENT_INS_MODE		"im"
# define LEAVE_INS_MODE		"ei"
# define ENT_STOUT_MODE		"so"
# define LEAVE_STOUT_MODE	"se"
# define CLEAR_SCREEN		"cd"
# define SAVE_CRS_POS		"sc"
# define RESTR_CRS_POS		"rc"

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
# define ENTER_KEY		"\n"

/*
** Struct for saving cursor position and terminal resolution
*/

typedef struct		s_cpos
{
	int		w_cols;
	int		w_rows;
	int		col;
	int		row;
	int		grows;
}					t_cpos;

/*
** Struct for prompt
*/

typedef struct		s_prmt
{
	char	*p;
	int		len;
}					t_prmt;

/*
** Struct for command line interface, which includes other structs
*/

typedef struct		s_cli
{
	t_cpos		crs;
	t_prmt		prt;
	char		*cmd;
	char		**env;
}					t_cli;

/*
** Defines for t_cli struct
*/

# define CRS cli->crs
# define PRT cli->prt
# define CMD cli->cmd

/*
** Main functions
*/

void				init_term_data(t_cli *cli);
void				enable_raw_mode(void);
char				**copy_env();
void				init_cpos(t_cli *cli);

/*
** Key process functions
*/

void				key_process(char *c, t_cli *cli);
void				insert_chr_in_cmdl(char *c, t_cli *cli);
void				del_chr_from_cmdl(t_cli *cli);
void				refresh_cli(t_cli *cli);

/*
** Misc functions
*/

int					ft_isnotprint(int c);
int					ft_putcchar(int c);

#endif
