/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dromansk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 15:41:57 by dromansk          #+#    #+#             */
/*   Updated: 2019/02/12 19:15:49 by dromansk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"
#include "lsenums.h"

/*
** issue is after t_direct creation, some time before recursion check
*/

char	*fix_input(char *input)
{
	char		*s;

	s = ft_strdup(input);
	if (*input != '.' && *input != '/')
		s = swap_n_free(ft_strjoin("./", s), &s);
	if (input[ft_strlen(input) - 1] != '/')
		s = swap_n_free(ft_strjoin(s, "/"), &s);
	return (s);
}

int		is_end(t_direct *dir)
{
	while (dir)
	{
		if (is_type(*(dir->stats), S_IFDIR))
			return (0);
		dir = dir->next;
	}
	return (1);
}

void	check_recursion(t_direct *dir)
{
	char		*fpath;

	while (dir)
	{
		if (!(dir->flags & a) && *dir->direct->d_name == '.')
			dir = dir->next;
		else if (is_type(*(dir->stats), S_IFDIR))
		{
			printf("\n%s %d\n", dir->direct->d_name, is_type(*(dir->stats), S_IFDIR));
			fpath = ft_strjoin(dir->path, dir->direct->d_name);
			ft_printf("\n%s\n", fpath);
			ft_ls(fix_input(fpath), dir->flags);
			free(fpath);
			dir = dir->next;
		}
		else
			dir = dir->next;
	}
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
	if (flags & R)
		check_recursion(d);
	del_dir(d);
	free(path);
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
	del_path(path);
	return (0);
}
