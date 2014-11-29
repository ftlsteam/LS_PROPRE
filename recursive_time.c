/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recursive_time.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acouliba <acouliba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/26 16:51:32 by acouliba          #+#    #+#             */
/*   Updated: 2014/11/29 15:11:35 by acouliba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "libft.h"
#include "test_btree.h"

void            ls_grep_dir_time(char *argv, t_time **tree, char *options)
{
    t_time *root;
    char *pathname;

	if (*tree)
	{
		root = *tree;
		pathname = ft_strjoin(argv, "/");
		pathname = ft_strjoin(pathname, root->content);
		if (!(options[3]))
		{
			if (root->left)
				ls_grep_dir_time(argv, &root->left, options);
			if (root->file_type == 4 && ft_strcmp("..", root->content) != 0 && ft_strcmp(".", root->content) != 0)
				ls_read_rec_time(pathname, options);
			if (root->right)
				ls_grep_dir_time(argv, &root->right, options);
		}
		else
		{
			if (root->right)
				ls_grep_dir_time(argv, &root->right, options);
			if (root->file_type == 4 && ft_strcmp("..", root->content) != 0 && ft_strcmp(".", root->content) != 0)
				ls_read_rec_time(pathname, options);
			if (root->left)
				ls_grep_dir_time(argv, &root->left, options);
		}
	}
}

void            ls_read_rec_time(char *pathname, char *choice)
{
    struct dirent *file;
    DIR     *rep;

    ft_putchar('\n');
	ft_putstr(pathname);
	ft_putendl(":");
    pathname = ft_strjoin(pathname, "/");
    if((rep = opendir(pathname)) != NULL)
    {
		show_dir_time(pathname, choice);
		while ((file = readdir(rep)) != NULL )
        {
            if (file->d_type == 4 && ft_strcmp(".", file->d_name) != 0 && ft_strcmp("..", file->d_name) != 0)
                ls_read_rec_time(ft_strjoin(pathname, file->d_name), choice);
		}
		closedir(rep);
    }
	else
		print_error(pathname);
	free(pathname);
}

void        show_dir_time(char *pathname, char *choice)
{
    struct dirent *file;
    t_time     *tree;
    struct stat *stats_struct;
    DIR     *rep;
    int     stats;
	char	*filepathname;

	tree = NULL;
    if ((stats_struct = (struct stat*)malloc(sizeof(struct stat))))
    {
        if ((rep = opendir(pathname)))
		{
			while((file = readdir(rep)))
			{
				filepathname = ft_strjoin(pathname, file->d_name);
				stats = lstat(filepathname, stats_struct);
				if (stats != -1)
					btree_insert_data_time(&tree, file->d_name, stats_struct->st_mtimespec.tv_sec, file->d_type);
			}
			btree_print_time(tree, choice);
		}
		free(filepathname);
		free(stats_struct);
		free_tree_time(tree);
		closedir(rep);
    }
}
