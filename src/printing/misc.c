/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dromansk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 23:59:06 by dromansk          #+#    #+#             */
/*   Updated: 2019/02/25 23:59:09 by dromansk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

void	print_one(char *file, short flags)
{
	t_direct	*ffile;

	ffile = new_direct(file, "", flags);
	print_list(ffile);
	free(ffile);
}
