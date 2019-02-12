/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_time.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dromansk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 20:16:38 by dromansk          #+#    #+#             */
/*   Updated: 2019/02/11 20:56:21 by dromansk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"
#include "lsenums.h"
#include "datestruct.h"

/*
** result is slow by exactly 16 hours. Figure out why
*/

void	get_hour(long time)
{
	int			i;

	i = 0;
	while (time > 3600)
	{
		time -= 3600;
		i++;
	}
	ft_printf("%02d:%02d ", i, time / 60);
}

void	get_day(long time)
{
	int			i;

	i = 0;
	while (time > 86400)
	{
		time -= 86400;
		i++;
	}
	ft_printf("%2d ", i);
	get_hour(time);
}

void	get_month(long time, int leap)
{
	int		i;

	i = 0;
	while (time > g_months[i].time)
	{
		time -= leap && i == 1 ? g_months[i].time + 86400 : g_months[i].time;
		i++;
		if (i == 12)
			i = 0;
	}
	ft_printf(" %s ", g_months[i].month);
	get_day(time);
}

void	print_time(struct stat *info)
{
	long			time;
	int				year;

	time = (long)info->st_mtimespec.tv_sec;
	year = 1970;
	while (time > 31536000)
	{
		time -= year % 4 ? 31536000 : 31622400;
		year++;
	}
	get_month(time, year % 4 ? 0 : 1);
}
