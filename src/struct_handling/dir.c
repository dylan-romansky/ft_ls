/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dir.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dromansk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 16:19:14 by dromansk          #+#    #+#             */
/*   Updated: 2019/02/13 16:39:01 by dromansk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"
#include "lsenums.h"

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
	stat(fpath, stats);
	free(fpath);
	if (!(new = (t_direct *)malloc(sizeof(t_direct))))
		return (NULL);
	new->direct = direct;
	new->user = handle_uid(stats->st_uid);
	new->group = handle_gid(stats->st_gid);
	new->size = stats->st_size;
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
	free(dir->stats);
	free(dir->group);
	free(dir->user);
	if (del->next)
		del_dir(del->next);
	free(del);
}
