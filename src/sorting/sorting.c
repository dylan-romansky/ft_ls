/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dromansk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 21:41:16 by dromansk          #+#    #+#             */
/*   Updated: 2019/02/07 22:34:38 by dromansk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

/*
**stupid fucking retard fucking infiniting for no fucking reason
*/

int		is_sorted(char *s1, char *s2)
{
	printf("%s vs %s\n", s1, s2);
	while (*s1 && *s1 < *s2)
	{
		s1++;
		s2++;
	}
	if (*s1 <= *s2)
		return (1);
	return (0);
}

void	sort_file(t_file **list)
{
	t_file		*file;
	t_file		*next;

	file = *list;
	next = file->next;
	while (file->next)
	{
		printf("file\n");
		if (!is_sorted(file->file->d_name, next->file->d_name))
		{
			printf("we gucci\n");
			file->next = next->next;
			next->next = file;
			next = file->next;
			printf("we real gucci\n");
			sort_file(list);
		}
		else
		{
			file = file->next;
			next = next->next;
		}
	}
}

void	sort_dir(t_direct **list)
{
	t_direct	*dir;
	t_direct	*next;

	dir = *list;
	next = dir->next;
	while (dir->next)
	{
		printf("dir\n");
		if (!is_sorted(dir->direct->d_name, next->direct->d_name))
		{
			printf("we gucci\n");
			dir->next = next->next;
			next->next = dir;
			next = dir->next;
			printf("we real gucci\n");
			sort_dir(list);
		}
		else
		{
			dir = dir->next;
			next = next->next;
		}
	}
}
