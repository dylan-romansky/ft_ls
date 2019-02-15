/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_and_path.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dromansk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 15:10:24 by dromansk          #+#    #+#             */
/*   Updated: 2019/02/14 16:24:53 by dromansk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fstruct.h"
#include "ls.h"

static char	**array_join(char **sentence, char *word)
{
	char	**old;
	char	**new;
	int		i;

	old = sentence;
	new = NULL;
	i = 0;
	while (old[i])
		i++;
	if ((new = (char **)malloc(sizeof(char *) * (i + 2))))
	{
		i = -1;
		while (old[++i])
			new[i] = old[i];
		new[i++] = word;
		new[i] = NULL;
	}
	free(sentence);
	return (new);
}

int			get_one(int f)
{
	if (f & l)
		f -= l;
	if (f & g)
		f -= g;
	return (f);
}

int			get_flag(char *s)
{
	int		i;
	int		f;

	i = 0;
	f = 0;
	if (*s++ == '-')
	{
		while (*s)
		{
			if (*s == '1')
				f = get_one(f);
			while (i <= 7 && g_ftypes[i].type != *s)
				i++;
			if (i <= 7)
				f |= g_ftypes[i].flag;
			else
				return (flags_error(*s));
			s++;
			i = 0;
		}
	}
	return (f);
}

char		**get_path(int size, char **input, unsigned char flags)
{
	int		i;
	char	**paths;
	int		error;

	i = 1;
	paths = (char **)malloc(sizeof(char *));
	*paths = NULL;
	error = 0;
	while (input[i] && *input[i] == '-')
		i++;
	while (i < size)
	{
		error = test_input(input[i]);
		if (!error)
			paths = array_join(paths, ft_strdup(input[i]));
		else if (error == 2)
			print_one(input[i], flags);
		i++;
	}
	if (!*paths && !error)
		paths = array_join(paths, ft_strdup("./"));
	return (paths);
}

int			get_flags(char **s, int size)
{
	int		i;
	int		f;

	i = 0;
	f = 0;
	while (++i < size)
	{
		if (*s[i] != '-')
			break ;
		f |= get_flag(s[i]);
	}
	return (f);
}
