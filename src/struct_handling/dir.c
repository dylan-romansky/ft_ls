/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dir.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dromansk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 16:19:14 by dromansk          #+#    #+#             */
/*   Updated: 2019/02/07 20:42:49 by dromansk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

int			add_dir(t_direct **dir, struct dirent *ent)
{
	t_direct	*n;
	struct stat	stats;

	if (!ent || stat(ent->d_name, &stats) == -1)
		return (0);
	n = *dir;
	if (!is_type(stats, S_IFDIR))
		add_file(dir, ent);
	while (n->next)
		n = n->next;
	n->next = new_direct(ent);
	return (1);
}

t_direct	*new_direct(struct dirent *direct)
{
	t_direct	*new;

	if (!(new = (t_direct *)malloc(sizeof(t_direct))))
		return (NULL);
	new->direct = direct;
	new->file = NULL;
	new->next = NULL;
	return (new);
}

void		del_dir(t_direct *dir)
{
	t_direct	*del;

	del = dir;
	if (del->file)
		del_file(del->file);
	if (del->next)
		del_dir(del->next);
	free(del);
}
