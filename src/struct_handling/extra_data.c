/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dromansk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 21:41:16 by dromansk          #+#    #+#             */
/*   Updated: 2019/02/08 14:54:44 by dromansk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

char	*handle_gid(gid_t st_gid)
{
	struct group *id;
	
	id = getgrgid(st_gid);
	return (ft_strdup(id->gr_name));
}

char	*handle_uid(uid_t st_uid)
{
	struct passwd *id;

	id = getpwuid(st_uid);
	return (ft_strdup(id->pw_name));
}
