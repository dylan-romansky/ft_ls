/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstructs.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dromansk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 14:40:41 by dromansk          #+#    #+#             */
/*   Updated: 2019/02/21 14:57:46 by dromansk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LSTRUCTS_H
# define LSTRUCTS_H
# include <dirent.h>

typedef struct s_direct		t_direct;
typedef struct s_ftypes		t_ftypes;
typedef struct s_filetypes	t_filetypes;

struct	s_direct
{
	char		*name;
	struct stat	*stats;
	short		flags;
	char		*path;
	char		*user;
	char		*group;
	long		size;
	int			size_pad;
	int			link_pad;
	int			userlen;
	int			grouplen;
	t_direct	*sub;
	t_direct	*next;
};

struct	s_ftypes
{
	char	type;
	int		flag;
};

struct	s_filetypes
{
	int		type;
	char	c;
	char	*colour;
};

#endif
