/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dromansk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 21:41:16 by dromansk          #+#    #+#             */
/*   Updated: 2019/02/08 14:54:44 by dromansk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"
#include "lsenums.h"

int		is_sorted(char *s1, char *s2)
{
	while (*s1 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	if (*s1 <= *s2)
		return (1);
	return (0);
}

void	dir_swap(t_direct **current)
{
	t_direct	*tmp;

	tmp = (*current)->next->next;
	(*current)->next->next = (*current);
	(*current)->next = tmp;
}

void	sort_dir(t_direct **list)
{
	t_direct	*dir;
	t_direct	*last;

	dir = *list;
	last = NULL;
	while (dir->next)
	{
		if ((r & dir->flags) == is_sorted(dir->direct->d_name, dir->next->direct->d_name))
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
}
