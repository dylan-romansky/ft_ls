/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   blocks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dromansk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 18:43:51 by dromansk          #+#    #+#             */
/*   Updated: 2019/02/26 18:19:19 by dromansk         ###   ########.fr       */
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

void	print_char(t_direct *d, int i)
{
	int			t;

	t = i;
	if (i == 3 && (d->flags & l || d->flags & g || d->flags & o))
	{
		if (is_type(*d->stats, S_IFDIR))
		{
			t = 1;
			print_link(d);
		}
	}
	ft_printf("%c", g_filetypes[t].c2);
	if (i == 3 && t != 1 && (d->flags & l || d->flags & g))
		print_link(d);
}

void	print_name(t_direct *d, int i, int width)
{
	int			len;

	if (d->flags & G)
		ft_printf("%s", g_filetypes[i].colour);
	ft_printf("%s", d->name);
	if (d->flags & G)
		ft_printf("{eoc}");
	len = ft_strlen(d->name);
	width = width > len ? width - len : 0;
	i = (i == 14 || i == 15) ? 1 : i;
	if (d->flags & F)
		print_char(d, i);
	else if (((d->flags & l) || (d->flags & g)) && g_filetypes[i].c == 'l')
		print_link(d);
	while (width--)
		ft_putchar(' ');
}

void	print_type(t_direct *d, int width)
{
	int			i;

	i = 0;
	while (i < 15 && !is_type(*d->stats, g_filetypes[i].type))
		i++;
	if (i == 5 && d->stats->st_mode & S_IXUSR)
		i = 13;
	if (d->flags & l || d->flags & g)
	{
		ft_printf("%c", g_filetypes[i].c);
		print_info(d);
	}
	if (i == 1 && d->stats->st_mode & S_IWOTH)
		i = d->stats->st_mode & S_ISVTX ? 14 : 15;
	print_name(d, i, width);
}

void	print_maj_min(t_direct *d)
{
	if (is_type(*d->stats, S_IFCHR) || is_type(*d->stats, S_IFBLK))
		ft_printf("  %3d, %3d", major(d->stats->st_rdev),
				minor(d->stats->st_rdev));
	else
		ft_printf("  %8ld", d->size);
}
