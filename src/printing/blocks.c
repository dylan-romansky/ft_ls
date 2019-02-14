/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   blocks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dromansk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 18:43:51 by dromansk          #+#    #+#             */
/*   Updated: 2019/02/13 18:51:41 by dromansk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"
#include "lsenums.h"

void	get_blocks(t_direct *dir)
{
	int		blocks;

	blocks = 0;
	while (dir)
	{
		while (!(dir->flags & a) && !(ft_strcmp(dir->direct->d_name, ".") &&
					ft_strcmp(dir->direct->d_name, "..")))
			dir = dir->next;
		blocks += dir->stats->st_blocks;
		dir = dir->next;
	}
	ft_printf("total %d\n", blocks);
}
