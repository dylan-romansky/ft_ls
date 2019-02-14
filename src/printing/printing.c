/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dromansk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 18:52:04 by dromansk          #+#    #+#             */
/*   Updated: 2019/02/13 21:42:07 by dromansk         ###   ########.fr       */
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
	if (is_type(*info, S_IFDIR))
		ft_printf("d");
	else if (is_type(*info, S_IFLNK))
		ft_printf("l");
	else
		ft_printf("-");
	while (b)
	{
		b & info->st_mode ? ft_printf("r") : ft_printf("-");
		b >>= 1;
		b & info->st_mode ? ft_printf("w") : ft_printf("-");
		b >>= 1;
		b & info->st_mode ? ft_printf("x") : ft_printf("-");
		b >>= 1;
	}
}

void	print_info(t_direct *d)
{
	int				b;

	b = 256;
	print_perm(d->stats, b);
	ft_printf("  %d", d->stats->st_nlink);
	if (!(d->flags & g))
		ft_printf(" %8s ", d->user);
	ft_printf(" %8s  %*ld", d->group, d->size_pad, d->size);
	print_time(d->stats);
}

void	print_link(t_direct *d)
{
	char			link[BUFF_SIZE + 1];
	int				ret;
	char			*path;

	path = ft_strjoin(d->path, d->direct->d_name);
	ret = readlink(path, link, BUFF_SIZE);
	link[ret] = '\0';
	ft_printf("%s -> %s\n", d->direct->d_name, link);
	free(path);
}

void	print_list(t_direct *d)
{
	if (d->flags & l || d->flags & g)
		get_blocks(d);
	while (d)
	{
		if (*(d->direct->d_name) == '.' && !(d->flags & a))
			d = d->next;
		else
		{
			if (d->flags & l || d->flags & g)
				print_info(d);
			if (is_type(*(d->stats), S_IFLNK) && (d->flags & g
						|| d->flags & l))
				print_link(d);
			else
				ft_printf("%s\n", d->direct->d_name);
			d = d->next;
		}
	}
}
