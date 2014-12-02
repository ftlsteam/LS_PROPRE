/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_lsl.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallete <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/21 14:20:33 by avallete          #+#    #+#             */
/*   Updated: 2014/12/02 18:48:54 by avallete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "libft.h"
# include "test_btree.h"
# include "ft_ls.h"

/*
   void print_error(char *filename)
   {
   int err;

   err = errno;
   perror("ls: ");
   }
   */

void print_lsl(t_llstat *stats, size_t *infos, char option, char *pathname)
{
	char *file_pathname;

	file_pathname = NULL;
	if (!(check_slash(pathname)))
		file_pathname = ft_strjoin(pathname, "/");
	else
		file_pathname = pathname;
	if (((!(option)) && (stats->filename[0] != '.')) || option)
	{
		if (infos[6])
		{
			print_total(infos[5]);
			infos[6] = 0;
		}
		infos[5] = 0;
		print_typefile(stats->filetype);
		print_rights(stats->accesright);
		print_hlink(stats->nbhlink, infos[0]);
		if (stats->owner)
			print_owner(stats->owner, infos[1]);
		if (stats->group)
			print_group(stats->group, infos[2]);
		if (stats->filetype != 2 && stats->filetype != 6)
			print_size(stats->size, infos[3]);
		//		else
		//			print_devices(stats->devices, infos[3]);
		print_time(stats->date, infos[4]);
		ft_putstr(stats->filename);
		file_pathname = ft_strjoin(file_pathname, stats->filename);
		if (stats->filetype == 10)
			print_linkpath(file_pathname, stats->size);
		ft_putchar('\n');
		if (file_pathname)
			free(file_pathname);
		if (stats->filename)
		{
			if (stats->filetype != 4)
			{
				free(stats->filename);
				stats->filename = NULL;
			}
			free(stats->owner);
			free(stats->group);
			stats->owner = NULL;
			stats->group = NULL;
		}
	}
}
