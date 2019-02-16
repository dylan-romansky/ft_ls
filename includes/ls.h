/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dromansk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 15:43:02 by dromansk          #+#    #+#             */
/*   Updated: 2019/02/15 20:59:32 by dromansk         ###   ########.fr       */
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
# define BUFF_SIZE 1024
# ifdef __linux__
# include "linux.h"
# endif

/*
** NAME_MAX and PATH_MAX for your maximum buffers
** bonus -u -d, colours
** u = time of last access, d makes directories plain files
*/
/*
 1.   If r, the file is readable; if -, it is not readable.

 2.   If w, the file is writable; if -, it is not writable.

 3.   The first of the following that applies:

            S     If in the owner permissions, the file is not exe-
                  cutable and set-user-ID mode is set.  If in the
                  group permissions, the file is not executable and
                  set-group-ID mode is set.

            s     If in the owner permissions, the file is exe-
                  cutable and set-user-ID mode is set.  If in the
                  group permissions, the file is executable and set-
                  group-ID mode is set.

            x     The file is executable or the directory is search-
                  able.

            -     The file is neither readable, writable, exe-
                  cutable, nor set-user-ID nor set-group-ID mode,
                  nor sticky.  (See below.)

      These next two apply only to the third character in the last
      group (other permissions).

            T     The sticky bit is set (mode 1000), but not execute
                  or search permission.  (See chmod(1) or
                  sticky(8).)

            t     The sticky bit is set (mode 1000), and is search-
                  able or executable.  (See chmod(1) or sticky(8).)
*/

int			ft_ls(char *path, unsigned char flags);
int			get_flags(char **s, int size);
char		**get_path(int size, char **input, unsigned char flags);
char		*fix_input(char *input);
void		del_path(char **path);

t_direct	*new_direct(char *name, char *path, unsigned char flags);
int			add_dir(t_direct **dir, struct dirent *ent);
void		del_dir(t_direct *dir);
int			num_len(long long n);
void		fix_size_pad(t_direct **dir, int size);
void		fix_userlen(t_direct **dir, int size);
void		fix_grouplen(t_direct **dir, int size);
void		fix_link_pad(t_direct **dir, int size);

int			is_end(t_direct *dir);

char		*handle_gid(gid_t st_gid);
char		*handle_uid(uid_t st_uid);

void		print_list(t_direct *dir);
void		print_type(t_direct *dir);
void		print_link(t_direct *dir);
void		print_info(t_direct *dir);
void		print_one(char *file, unsigned char flags);
void		get_blocks(t_direct *dir);
void		sort_dir(t_direct **list);
void		f_sort(t_direct **list);
void		dir_swap(t_direct **current);
void		t_sort(t_direct **list);

int			is_type(struct stat stats, unsigned int type);

int			test_input(char *input);
int			flags_error(char e);

#endif
