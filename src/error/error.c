/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dromansk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 15:59:22 by dromansk          #+#    #+#             */
/*   Updated: 2019/02/13 17:20:44 by dromansk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

void	errorprint(char *path, int errnum)
{
	ft_printf("ft_ls: %s: %s\n", path, strerror(errnum));
}

int		test_input(char *input)
{
	char	*fixed;
	DIR		*test;

	if (!input)
		return (0);
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
