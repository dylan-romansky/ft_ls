/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dromansk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 15:43:02 by dromansk          #+#    #+#             */
/*   Updated: 2019/03/05 14:59:23 by dromansk         ###   ########.fr       */
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
# ifdef __linux__
# include "linux.h"
# endif

/*
**other notes:
*/

int			ft_ls(char *path, short flags);
int			get_flags(char **s, int size);
char		**get_path(int size, char **input, short flags);
char		*fix_input(char *input);
void		del_path(char **path);

t_direct	*new_direct(char *name, char *path, short flags);
int			add_dir(t_direct **dir, struct dirent *ent);
void		del_dir(t_direct *dir);
int			num_len(long long n);
void		fix_size_pad(t_direct **dir, int size);
void		fix_userlen(t_direct **dir, int size);
void		fix_grouplen(t_direct **dir, int size);
void		fix_link_pad(t_direct **dir, int size);
t_rex		*new_rex(t_direct *d);
void		add_rex(t_direct *d, t_rex **rec);
void		del_rex(t_rex *rec);

void		check_recursion(t_rex **rec);

char		*handle_gid(gid_t st_gid);
char		*handle_uid(uid_t st_uid);

void		print_list(t_direct *dir);
void		print_type(t_direct *dir, int width);
void		print_link(t_direct *dir);
void		print_info(t_direct *dir);
void		print_one(char *file, short flags);
void		print_maj_min(t_direct *dir);
void		print_col(t_direct *dir);
int			print_char(t_direct *d, int i, int width);
void		get_blocks(t_direct *dir);
int			is_sorted(char *s1, char *s2);
void		sort_dir(t_direct **list);
void		f_sort(t_direct **list);
void		dir_swap(t_direct **current);
void		t_sort(t_direct **list);
void		u_sort(t_direct **list);
void		sorting(t_direct **d, short flags);

int			is_type(struct stat stats, unsigned int type);

int			test_input(char *input, short flags);
int			flags_error(char e);
int			errorprint(char *path, int errnum);

#endif
