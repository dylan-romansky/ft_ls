/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dromansk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 15:24:32 by dromansk          #+#    #+#             */
/*   Updated: 2019/12/19 18:34:15 by dromansk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"
#include "lsenums.h"

void		dir_swap(t_direct **current)
{
	t_direct	*tmp;

	tmp = (*current)->next->next;
	(*current)->next->next = (*current);
	(*current)->next = tmp;
}

int			is_sorted(char *s1, char *s2)
{
	while (*s1 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return (*s1 <= *s2 ? r : 0);
}
