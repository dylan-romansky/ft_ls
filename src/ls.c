/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dromansk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 15:41:57 by dromansk          #+#    #+#             */
/*   Updated: 2019/02/25 23:37:50 by dromansk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"
#include "lsenums.h"

char	*fix_input(char *input)
{
	char	*s;

	s = ft_strdup(input);
	if (*s != '.' && *s != '/')
		s = swap_n_free(ft_strjoin("./", s), &s);
	if (s[ft_strlen(s) - 1] != '/')
		s = swap_n_free(ft_strjoin(s, "/"), &s);
	return (s);
}

void	check_recursion(t_rex **rec)
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
	if (rec && *rec)
		del_rex(*rec);
}

void	sorting(t_direct **d, short flags)
{
	if (!(flags & f))
	{
		if (flags & t)
			t_sort(d);
		if (flags & u)
			u_sort(d);
		else
			sort_dir(d);
	}
	else
		f_sort(d);
	fix_size_pad(d, (*d)->size_pad);
	fix_userlen(d, (*d)->userlen);
	fix_grouplen(d, (*d)->grouplen);
	fix_link_pad(d, (*d)->link_pad);
}

int		ft_ls(char *path, short flags)
{
	t_direct		*d;
	DIR				*s;
	struct dirent	*ent;

	d = NULL;
	s = opendir(path);
	while (!d && s && (ent = readdir(s)))
		d = new_direct(ent->d_name, path, flags);
	if (d)
	{
		while (d && add_dir(&d, readdir(s)))
			continue ;
		sorting(&d, flags);
	}
	closedir(s);
	if (d)
	{
		flags & 1 || flags & l || flags & o || d->flags & g ? print_list(d) : print_col(d);
		del_dir(d);
	}
	free(path);
	return (1);
}

int		main(int ac, char **av)
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
		ft_ls(fix_input(path[i]), flags);
		if (++i < size)
			ft_putchar('\n');
	}
	del_path(path);
	return (errno);
}
