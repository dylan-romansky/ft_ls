/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dir.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dromansk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 16:19:14 by dromansk          #+#    #+#             */
/*   Updated: 2019/02/08 14:13:22 by dromansk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"
#include "lsenums.h"

int			add_dir(t_direct **dir, struct dirent *ent)
{
	t_direct		*n;
	struct stat		stats;
	unsigned char	tmp;

	if (!ent || stat(ent->d_name, &stats) == -1)
		return (0);
	n = *dir;
	while (n->next)
		n = n->next;
	tmp = n->flags;
	if (tmp & isdir)
		tmp -= isdir;
	n->next = new_direct(ent, n->path, tmp);
	return (1);
}

t_direct	*new_direct(struct dirent *direct, char *path, unsigned char flags)
{
	t_direct		*new;
	struct stat		*stats;

	stats = (struct stat *)malloc(sizeof(struct stat));
	stat(direct->d_name, stats);
	if (!(new = (t_direct *)malloc(sizeof(t_direct))))
		return (NULL);
	new->direct = direct;
	new->sub = NULL;
	new->next = NULL;
	if (is_type(*stats, S_IFDIR))
		flags |= isdir;
	new->flags = flags;
	new->path = path;
	return (new);
}

void		del_dir(t_direct *dir)
{
	t_direct		*del;

	del = dir;
	if (del->next)
		del_dir(del->next);
	free(del);
}
