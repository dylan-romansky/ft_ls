/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dir.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dromansk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 16:19:14 by dromansk          #+#    #+#             */
/*   Updated: 2019/02/22 00:46:28 by dromansk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"
#include "lsenums.h"

int			num_len(long long n)
{
	int				i;

	i = 1;
	while (n /= 10)
		i++;
	return (i);
}

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

t_direct	*new_direct(char *name, char *path, short flags)
{
	t_direct		*new;
	struct stat		*stats;
	char			*fpath;

	if (*name == '.' && !(flags & a))
		return (NULL);
	if ((!ft_strcmp(name, ".") || !ft_strcmp(name, "..")) && flags & A)
		return (NULL);
	fpath = (*name == '.' && (name[1] == '.' || name[1] == '/')) ?
			ft_strdup(name) : ft_strjoin(path, name);
	stats = (struct stat *)malloc(sizeof(struct stat));
	lstat(fpath, stats);
	free(fpath);
	if (!(new = (t_direct *)malloc(sizeof(t_direct))))
		return (NULL);
	new->name = ft_strdup(name);
	new->user = handle_uid(stats->st_uid);
	new->userlen = ft_strlen(new->user);
	new->group = handle_gid(stats->st_gid);
	new->size = stats->st_size;
	new->grouplen = ft_strlen(new->group);
	new->size_pad = num_len(new->size);
	new->link_pad = num_len(stats->st_nlink);
	new->stats = stats;
	new->flags = flags;
	new->path = path;
	new->sub = NULL;
	new->next = NULL;
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
