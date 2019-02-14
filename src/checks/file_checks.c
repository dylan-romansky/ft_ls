/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_checks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dromansk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 20:11:38 by dromansk          #+#    #+#             */
/*   Updated: 2019/02/13 16:17:52 by dromansk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

int		is_type(struct stat stats, unsigned int type)
{
	if ((stats.st_mode & S_IFMT) == type)
		return (1);
	return (0);
}

void	del_path(char **path)
{
	int	i;

	i = 0;
	while (path[i])
		free(path[i++]);
	free(path);
}

int		is_end(t_direct *dir)
{
	while (dir)
	{
		if (is_type(*(dir->stats), S_IFDIR))
			return (0);
		dir = dir->next;
	}
	return (1);
}
