/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   blocks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dromansk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 18:43:51 by dromansk          #+#    #+#             */
/*   Updated: 2019/02/22 01:03:30 by dromansk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"
#include "lsenums.h"
#include "lstypestruct.h"

void	get_blocks(t_direct *dir)
{
	int			blocks;

	blocks = 0;
	while (dir)
	{
		while (dir->next && !(dir->flags & a) && *(dir->name) == '.')
			dir = dir->next;
		blocks += dir->stats->st_blocks;
		dir = dir->next;
	}
	ft_printf("total %d\n", blocks);
}

void	print_one(char *file, short flags)
{
	t_direct	*ffile;

	ffile = new_direct(file, "", flags);
	print_list(ffile);
	free(ffile);
}

void	print_name(t_direct *d, int i, int width)
{
	if (d->flags & G)
		ft_printf("%s%-*s{eoc}", g_filetypes[i].colour, width, d->name);
	else
		ft_printf("%-*s", width, d->name);
	if (((d->flags & l) || (d->flags & g)) && g_filetypes[i].c == 'l')
		print_link(d);
}

void	print_type(t_direct *d, int width)
{
	int			i;

	i = 0;
	while (i <= 15 && !is_type(*d->stats, g_filetypes[i].type))
		i++;
	if (i == 4 && d->stats->st_mode & S_IXUSR)
		i = 13;
	if (d->flags & l || d->flags & g)
	{
		ft_printf("%c", g_filetypes[i].c);
		print_info(d);
	}
	if (i == 2 && d->stats->st_mode & S_IWOTH)
		i = d->stats->st_mode & S_ISVTX ? 14 : 15;
	print_name(d, i, width);
}

void	print_maj_min(t_direct *d)
{
	if (is_type(*d->stats, S_IFCHR) || is_type(*d->stats, S_IFBLK))
		ft_printf("  %3d, %3d", major(d->stats->st_rdev), minor(d->stats->st_rdev));
	else
		ft_printf("  %8ld", d->size);
}
