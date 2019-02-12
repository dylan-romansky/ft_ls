/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dromansk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 18:52:04 by dromansk          #+#    #+#             */
/*   Updated: 2019/02/11 18:44:04 by dromansk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"
#include "lsenums.h"

void	print_info(t_direct *d)
{
	struct stat		*info;
	int				b;

	info = (struct stat *)malloc(sizeof(struct stat));
	b = 256;
	stat(d->direct->d_name, info);
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
	ft_printf(" %d %8s %8s %9ld %s ", info->st_mode, d->user, d->group, d->size, "coming soon");
}

void	print_list(t_direct *d)
{
	while (d)
	{
		if (*(d->direct->d_name) == '.' && !(d->flags & a))
			d = d->next;
		else
		{
			if (d->flags & l && d->flags & a)
				print_info(d);
			ft_printf("%s", d->direct->d_name);
			ft_putchar('\n');
			d = d->next;
		}
	}
}
