/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dromansk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 19:33:57 by dromansk          #+#    #+#             */
/*   Updated: 2019/02/07 20:44:06 by dromansk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

int			add_file(t_direct **dir, struct dirent *ent)
{
	t_direct	*d;
	t_file		*n;

	d = *dir;
	n = NULL;
	if (!ent)
		return (0);
	if (!d->file)
		d->file = new_file(ent);
	else
	{
		n = d->file;
		while (n->next)
			n = n->next;
		n->next = new_file(ent);
	}
	return (1);
}

t_file	*new_file(struct dirent *file)
{
	t_file		*new;

	if (!(new = (t_file *)malloc(sizeof(t_file))))
		return (NULL);
	new->file = file;
	new->next = NULL;
	return (new);
}

void		del_file(t_file *file)
{
	t_file		*del;

	del = file;
	if (del->next)
		del_file(del->next);
	free(del);
}
