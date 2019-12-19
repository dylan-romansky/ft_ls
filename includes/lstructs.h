/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstructs.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dromansk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 14:40:41 by dromansk          #+#    #+#             */
/*   Updated: 2019/02/26 00:14:46 by dromansk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LSTRUCTS_H
# define LSTRUCTS_H
# include <dirent.h>

typedef struct s_direct		t_direct;
typedef struct s_ftypes		t_ftypes;
typedef struct s_filetypes	t_filetypes;
typedef struct s_rex		t_rex;

struct	s_direct
{
	char		*name;
	struct stat	*stats;
	short		flags;
	char		*path;
	char		*user;
	char		*group;
	char		*size;
	int			size_pad;
	int			link_pad;
	int			userlen;
	int			grouplen;
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
	char	c2;
};

struct	s_rex
{
	t_direct	*dir;
	t_rex		*next;
};

#endif
