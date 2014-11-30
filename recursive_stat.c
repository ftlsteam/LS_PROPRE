/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recursive_stat.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acouliba <acouliba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/28 16:48:17 by acouliba          #+#    #+#             */
/*   Updated: 2014/11/30 15:35:55 by acouliba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void			ls_grep_dir_stat(char *argv, t_lltree **tree, char *options)
{
	char		*pathname;

	if (*tree)
	{
		if (!(check_slash(argv)))
			pathname = ft_strjoin(argv, "/");
		else
			pathname = ft_strdup(argv);
		pathname = ft_strjoin(pathname, (*tree)->stats.filename);
		if (!(options[3]))
			normal_stat(argv, tree, options, pathname);
		else
			reverse_stat(argv, tree, options, pathname);
	}
}

void			normal_stat(char *argv, t_lltree **tree, char *options,\
							char *pathname)
{
	t_lltree	*root;

	root = *tree;
	if (root)
	{
		if (root->left)
			ls_grep_dir_stat(argv, &root->left, options);
		if (root->stats.filetype == 4 && ft_strcmp("..", root->stats.filename)\
			!= 0 && ft_strcmp(".", root->stats.filename) != 0)
			recurs(pathname, options);
		if (root->right)
			ls_grep_dir_stat(argv, &root->right, options);
	}
}

void			reverse_stat(char *argv, t_lltree **tree, char *options,\
							char *pathname)
{
	t_lltree	*root;

	root = *tree;
	if (root)
	{
		if (root->right)
			ls_grep_dir_stat(argv, &root->right, options);
		if (root->stats.filetype == 4 && ft_strcmp("..", root->stats.filename)\
			!= 0 && ft_strcmp(".", root->stats.filename))
			recurs(pathname, options);
		if (root->left)
			ls_grep_dir_stat(argv, &root->left, options);
	}
}
