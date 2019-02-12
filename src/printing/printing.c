/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dromansk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 18:52:04 by dromansk          #+#    #+#             */
/*   Updated: 2019/02/08 14:55:00 by dromansk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"
#include "lsenums.h"

void	print_info(struct dirent *file)
{
	struct stat	*info;
	int			b;

	info = (struct stat *)malloc(sizeof(struct stat));
	b = 256;
	stat(file->d_name, info);
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
	ft_printf(" ");
}

void	print_list(t_direct *d)
{
	if (*(d->direct->d_name) == '.' && !(d->flags & a))
		while (d->next && *(d->direct->d_name) == '.')
			d = d->next;
	while (d)
	{
		if (d->flags & l && d->flags & a)
			print_info(d->direct);
		ft_printf("%s", d->direct->d_name);
		ft_putchar('\n');
		d = d->next;
	}
}
