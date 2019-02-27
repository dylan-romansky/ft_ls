/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dir.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dromansk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 16:19:14 by dromansk          #+#    #+#             */
/*   Updated: 2019/02/26 17:28:52 by dromansk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"
#include "lsenums.h"

void		fix_size_pad(t_direct **dir, int size)
{
	t_direct		*d;

	d = *dir;
	while (d)
	{
		if (d->size_pad > size)
		{
			fix_size_pad(dir, d->size_pad);
			return ;
		}
		d->size_pad = size;
		d = d->next;
	}
}

int			add_dir(t_direct **dir, struct dirent *ent)
{
	t_direct		*n;

	if (!ent)
		return (0);
	n = *dir;
	while (n->next)
		n = n->next;
	n->next = new_direct(ent->d_name, n->path, n->flags);
	return (1);
}

void		d_fill(t_direct **dir)
{
	t_direct		*new;
	struct stat		*stats;

	new = *dir;
	stats = new->stats;
	new->userlen = ft_strlen(new->user);
	new->grouplen = ft_strlen(new->group);
	new->size_pad = number_length(new->size);
	new->link_pad = number_length(stats->st_nlink);
}

t_direct	*new_direct(char *name, char *path, short flags)
{
	t_direct		*new;
	struct stat		*stats;
	char			*fpath;

	if ((*name == '.' && !(flags & a)) || ((!ft_strcmp(name, ".")
					|| !ft_strcmp(name, "..")) && flags & A))
		return (NULL);
	fpath = fix_input(path);
	fpath = (*name == '.' && (name[1] == '.' || name[1] == '/')) ?
			swap_n_free(ft_strdup(name), &fpath) :
			swap_n_free(ft_strjoin(fpath, name), &fpath);
	stats = (struct stat *)malloc(sizeof(struct stat));
	lstat(fpath, stats);
	free(fpath);
	if (!(new = (t_direct *)malloc(sizeof(t_direct))))
		return (NULL);
	new->name = ft_strdup(name);
	new->user = handle_uid(stats->st_uid);
	new->group = handle_gid(stats->st_gid);
	new->size = stats->st_size;
	new->stats = stats;
	new->flags = flags;
	new->path = path;
	new->next = NULL;
	d_fill(&new);
	return (new);
}

void		del_dir(t_direct *dir)
{
	t_direct		*del;

	del = dir;
	free(dir->name);
	free(dir->stats);
	free(dir->group);
	free(dir->user);
	if (del->next)
		del_dir(del->next);
	free(del);
}
