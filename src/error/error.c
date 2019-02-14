/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dromansk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 15:59:22 by dromansk          #+#    #+#             */
/*   Updated: 2019/02/13 21:46:37 by dromansk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

void	errorprint(char *path, int errnum)
{
	ft_dprintf(2, "ft_ls: %s: %s\n", path, strerror(errnum));
}

int		flags_error(char e)
{
	ft_dprintf(2, "ft_ls: illegal option --%c\n", e);
	ft_dprintf(2, "usage: ft_ls [-Rafglrt1] [file ...]\n");
	return (255);
}

int		test_input(char *input)
{
	char	*fixed;
	DIR		*test;

	fixed = fix_input(input);
	test = opendir(fixed);
	free(fixed);
	if (errno)
	{
		errorprint(input, errno);
		errno = 0;
		return (1);
	}
	closedir(test);
	return (0);
}
