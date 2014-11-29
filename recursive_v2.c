/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recursive_v2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acouliba <acouliba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/24 19:01:00 by acouliba          #+#    #+#             */
/*   Updated: 2014/11/29 17:29:12 by avallete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int				check_slash(char *str)
{
	size_t i;

	if (str)
	{
		i = ft_strlen(str) - 1;
		if (str[i] == '/')
			return (1);
		else
			return (0);
	}
	return (0);
}

void			ls_grep_dir(char *argv, t_btree **tree, char *options)
{
	t_btree *root;
	char *pathname;

	if (*tree)
	{
		root = *tree;
		if (!(check_slash(argv)))
			pathname = ft_strjoin(argv, "/");
		else
			pathname = ft_strdup(argv);
		pathname = ft_strjoin(pathname, root->content);

		if (!(options[3]))
		{
			if (root->left)
				ls_grep_dir(argv, &root->left, options);
			if (root->file_type == 4 && ft_strcmp("..", root->content) != 0 && ft_strcmp(".", root->content) != 0)
				ls_read_rec(pathname, options);
			if (root->right)
				ls_grep_dir(argv, &root->right, options);
		}
		else
		{
			if (root->right)
				ls_grep_dir(argv, &root->right, options);
			if (root->file_type == 4 && ft_strcmp("..", root->content) != 0)
				ls_read_rec(pathname, options);
			if (root->left)
				ls_grep_dir(argv, &root->left, options);
		}
		free(pathname);
	}
}

void            ls_read_rec(char *pathname, char *choice)
{
	struct dirent *file;
	DIR     *rep;

	ft_putchar('\n');
	ft_putstr(pathname);
	ft_putendl(":");
	if (!(check_slash(pathname)))
		pathname = ft_strjoin(pathname, "/");
	if((rep = opendir(pathname)) != NULL)
	{
		show_dir(pathname, choice);
		while ((file = readdir(rep)) != NULL)
		{
			if (file->d_type == 4 && ft_strcmp(".", file->d_name) != 0 && ft_strcmp("..", file->d_name) != 0)
				ls_read_rec(ft_strjoin(pathname, file->d_name), choice);
		}
		closedir(rep);
	}
	else
		print_error(pathname);
	free(pathname);
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
		free_tree(tree);
		closedir(rep);
	}
}
