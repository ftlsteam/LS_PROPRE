/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recursive_v2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acouliba <acouliba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/24 19:01:00 by acouliba          #+#    #+#             */
/*   Updated: 2014/11/30 15:39:33 by acouliba         ###   ########.fr       */
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
	char		*pathname;

	if (*tree)
	{
		if (!(check_slash(argv)))
			pathname = ft_strjoin(argv, "/");
		else
			pathname = ft_strdup(argv);
		pathname = ft_strjoin(pathname, (*tree)->content);
		if (!(options[3]))
			normal(argv, tree, options, pathname);
		else
			reverse(argv, tree, options, pathname);
	}
}

void			normal(char *argv, t_btree **tree, char *options,\
					char *pathname)
{
	t_btree		*root;

	root = *tree;
	if (root)
	{
		if (root->left)
			ls_grep_dir(argv, &root->left, options);
		if (root->file_type == 4 && ft_strcmp("..", root->content) != 0\
			&& ft_strcmp(".", root->content) != 0)
			recurs(pathname, options);
		if (root->right)
			ls_grep_dir(argv, &root->right, options);
	}
}

void			reverse(char *argv, t_btree **tree, char *options,\
						char *pathname)
{
	t_btree		*root;

	root = *tree;
	if (root)
	{
		if (root->right)
			ls_grep_dir(argv, &root->right, options);
		if (root->file_type == 4 && ft_strcmp("..", root->content) != 0\
			&& ft_strcmp(".", root->content) != 0)
			recurs(pathname, options);
		if (root->left)
			ls_grep_dir(argv, &root->left, options);
	}
}

void			recurs(char *pathname, char *options)
{
	ft_putchar('\n');
	ft_putstr(pathname);
	ft_putendl(":");
	set_up(pathname, options);
}
