/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dromansk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 15:41:57 by dromansk          #+#    #+#             */
/*   Updated: 2019/02/07 20:27:21 by dromansk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

int		main(int ac, char **av)
{
	t_direct	*d;
	DIR			*s;
	char		*path;

	path = ac == 1 ? "./" : av[1];
	s = opendir(path);
	d = new_direct(readdir(s));
	while (add_dir(&d, readdir(s)));
	print_list(d);
	closedir(s);
	del_dir(d);
	return (0);
}
