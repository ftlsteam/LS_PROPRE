/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_stat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallete <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/25 17:06:49 by avallete          #+#    #+#             */
/*   Updated: 2014/11/30 16:07:07 by avallete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char			ft_oldtime(int32_t timefile)
{
	time_t currenttime = NULL;

	time(&currenttime);
	if ((timefile - currenttime) <= -15811200 || (currenttime - timefile) <= -3600)
		return (1);
	return (0);	
}

void			test_sizeinfos(t_llstat *stats, size_t *infos, size_t block, char *choice)
{
	if ((((!(choice[2]))) && stats->filename[0] != '.') || (choice[2]))
	{
		if (ft_nbrlen(stats->nbhlink) > infos[0])
			infos[0] = ft_nbrlen(stats->nbhlink);
		if (stats->owner)
		{
			if (ft_strlen(stats->owner) > infos[1])
				infos[1] = ft_strlen(stats->owner);
		}
		if (stats->group)
		{
			if (ft_strlen(stats->group) > infos[2])
				infos[2] = ft_strlen(stats->group);
		}
		if (ft_nbrlen(stats->size) > infos[3])
			infos[3] = ft_nbrlen(stats->size);
		if (ft_oldtime(stats->date))
			infos[4] = 1;
		infos[5] += block;
		infos[6] = 1;
	}
}

void			takestats(struct stat *statsbase, t_llstat *statstree)
{
	statstree->accesright = statsbase->st_mode;
	statstree->nbhlink = statsbase->st_nlink;
	if (!(getpwuid(statsbase->st_uid)))
		statstree->owner = ft_itoa(statsbase->st_uid);
	else
		statstree->owner = (getpwuid(statsbase->st_uid)->pw_name);
	if (!(getgrgid(statsbase->st_gid)))
		statstree->group = ft_itoa(statsbase->st_gid);
	else
		statstree->group = (getgrgid(statsbase->st_gid)->gr_name);
	statstree->size = statsbase->st_size;
	statstree->date = statsbase->st_mtimespec.tv_sec;
}

