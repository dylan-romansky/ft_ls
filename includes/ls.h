/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dromansk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 15:43:02 by dromansk          #+#    #+#             */
/*   Updated: 2019/02/07 20:32:26 by dromansk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LS_H
# define LS_H
# include "printf.h"
# include "lstructs.h"
# include "libft.h"
# include <dirent.h>
# include <errno.h>
# include <grp.h>
# include <pwd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <time.h>
# include <unistd.h>
# include <sys/xattr.h>
# include <sys/acl.h>
# include <sys/time.h>
# include <glob.h>
# include <sys/ioctl.h>
# include <fcntl.h>

/*
** handle flags -l -R -a -r -t
** bonus -u -f -g -d, colours
*/

t_direct	*new_direct(struct dirent *direct);
int			add_dir(t_direct **dir, struct dirent *ent);
void		del_dir(t_direct *dir);

t_file		*new_file(struct dirent *file);
int			add_file(t_direct **file, struct dirent *ent);
void		del_file(t_file *file);

void		print_list(t_direct *dir);

int			is_type(struct stat stats, int type);

#endif
