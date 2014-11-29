/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_up.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acouliba <acouliba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/17 15:15:25 by acouliba          #+#    #+#             */
/*   Updated: 2014/11/29 18:51:41 by acouliba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_btree.h"
#include "libft.h"
#include "ft_ls.h"

void            ls_read(t_btree **tree, char *pathname)
{
	struct dirent *file;
	DIR     *rep;

	rep = opendir(pathname);
	if (rep != NULL)
	{
		if (!(check_slash(pathname)))
			pathname = ft_strjoin(pathname, "/");
		while((file = readdir(rep)) != NULL)
		{
			pathname = ft_strjoin(pathname, file->d_name);
			btree_insert_data(tree, file->d_name, file->d_type);
		}
		free(pathname);
		closedir(rep);
	}
	else
		print_error(pathname);
}

void			ls_read_time(t_time **tree, char *pathname)
{
	struct dirent *file;
	struct stat *stats_struct;
	DIR     *rep;
	int		stats;
	char			*filepathname;

	if ((stats_struct = (struct stat*)malloc(sizeof(struct stat))))
	{
		rep = opendir(pathname);
		if (rep != NULL)
		{
			if (!(check_slash(pathname)))
				pathname = ft_strjoin(pathname, "/");
			while((file = readdir(rep)) != NULL)
			{
				filepathname = ft_strjoin(pathname, file->d_name);
				stats = lstat(filepathname, stats_struct);
				if (stats != -1)
					btree_insert_data_time(tree, file->d_name, stats_struct->st_mtimespec.tv_sec, file->d_type);
				free(filepathname);
				filepathname = NULL;
			}
			closedir(rep);
		}
		else
			print_error(pathname);
		free(stats_struct);
	}
}

size_t          *ls_read_stat(t_lltree **tree, char *pathname, char *choice)
{
	struct dirent	*file;
	DIR				*rep;
	struct stat		*stats_struct;
	t_llstat		statsfile;
	int				stats;
	static size_t	keep_infos[5] = {0};
	char			*filepathname;

	if((rep = opendir(pathname)))
	{
		if ((stats_struct = (struct stat*)malloc(sizeof(struct stat))))
		{
			if (!(check_slash(pathname)))
				pathname = ft_strjoin(pathname, "/");
			while ((file = readdir(rep)))
			{
				statsfile.filetype = file->d_type;
				statsfile.filename = ft_strdup(file->d_name);
				filepathname = ft_strjoin(pathname, file->d_name);
				if (((stats = lstat(filepathname, stats_struct))) != -1)
				{
					takestats(stats_struct, &statsfile);
					test_sizeinfos(&statsfile, keep_infos, stats_struct->st_blocks, choice);
					if (!(choice[1]))
						ltree_insert_data(tree, statsfile);
					else if (choice[1])
						ltree_insert_data_time(tree, statsfile);	
				}
				free(filepathname);
				filepathname = NULL;
			}
			closedir(rep);
			free(stats_struct);
		}
	}
	else
		print_error(pathname);
	return (keep_infos);
}
