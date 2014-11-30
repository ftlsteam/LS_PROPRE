/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recursive_time.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acouliba <acouliba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/30 14:16:13 by acouliba          #+#    #+#             */
/*   Updated: 2014/11/30 15:23:03 by acouliba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void			ls_grep_dir_time(char *argv, t_time **tree, char *options)
{
	char		*pathname;

	if (*tree)
	{
		if (!(check_slash(argv)))
			pathname = ft_strjoin(argv, "/");
		else
			pathname = ft_strdup(argv);
		pathname = ft_strjoin(pathname, (*tree)->content);
		if (!(options[3]))
			normal_time(argv, tree, options, pathname);
		else
			reverse_time(argv, tree, options, pathname);
	}
}

void			normal_time(char *argv, t_time **tree, char *options,\
							char *pathname)
{
	t_time		*root;

	root = *tree;
	if (root)
	{
		if (root->left)
			ls_grep_dir_time(argv, &root->left, options);
		if (root->file_type == 4 && ft_strcmp("..", root->content) != 0\
			&& ft_strcmp(".", root->content) != 0)
			recurs(pathname, options);
		if (root->right)
			ls_grep_dir_time(argv, &root->right, options);
	}
}

void			reverse_time(char *argv, t_time **tree, char *options,\
							char *pathname)
{
	t_time		*root;

	root = *tree;
	if (root)
	{
		if (root->right)
			ls_grep_dir_time(argv, &root->right, options);
		if (root->file_type == 4 && ft_strcmp("..", root->content) != 0\
			&& ft_strcmp(".", root->content) != 0)
			recurs(pathname, options);
		if (root->left)
			ls_grep_dir_time(argv, &root->left, options);
	}
}
