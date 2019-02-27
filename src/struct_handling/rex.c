/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rex.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dromansk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 00:08:10 by dromansk          #+#    #+#             */
/*   Updated: 2019/02/26 00:08:13 by dromansk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

t_rex	*new_rex(t_direct *d)
{
	t_rex	*new;

	new = (t_rex *)malloc(sizeof(t_rex));
	new->dir = d;
	new->next = NULL;
	return (new);
}

void	add_rex(t_direct *d, t_rex **rec)
{
	t_rex	*curr;
	t_rex	*new;

	curr = *rec;
	if (!(curr->dir))
	{
		curr->dir = d;
		return ;
	}
	new = new_rex(d);
	while (curr->next)
		curr = curr->next;
	curr->next = new;
}

void	del_rex(t_rex *rec)
{
	t_rex	*del;

	del = rec;
	if (del && del->next)
		del_rex(del->next);
	if (del)
		free(del);
}
