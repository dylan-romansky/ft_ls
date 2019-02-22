/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_checks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dromansk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 20:11:38 by dromansk          #+#    #+#             */
/*   Updated: 2019/02/21 23:47:56 by dromansk         ###   ########.fr       */
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
	int			i;

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

int		will_fit(int extra, t_direct *d, int columns)
{
	int			i;
	t_direct	*cur;

	i = 1;
	cur = d;
	while (cur)
	{
		if (!(++i % columns) && (int)ft_strlen(d->name) > extra)
			return (0);
		cur = cur->next;
	}
	return (1);
}
