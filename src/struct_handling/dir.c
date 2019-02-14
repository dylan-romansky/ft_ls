/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dir.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dromansk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 16:19:14 by dromansk          #+#    #+#             */
/*   Updated: 2019/02/13 22:37:58 by dromansk         ###   ########.fr       */
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

void		fix_size_pad(t_direct **dir)
{
	t_direct		*d;
	int				size;

	d = *dir;
	size = d->size_pad;
	while (d->next)
	{
		if (d->next->size_pad > size)
		{
			size = d->next->size_pad;
			d->size_pad = size;
			fix_size_pad(dir);
		}
		d->size_pad = size;
		d = d->next;
	}
}

int			add_dir(t_direct **dir, struct dirent *ent)
{
	t_direct		*n;
	unsigned char	tmp;

	if (!ent)
		return (0);
	n = *dir;
	while (n->next)
		n = n->next;
	tmp = n->flags;
	n->next = new_direct(ent, n->path, tmp);
	return (1);
}

t_direct	*new_direct(struct dirent *direct, char *path, unsigned char flags)
{
	t_direct		*new;
	struct stat		*stats;
	char			*fpath;

	fpath = ft_strcmp(direct->d_name, ".") && ft_strcmp(direct->d_name, "..") ?
		ft_strjoin(path, direct->d_name) : ft_strdup(direct->d_name);
	stats = (struct stat *)malloc(sizeof(struct stat));
	lstat(fpath, stats);
	free(fpath);
	if (!(new = (t_direct *)malloc(sizeof(t_direct))))
		return (NULL);
	new->direct = direct;
	new->user = handle_uid(stats->st_uid);
	new->group = handle_gid(stats->st_gid);
	new->size = stats->st_size;
	new->size_pad = num_len(new->size);
	new->stats = stats;
//	printf("%s mode %d\nfifo %d\nchr %d\ndir %d\nblk %d\nreg %d\nlink %d\nsock %d\nwht %d\n", direct->d_name, S_IFMT & stats->st_mode, S_IFIFO, S_IFCHR, S_IFDIR, S_IFBLK, S_IFREG, S_IFLNK, S_IFSOCK, S_IFWHT);
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
	free(dir->stats);
	free(dir->group);
	free(dir->user);
	if (del->next)
		del_dir(del->next);
	free(del);
}
