/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dromansk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 15:41:57 by dromansk          #+#    #+#             */
/*   Updated: 2019/02/26 19:58:24 by dromansk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"
#include "lsenums.h"

char		*fix_input(char *input)
{
	char	*s;

	s = ft_strdup(input);
	if (*s != '.' && *s != '/')
		s = swap_n_free(ft_strjoin("./", s), &s);
	if (s[ft_strlen(s) - 1] != '/')
		s = swap_n_free(ft_strjoin(s, "/"), &s);
	return (s);
}

void		check_recursion(t_rex **rec)
{
	char		*fpath;
	t_rex		*curr;
	t_direct	*dir;

	curr = *rec;
	if (!curr || !curr->dir)
		return ;
	while (curr && curr->dir)
	{
		dir = curr->dir;
		fpath = ft_strjoin(dir->path, dir->name);
		ft_printf("\n%s\n", fpath);
		ft_ls(fix_input(fpath), dir->flags);
		free(fpath);
		curr = curr->next;
	}
}

t_direct	*read_dirs(char *path, DIR *s, short flags)
{
	struct dirent	*ent;
	t_direct		*d;

	ent = NULL;
	d = NULL;
	while (!d && s && (ent = readdir(s)))
		d = new_direct(ent->d_name, path, flags);
	if (d)
	{
		while (d && add_dir(&d, readdir(s)))
			continue ;
		sorting(&d, flags);
	}
	return (d);
}

int			ft_ls(char *path, short flags)
{
	t_direct		*d;
	DIR				*s;

	if (!(s = opendir(path)) && errno)
	{
		free(path);
		return (errno);
	}
	d = read_dirs(path, s, flags);
	closedir(s);
	if (d)
	{
		flags & 1 || flags & l || flags & o || d->flags & g
			? print_list(d) : print_col(d);
		del_dir(d);
	}
	free(path);
	return (0);
}

int			main(int ac, char **av)
{
	char	**path;
	short	flags;
	int		size;
	int		i;

	errno = 0;
	flags = get_flags(av, ac);
	if (flags == -1)
		return (1);
	path = get_path(ac, av, flags);
	size = 0;
	i = 0;
	while (path[size])
		size++;
	while (path[i])
	{
		if (size > 1 && ft_strcmp(path[i], "./"))
			ft_printf("%s:\n", path[i]);
		if (ft_ls(fix_input(path[i]), flags))
			errorprint(path[i], errno);
		if (++i < size)
			ft_putchar('\n');
	}
	del_path(path);
	return (errno);
}
