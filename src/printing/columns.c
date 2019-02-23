/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   columns.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dromansk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 22:21:24 by dromansk          #+#    #+#             */
/*   Updated: 2019/02/22 18:55:35 by dromansk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

/*
** not perfect but Imma do either 30 width or longest name plus 2
*/

void		print_every_i(t_direct *d, int i, int len)
{
	t_direct		*curr;
	int				count;

	count = 1;
	print_type(d, len);
	curr = d->next;
	while (curr)
	{
		if (!(count % i))
			print_type(curr, len);
		curr = curr->next;
		count++;
	}
}

void		print_cols(t_direct *d, int cols, int size, int len)
{
	int				counter;
	int				i;

	counter = 1;
	i = size / cols;
	if (size % cols)
		i++;
	while (counter <= i)
	{
		print_every_i(d, i, len);
		d = d->next;
		counter++;
		ft_putchar('\n');
	}
}

void		column_count(t_direct *d, int len, int count)
{
	struct winsize	ws;
	int				size;
	int				cols;
	
	cols = 1;
	ioctl(1, TIOCGWINSZ, &ws);
	size = ws.ws_col;
	if (size > len)
	{
		cols = size / len;
	}
	print_cols(d, cols, count, len);
}

void		print_col(t_direct *d)
{
	t_direct	*start;
	int			len;
	int			cmp;
	int			count;
	len = 16;
	count = 0;
	start = d;
	while (d)
	{
		count++;
		cmp = ft_strlen(d->name);
		len = cmp > 16 ? 30 : len;
		len = cmp > len ? cmp : len;
		d = d->next;
	}
	column_count(start, len, count);
}
