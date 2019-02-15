/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstructs.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dromansk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 14:40:41 by dromansk          #+#    #+#             */
/*   Updated: 2019/02/14 16:04:23 by dromansk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LSTRUCTS_H
# define LSTRUCTS_H
# include <dirent.h>

typedef struct s_direct	t_direct;
typedef struct s_ftypes	t_ftypes;

struct	s_direct
{
	char			*name;
	struct stat		*stats;
	unsigned char	flags;
	char			*path;
	char			*user;
	char			*group;
	long			size;
	long long		size_pad;
	t_direct		*sub;
	t_direct		*next;
};

struct	s_ftypes
{
	char	type;
	int		flag;
};

#endif
