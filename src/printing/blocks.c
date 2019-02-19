/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   blocks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dromansk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 18:43:51 by dromansk          #+#    #+#             */
/*   Updated: 2019/02/18 21:28:51 by dromansk         ###   ########.fr       */
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

void	print_one(char *file, unsigned char flags)
{
	t_direct	*ffile;

	ffile = new_direct(file, "", flags);
	print_list(ffile);
	free(ffile);
}

void	print_name(t_direct *d, int i)
{
	if (d->flags & G)
		ft_printf("%s%s{eoc}", g_filetypes[i].colour, d->name);
	else
		ft_printf("%s", d->name);
	if (((d->flags & l) || (d->flags & g)) && g_filetypes[i].c == 'l')
		print_link(d);
	ft_putchar('\n');
}

void	print_type(t_direct *d)
{
	int			i;

	i = 0;
	while (i <= 13 && !is_type(*d->stats, g_filetypes[i].type))
		i++;
	if (i == 4 && d->stats->st_mode & S_IXUSR)
		i = 13;
	if (d->flags & l || d->flags & g)
	{
		ft_printf("%c", g_filetypes[i].c);
		print_info(d);
	}
	print_name(d, i);
}
