/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dromansk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 15:59:22 by dromansk          #+#    #+#             */
/*   Updated: 2019/02/26 16:58:42 by dromansk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"
#include "lsenums.h"

int		errorprint(char *path, int errnum)
{
	ft_dprintf(2, "ft_ls: %s: %s\n", path, strerror(errnum));
	return (errnum);
}

int		flags_error(char e)
{
	ft_dprintf(2, "ft_ls: illegal option --%c\n", e);
	ft_dprintf(2, "usage: ft_ls [-AFGHRadfghlortu1] [file ...]\n");
	return (-1);
}

int		test_input(char *input, short flags)
{
	char		*fixed;
	struct stat	ltest;
	struct stat test;

	fixed = ft_strlen(input) ? ft_strdup(input) : ft_strdup("./");
	lstat(input, &ltest);
	stat(input, &test);
	free(fixed);
	if (errno)
	{
		errorprint(input, errno);
		errno = 0;
		return (1);
	}
	if (flags & H)
		return (0);
	if (flags & d || ((flags & l && is_type(ltest, S_IFLNK) &&
			(input[ft_strlen(input) - 1] != '/' || (*input == '\'' &&
			input[ft_strlen(input) - 2] != '/'))) || !is_type(test, S_IFDIR)))
		return (2);
	return (0);
}
