/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstypestruct.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dromansk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 20:04:49 by dromansk          #+#    #+#             */
/*   Updated: 2019/02/14 20:28:25 by dromansk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LSTYPESTRUCT_H
# define LSTYPESTRUCT_H
# include "lstructs.h"

t_filetypes g_filetypes[] =
{
	{S_IFIFO, 'p'},
	{S_IFCHR, 'c'},
	{S_IFDIR, 'd'},
	{S_IFBLK, 'b'},
	{S_IFREG, '-'},
	{S_IFLNK, 'l'},
	{S_IFSOCK, 's'},
	{S_IFWHT, '-'},
	{S_ISUID, '-'},
	{S_ISGID, '-'},
	{S_ISVTX, '-'},
	{S_IRUSR, '-'},
	{S_IWUSR, '-'},
	{S_IXUSR, '-'}
};

/*
** add colour codes in third slot
*/
#endif
