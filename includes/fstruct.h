/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fstruct.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dromansk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 15:12:09 by dromansk          #+#    #+#             */
/*   Updated: 2019/02/13 22:23:02 by dromansk         ###   ########.fr       */
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
*/

#endif
