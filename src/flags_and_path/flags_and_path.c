/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_and_path.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dromansk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 15:10:24 by dromansk          #+#    #+#             */
/*   Updated: 2019/02/13 17:07:46 by dromansk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fstruct.h"
#include "ls.h"

static char		**array_join(char **sentence, char *word)
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

int		get_flag(char *s)
{
	int		i;
	int		f;

	i = 0;
	f = 0;
	if (*s++ == '-')
	{
		while (*s)
		{
			while (i <= 6 && g_ftypes[i].type != *s)
				i++;
			if (i <= 6)
				f |= g_ftypes[i].flag;
			else
			{
				ft_printf("ft_ls: illegal option --%c\n", *s);
				ft_printf("usage: ft_ls [-Rafglrt] [file ...]\n");
				return (255);
			}
			s++;
			i = 0;
		}
	}
	return (f);
}

char	**get_path(int size, char **input)
{
	int		i;
	char	**paths;
	int		error;

	i = 0;
	paths = (char **)malloc(sizeof(char *));
	*paths = NULL;
	while (++i < size)
	{
		error = 0;
		if (!get_flag(input[i]))
			error = test_input(input[i]);
		if (!error)
			paths = array_join(paths, ft_strdup(input[i]));
	}
	if (!*paths && !error)
		paths = array_join(paths, ft_strdup("./"));
	return (paths);
}

int		get_flags(char **s, int size)
{
	int		i;
	int		f;

	i = 0;
	f = 0;
	while (i < size)
		f |= get_flag(s[i++]);
	return (f);
}
