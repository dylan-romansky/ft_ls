/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dromansk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 18:52:04 by dromansk          #+#    #+#             */
/*   Updated: 2019/02/07 20:36:54 by dromansk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

void		print_file(t_file *f)
{
	while (f)
	{
		ft_printf("file: %s\n", f->file->d_name);
		f = f->next;
	}
}

void		print_list(t_direct *d)
{
	if (d->file)
		print_file(d->file);
	while (d)
	{
		ft_printf("directory: %s\n", d->direct->d_name);
		d = d->next;
	}
}
