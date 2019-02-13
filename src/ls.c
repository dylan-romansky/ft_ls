/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dromansk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 15:41:57 by dromansk          #+#    #+#             */
/*   Updated: 2019/02/12 19:01:37 by dromansk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"
#include "lsenums.h"

char	*fix_input(char *input)
{
	char *s1;
	char *s2;

	s1 = ft_strdup(input);
	if (*input != '.' && *input != '/')
	{
		s2 = ft_strjoin("./", s1);
		free(s1);
		s1 = s2;
	}
	if (input[ft_strlen(input) - 1] != '/')
	{
		s2 = ft_strjoin(s1, "/");
		free (s1);
		s1 = s2;
	}
	return (s1);
}

int		ft_ls(char *path, unsigned char flags)
{
	DIR			*s;
	t_direct	*d;

	s = opendir(path);
	d = new_direct(readdir(s), path, flags);
	while (add_dir(&d, readdir(s)))
		continue ;
	flags & t ? t_sort(&d) : sort_dir(&d);
	print_list(d);
	closedir(s);
//	if (flags & R)
//		check_recursion(d);
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
		if ((flags & R || size > 1) && ft_strcmp(path[i], "./"))
			ft_printf("%s:\n", path[i]);
		ft_ls(fix_input(path[i++]), flags);
		if (i < size)
			ft_putchar('\n');
	}
	return (0);
}
