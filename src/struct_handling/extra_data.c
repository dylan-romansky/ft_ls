/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dromansk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 21:41:16 by dromansk          #+#    #+#             */
/*   Updated: 2019/02/15 21:20:28 by dromansk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

char	*handle_gid(gid_t st_gid)
{
	struct group *id;

	id = getgrgid(st_gid);
	return (id ? ft_strdup(id->gr_name) : NULL);
}

char	*handle_uid(uid_t st_uid)
{
	struct passwd *id;

	id = getpwuid(st_uid);
	return (id ? ft_strdup(id->pw_name) : NULL);
}

void	fix_userlen(t_direct **dir, int size)
{
	t_direct		*d;

	d = *dir;
	while (d)
	{
		if (d->userlen > size)
		{
			fix_userlen(dir, d->userlen);
			return ;
		}
		d->userlen = size;
		d = d->next;
	}
}

void	fix_grouplen(t_direct **dir, int size)
{
	t_direct		*d;

	d = *dir;
	while (d)
	{
		if (d->grouplen > size)
		{
			fix_grouplen(dir, d->grouplen);
			return ;
		}
		d->grouplen = size;
		d = d->next;
	}
}

void	fix_link_pad(t_direct **dir, int size)
{
	t_direct		*d;

	d = *dir;
	while (d)
	{
		if (d->link_pad > size)
		{
			fix_link_pad(dir, d->link_pad);
			return ;
		}
		d->link_pad = size;
		d = d->next;
	}
}
