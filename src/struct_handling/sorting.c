/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dromansk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 21:41:16 by dromansk          #+#    #+#             */
/*   Updated: 2019/02/13 15:39:12 by dromansk         ###   ########.fr       */
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
		return (r);
	return (0);
}

int		t_is_sorted(char *d1, char *d2)
{
	struct stat	*s1;
	struct stat	*s2;

	s1 = (struct stat *)malloc(sizeof(struct stat));
	s2 = (struct stat *)malloc(sizeof(struct stat));
	stat(d1, s1);
	stat(d2, s2);
	if (s1->st_mtimespec.tv_sec < s2->st_mtimespec.tv_sec)
		return (t);
	else if (s1->st_mtimespec.tv_sec == s2->st_mtimespec.tv_sec)
	{
		if (s1->st_mtimespec.tv_nsec < s2->st_mtimespec.tv_nsec)
			return (t);
		else if (s1->st_mtimespec.tv_nsec == s2->st_mtimespec.tv_nsec)
			return(is_sorted(d1, d2) ? t : 0);
	}
	return (0);
}

void	f_sort(t_direct **list)
{
	t_direct	*dir;
	t_direct	*last;

	dir = *list;
	last = NULL;
	while (dir->next)
	{
		if (!(ft_strcmp(dir->next->direct->d_name, ".") &&
			   ft_strcmp(dir->next->direct->d_name, "..")) &&
				!is_sorted(dir->direct->d_name, dir->next->direct->d_name))
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

void	t_sort(t_direct **list)
{
	t_direct	*dir;
	t_direct	*last;

	dir = *list;
	last = NULL;
	while (dir->next)
	{
		if ((t & dir->flags)
				== t_is_sorted(dir->direct->d_name, dir->next->direct->d_name))
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


void	sort_dir(t_direct **list)
{
	t_direct	*dir;
	t_direct	*last;

	dir = *list;
	last = NULL;
	while (dir->next)
	{
		if ((r & dir->flags) ==
				is_sorted(dir->direct->d_name, dir->next->direct->d_name))
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
