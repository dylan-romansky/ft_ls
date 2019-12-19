/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   columns.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dromansk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 22:21:24 by dromansk          #+#    #+#             */
/*   Updated: 2019/02/26 00:32:12 by dromansk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"
#include "lsenums.h"

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

int			len_check_lmao(int len, int cmp)
{
	if (len <= cmp)
		len = cmp + 2;
	return (len);
}

void		print_col(t_direct *d)
{
	t_direct	*start;
	int			len;
	int			count;
	t_rex		*recs;

	if (!d)
		return ;
	len = 0;
	count = 0;
	start = d;
	recs = NULL;
	if (d->flags & R)
		recs = new_rex(NULL);
	while (d)
	{
		count++;
		len = len_check_lmao(len, ft_strlen(d->name));
		if (d->flags & R && !ft_strequ(d->name, ".") &&
				!ft_strequ(d->name, "..") && is_type(*d->stats, S_IFDIR))
			add_rex(d, &recs);
		d = d->next;
	}
	column_count(start, len, count);
	check_recursion(&recs);
	del_rex(recs);
}
