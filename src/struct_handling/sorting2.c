/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dromansk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 21:41:16 by dromansk          #+#    #+#             */
/*   Updated: 2019/02/14 16:22:29 by dromansk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"
#include "lsenums.h"

int		u_is_sorted(t_direct *d1, t_direct *d2)
{
	struct stat	s1;
	struct stat	s2;

	s1 = *d1->stats;
	s2 = *d2->stats;
	if (s1.st_atimespec.tv_sec < s2.st_atimespec.tv_sec)
		return (u);
	else if (s1.st_atimespec.tv_sec == s2.st_atimespec.tv_sec)
	{
		if (s1.st_atimespec.tv_nsec < s2.st_atimespec.tv_nsec)
			return (u);
		else if (s1.st_atimespec.tv_nsec == s2.st_atimespec.tv_nsec)
			return (is_sorted(d1->name, d2->name) ? u : 0);
	}
	return (0);
}

void	u_sort(t_direct **list)
{
	t_direct	*dir;
	t_direct	*last;

	dir = *list;
	last = NULL;
	while (dir->next)
	{
		if ((r & dir->flags) ==
				u_is_sorted(dir, dir->next))
		{
			if (dir != *list)
				last->next = dir->next;
			else
				*list = dir->next;
			dir_swap(&dir);
			dir = *list;
		}
		else
		{
			last = dir;
			dir = dir->next ? dir->next : dir;
		}
	}
//	f_sort(list);
}
