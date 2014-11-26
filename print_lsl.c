/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_lsl.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallete <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/21 14:20:33 by avallete          #+#    #+#             */
/*   Updated: 2014/11/25 17:13:11 by avallete         ###   ########.fr       */
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

void print_lsl(t_llstat *stats, size_t *infos, char option)
{
	if (infos[5])
	{
		print_total(infos[5]);
		infos[5] = 0;
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
		if (stats->filetype == 10)
			print_linkpath(stats->filename, stats->size);
		ft_putchar('\n');
	}
}
