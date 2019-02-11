/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dromansk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 15:41:57 by dromansk          #+#    #+#             */
/*   Updated: 2019/02/08 16:06:05 by dromansk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

int		main(int ac, char **av)
{
	t_direct	*d;
	DIR			*s;
	char		**path;
	short		flags;

	flags = get_flags(av, ac);
	path = get_path(ac, av);
	s = opendir(*path);
	d = new_direct(readdir(s));
	while (add_dir(&d, readdir(s)));
	sort_dir(&d, flags);
	print_list(d, flags);
	closedir(s);
	del_dir(d);
	return (0);
}
