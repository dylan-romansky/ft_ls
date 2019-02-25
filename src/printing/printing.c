/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dromansk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 18:52:04 by dromansk          #+#    #+#             */
/*   Updated: 2019/02/22 00:48:25 by dromansk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"
#include "lsenums.h"

void	print_time(struct stat *info)
{
	char			*time;

	time = ft_strsub(ctime(&(info->st_mtimespec.tv_sec)), 4, 12);
	ft_printf(" %s ", time);
	free(time);
}

void	print_perm(struct stat *info, int b)
{
	while (b)
	{
		b & info->st_mode ? ft_printf("r") : ft_printf("-");
		b >>= 1;
		b & info->st_mode ? ft_printf("w") : ft_printf("-");
		b >>= 1;
		if (b & info->st_mode || info->st_mode & S_ISUID ||
				info->st_mode & S_ISVTX)
		{
			if (!(b & info->st_mode))
				ft_printf("S");
			else if ((b == 64 && info->st_mode & S_ISUID)
				   	|| (b == 8 && info->st_mode & S_ISGID))
				ft_printf("s");
			else if (b == 1 && info->st_mode & S_ISVTX)
				b & info->st_mode ? ft_printf("t") : ft_printf("T");
			else
				ft_printf("x");
		}
		else
			ft_printf("-");
		b >>= 1;
	}
}

void	print_info(t_direct *d)
{
	int				b;

	b = 256;
	print_perm(d->stats, b);
	ft_printf("  %*d ", d->link_pad, d->stats->st_nlink);
	if (!(d->flags & g))
		d->user ? ft_printf("%-*s", d->userlen, d->user) : ft_printf("%*d", d->userlen, d->stats->st_uid);
	if (!(d->flags & g) && !(d->flags & o))
		ft_printf("  ");
	if (!(d->flags & o))
		d->group ? ft_printf("%-*s", d->grouplen, d->group) : ft_printf("%*d", d->grouplen, d->stats->st_gid);
	if (ft_strstr(d->path, "/dev"))
		print_maj_min(d);
	else
		ft_printf("  %*ld", d->size_pad, d->size);
	print_time(d->stats);
}

void	print_link(t_direct *d)
{
	char			link[PATH_MAX + 1];
	int				ret;
	char			*path;

	path = ft_strjoin(d->path, d->name);
	ret = readlink(path, link, PATH_MAX);
	link[ret] = '\0';
	ft_printf(" -> %s", link);
	free(path);
}

void	print_list(t_direct *d)
{
	t_rex	*recs;

	recs = NULL;
	if (!d)
		return ;
	if (d->flags & l || d->flags & g)
		get_blocks(d);
	if (d->flags & R)
		recs = new_rex(NULL);
	while (d)
	{
		print_type(d, 1);
		ft_putchar('\n');
		if (d->flags & R && !ft_strequ(d->name, ".") && !ft_strequ(d->name, "..") && is_type(*d->stats, S_IFDIR))
			add_rex(d, &recs);
		d = d->next;
	}
	check_recursion(&recs);
}
