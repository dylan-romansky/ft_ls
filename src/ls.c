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

int		ft_ls(char *path, unsigned char flags)
{
	DIR			*s;
	t_direct	*d;

	s = opendir(path);
	d = new_direct(readdir(s), path, flags);
	while (add_dir(&d, readdir(s)));
	sort_dir(&d);
	print_list(d);
	closedir(s);
	del_dir(d);
	return (1);
}

int		main(int ac, char **av)
{
	char		**path;
	short		flags;
	int			size;
	int			i;

	flags = get_flags(av, ac);
	path = get_path(ac, av);
	size = 0;
	i = 0;
	while (path[size])
		size++;
	while (path[i])
	{
		if (size > 1)
			ft_printf("%s:\n", path[i]);
		ft_ls(path[i++], flags);
		if (size > 1)
			ft_putchar('\n');
	}
	return (0);
}
