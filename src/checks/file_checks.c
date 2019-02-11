/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_checks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dromansk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 20:11:38 by dromansk          #+#    #+#             */
/*   Updated: 2019/02/07 20:24:37 by dromansk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

int		is_type(struct stat stats, unsigned int type)
{
	if ((stats.st_mode & S_IFMT) == type)
		return (1);
	return (0);
}
