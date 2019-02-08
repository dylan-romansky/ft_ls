/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstructs.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dromansk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 14:40:41 by dromansk          #+#    #+#             */
/*   Updated: 2019/02/07 16:05:36 by dromansk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LSTRUCTS_H
# define LSTRUCTS_H
# include <dirent.h>

typedef struct	s_direct;

struct	s_direct
{
	DIR				*stream;
	struct dirent	*direct;
}	t_direct;

#endif
