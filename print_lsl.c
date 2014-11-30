/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_lsl.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallete <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/21 14:20:33 by avallete          #+#    #+#             */
/*   Updated: 2014/11/30 14:18:22 by avallete         ###   ########.fr       */
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
		file_pathname= ft_strjoin(pathname, "/");
	if (infos[6])
	{
		print_total(infos[5]);
		infos[5] = 0;
		infos[6] = 0;
	}
	if (((!(option)) && (stats->filename[0] != '.')) || option)
	{
		print_typefile(stats->filetype);
		print_rights(stats->accesright);
		print_hlink(stats->nbhlink, infos[0]);
		print_owner(stats->owner, infos[1]);
		print_group(stats->group, infos[2]);
		print_size(stats->size, infos[3]);
		print_time(stats->date, infos[4]);
		ft_putstr(stats->filename);
		file_pathname = ft_strjoin(file_pathname, stats->filename);
		if (stats->filetype == 10)
			print_linkpath(file_pathname, stats->size);
		ft_putchar('\n');
		if (file_pathname)
			free(file_pathname);
	}
}
