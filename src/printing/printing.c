/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dromansk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 18:52:04 by dromansk          #+#    #+#             */
/*   Updated: 2019/02/21 15:37:59 by dromansk         ###   ########.fr       */
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
		ft_printf("%-*s", d->userlen, d->user);
	if (!(d->flags & g) && !(d->flags & o))
		ft_printf("  ");
	if (!(d->flags & o))
		ft_printf("%-*s", d->grouplen, d->group);
	if (ft_strstr(d->path, "/dev"))
		print_maj_min(d);
	else
		ft_printf("  %*ld", d->size_pad, d->size);
	print_time(d->stats);
}

void	print_link(t_direct *d)
{
	char			link[BUFF_SIZE + 1];
	int				ret;
	char			*path;

	path = ft_strjoin(d->path, d->name);
	ret = readlink(path, link, BUFF_SIZE);
/*	if (ret < 0)
	{
		ft_putchar('\n');
		errorprint(path, errno);
		free(path);
		exit(EXIT_FAILURE);
	}*/
	link[ret] = '\0';
	ft_printf(" -> %s", link);
	free(path);
}

void	print_list(t_direct *d)
{
	if (d->flags & l || d->flags & g)
		get_blocks(d);
	while (d)
	{
		if (*(d->name) == '.' && !(d->flags & a))
			d = d->next;
		else
		{
			print_type(d);
			d = d->next;
		}
	}
}
