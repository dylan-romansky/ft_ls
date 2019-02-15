/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fstruct.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dromansk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 15:12:09 by dromansk          #+#    #+#             */
/*   Updated: 2019/02/14 19:30:11 by dromansk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FSTRUCT_H
# define FSTRUCT_H
# include "lsenums.h"
# include "lstructs.h"

t_ftypes g_ftypes[] =
{
	{'1', 0},
	{'l', l},
	{'R', R},
	{'a', a},
	{'r', r},
	{'t', t},
	{'g', g},
	{'f', f + a}
};

/*
**	{'u', u},
**	{'d', d}
*/

/*
** normal shit is white
** directories are blue
** executable is red
** symlink is magenta
** socket is green
** pipe (fifo) is brown
** block (b) cyan and blue
** character special file grey with yellow background (maybe blue brown)
** executable with set uid bit is black/red bg
** executable, set gid bit black/cyan bg
** directory writable to others sticky black/green bg
** directory writable no sticky black/brown bg
*/

#endif
