/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recursive_v2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acouliba <acouliba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/24 19:01:00 by acouliba          #+#    #+#             */
/*   Updated: 2014/11/26 15:42:05 by avallete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void			ls_grep_dir(t_btree **tree, char *options)
{
	t_btree *root;

	root = *tree;
	if (!(options[3]))
	{
		if (root->left)
			ls_grep_dir(&root->left, options);
		if (root->file_type == 4 && ft_strcmp("..", root->content) != 0)
			ls_read_rec(root->content, options);
		if (root->right)
			ls_grep_dir(&root->right, options);
	}
	else
	{
		if (root->right)
			ls_grep_dir(&root->right, options);
		if (root->file_type == 4 && ft_strcmp("..", root->content) != 0)
			ls_read_rec(root->content, options);
		if (root->left)
			ls_grep_dir(&root->left, options);
	}
	
}

void            ls_read_rec(char *pathname, char *choice)
{
	struct dirent *file;
	DIR     *rep;
	static  int i = 0;

	if (i != 0)
	{
		ft_putchar('\n');
		ft_putstr(pathname);
		ft_putendl(":");
	}
	i++;
	pathname = ft_strjoin(pathname, "/");
	if((rep = opendir(pathname)) != NULL)
	{
		if (i != 1)
			show_dir(pathname, choice);
		while ((file = readdir(rep)) != NULL)
		{
			if (file->d_type == 4 && ft_strcmp(".", file->d_name) != 0 && ft_strcmp("..", file->d_name) != 0)
				ls_read_rec(ft_strjoin(pathname, file->d_name), choice);
		}
		free(pathname);
	}
}

void		show_dir(char *pathname, char *choice)
{
	struct dirent *file;
	DIR *rep;
	t_btree		*tree;

	if ((rep = opendir(pathname)) != NULL)
	{
		while ((file = readdir(rep)) != NULL)
			btree_insert_data(&tree, file->d_name, file->d_type);
		btree_print(tree, choice);
//		free_tree(tree);
	}
}