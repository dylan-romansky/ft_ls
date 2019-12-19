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
#include "lsenums.h"

char	*suffix_join(char *size, char *units, int unit)
{
	char	*tmp;
	char	*res;

	tmp = ft_strndup(units + unit, 1);
	res = ft_strjoin(size, tmp);
	free(size);
	free(tmp);
	return (res);
}

char	*size_str(long size, short flags)
{
	double	perc;
	int		unit;
	char	*units;

	unit = 0;
	units = "BKMGTP";
	if (!(flags & h))
		return(ft_ltoa(size));
	perc = (double)size;
	while (units[unit] && size > 1024)
	{
		unit++;
		size /= 1024;
		perc /= (double)1024;
	}
	return(suffix_join(ft_ftoa(perc, 1), units, unit));
}

void	print_one(char *file, short flags)
{
	t_direct	*ffile;

	ffile = new_direct(file, "", flags);
	print_list(ffile);
	free(ffile);
}
