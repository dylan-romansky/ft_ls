/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gen_struct.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dromansk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 16:19:14 by dromansk          #+#    #+#             */
/*   Updated: 2019/02/07 16:36:00 by dromansk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

int		new_direct(t_direct **d)
{
	t_direct	*new;

	if (!(new = (t_direct *)malloc(sizeof(t_direct))))
		return (0);
	new->stream = NULL;
	new->direct = NULL;
	*d = new;
	return (1);
}
