/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstypestruct.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dromansk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 20:04:49 by dromansk          #+#    #+#             */
/*   Updated: 2019/02/26 18:22:44 by dromansk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LSTYPESTRUCT_H
# define LSTYPESTRUCT_H
# include "lstructs.h"

/*
**confirm whether an executable is always red regardless of who can execute
*/

t_filetypes g_filetypes[] =
{
	{S_IFIFO, 'p', "\033[0;33m", '|'},
	{S_IFDIR, 'd', "\033[0;34m", '/'},
	{S_IFBLK, 'b', "\033[0;34;46m", '\0'},
	{S_IFLNK, 'l', "\033[0;35m", '@'},
	{S_IFSOCK, 's', "\033[0;32m", '='},
	{S_IFREG, '-', "\033[0m", '\0'},
	{S_IFWHT, '-', "\033[0m", '%'},
	{S_IFCHR, 'c', "\033[0;34;43m", '\0'},
	{S_ISUID, '-', "\033[0;30;41m", '\0'},
	{S_ISGID, '-', "\033[0;30;46m", '\0'},
	{S_ISVTX, '-', "\033[0m", '\0'},
	{S_IRUSR, '-', "\033[0m", '\0'},
	{S_IWUSR, '-', "\033[0m", '\0'},
	{S_IXUSR, '-', "\033[0;31m", '*'},
	{S_IWOTH, '-', "\033[0;30;42m", '\0'},
	{S_IWOTH, '-', "\033[0;30;43m", '\0'}
};

/*
** normal shit is white -
** directories are blue -
** executable is red -
** symlink is magenta -
** socket is green -
** pipe (fifo) is brown -
** block (b) cyan and blue -
** character special file grey with yellow background (maybe blue brown)
** executable with set uid bit is black/red bg
** executable, set gid bit black/cyan bg
** directory writable to others sticky black/green bg
** directory writable no sticky black/brown bg
*/

#endif
