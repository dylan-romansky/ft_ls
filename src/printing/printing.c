/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dromansk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 18:52:04 by dromansk          #+#    #+#             */
/*   Updated: 2019/02/11 20:17:12 by dromansk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"
#include "lsenums.h"

void	print_perm(struct stat *info, int b)
{
	is_type(*info, S_IFDIR) ? ft_printf("d") : ft_printf("-");
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
	struct stat		*info;
	int				b;

	info = (struct stat *)malloc(sizeof(struct stat));
	b = 256;
	stat(d->direct->d_name, info);
	print_perm(info, b);
	ft_printf("  %d", info->st_nlink);
	if (!(d->flags & g))
		ft_printf(" %8s", d->user);
	ft_printf(" %8s %8ld", d->group, d->size);
	print_time(info);
}

void	print_list(t_direct *d)
{
	while (d)
	{
		if (*(d->direct->d_name) == '.' && !(d->flags & a))
			d = d->next;
		else
		{
			if ((d->flags & l && d->flags & a) || d->flags & g)
				print_info(d);
			ft_printf("%s", d->direct->d_name);
			ft_putchar('\n');
			d = d->next;
		}
	}
}
