/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recursive_stat.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acouliba <acouliba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/28 16:48:17 by acouliba          #+#    #+#             */
/*   Updated: 2014/11/29 15:48:00 by acouliba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "libft.h"
#include "test_btree.h"

void			ls_grep_dir_stat(char *argv, t_lltree **tree, char *options)
{
	t_lltree *root;
    char *pathname;

	if (*tree)
	{
		root = *tree;
		pathname = ft_strjoin(argv, "/");
		pathname = ft_strjoin(pathname, root->stats.filename);
		if (!(options[3]))
		{
			if (root->left)
				ls_grep_dir_stat(argv, &root->left, options);
			if (root->stats.filetype == 4 && ft_strcmp("..", root->stats.filename) != 0 && ft_strcmp(".", root->stats.filename) != 0)
				ls_read_rec_stat(pathname, options);
			if (root->right)
				ls_grep_dir_stat(argv, &root->right, options);
		}
		else
		{
			if (root->right)
				ls_grep_dir_stat(argv, &root->right, options);
			if (root->stats.filetype == 4 && ft_strcmp("..", root->stats.filename) != 0 && ft_strcmp(".", root->stats.filename) != 0)
				ls_read_rec_stat(pathname, options);
			if (root->left)
				ls_grep_dir_stat(argv, &root->left, options);
		}
	}
}

void            ls_read_rec_stat(char *pathname, char *choice)
{
    struct dirent *file;
    DIR     *rep;

	ft_putchar('\n');
    ft_putstr(pathname);
    ft_putendl(":");
    pathname = ft_strjoin(pathname, "/");
    if((rep = opendir(pathname)) != NULL)
    {
		show_dir_stat(pathname, choice);
		while ((file = readdir(rep)) != NULL )
		{
            if (file->d_type == 4 && ft_strcmp(".", file->d_name) != 0 && ft_strcmp("..", file->d_name) != 0)
				ls_read_rec_stat(ft_strjoin(pathname, file->d_name), choice);
		}
        closedir(rep);
    }
    else
        print_error(pathname);
    free(pathname);
}

void          show_dir_stat(char *pathname, char *choice)
{
    struct dirent   *file;
    DIR             *rep;
    struct stat     *stats_struct;
    t_llstat        statsfile;
    int             stats;
    static size_t   keep_infos[5] = {0};
    char            *filepathname;
	t_lltree		*tree;

	tree = NULL;
    if((rep = opendir(pathname)))
    {
        if ((stats_struct = (struct stat*)malloc(sizeof(struct stat))))
        {
            pathname = ft_strjoin(pathname, "/");
            while ((file = readdir(rep)))
            {
                statsfile.filetype = file->d_type;
                statsfile.filename = ft_strdup(file->d_name);
                filepathname = ft_strjoin(pathname, file->d_name);
				stats = lstat(filepathname, stats_struct);
                if (stats != -1)
                {
                    takestats(stats_struct, &statsfile);
                    test_sizeinfos(&statsfile, keep_infos, stats_struct->st_blocks, choice);
                    if (!(choice[1]))
                        ltree_insert_data(&tree, statsfile);
                    else if (choice[1])
                        ltree_insert_data_time(&tree, statsfile);
                }
                free(filepathname);
                filepathname = NULL;
            }
			free(pathname);
			pathname = NULL;
			ltree_print(tree, keep_infos, choice);

			free_tree_stat(tree);
			closedir(rep);
            free(stats_struct);
        }

    }
    else
        print_error(pathname);
}
