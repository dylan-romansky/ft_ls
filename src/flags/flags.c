/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dromansk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 15:10:24 by dromansk          #+#    #+#             */
/*   Updated: 2019/02/12 14:07:10 by dromansk         ###   ########.fr       */
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
			while (i <= 5 && g_ftypes[i].type != *s)
				i++;
			if (i <= 5)
			{
				f |= g_ftypes[i].flag;
				s++;
				i = 0;
			}
		}
	}
	return (f);
}

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
	return (s2);
}

char	**get_path(int size, char **input)
{
	int		i;
	char	**paths;

	i = 0;
	paths = (char **)malloc(sizeof(char *));
	*paths = NULL;
	while (++i < size)
		if (!get_flag(input[i]))
			paths = array_join(paths, fix_input(input[i]));
	if (!*paths)
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
