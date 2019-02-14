/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dromansk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 15:24:32 by dromansk          #+#    #+#             */
/*   Updated: 2019/02/13 15:27:34 by dromansk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

void	dir_swap(t_direct **current)
{
	t_direct	*tmp;

	tmp = (*current)->next->next;
	(*current)->next->next = (*current);
	(*current)->next = tmp;
}
