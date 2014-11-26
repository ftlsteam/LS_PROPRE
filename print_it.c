/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_it.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acouliba <acouliba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/18 17:08:08 by acouliba          #+#    #+#             */
/*   Updated: 2014/11/26 14:14:08 by avallete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	btree_print_time(t_time *root, char *options)
{
	if (!(options[3]))
	{
		if (root->left)
			btree_print_time(root->left, options);
		ft_printls(root->content, options[2]);
		if (root->right)
			btree_print_time(root->right, options);
	}
	else
	{
		if (root->right)
			btree_print_time(root->right, options);
		ft_printls(root->content, options[2]);
		if (root->left)
			btree_print_time(root->left, options);
	}
}

void    btree_print(t_btree *root, char *options)
{
	if (!(options[3]))
	{
		if (root->left)
			btree_print(root->left, options);
		ft_printls(root->content, options[2]);
		if (root->right)
			btree_print(root->right, options);
	}
	else
	{
		if (root->right)
			btree_print(root->right, options);
		ft_printls(root->content, options[2]);
		if (root->left)
			btree_print(root->left, options);
	}
}

void    ltree_print(t_lltree *root, size_t *infos, char *options)
{
	if (!(options[3]))
	{
		if (root->left)
			ltree_print(root->left, infos, options);
		print_lsl(&root->stats, infos, options[2]);
		if (root->right)
			ltree_print(root->right, infos, options);
	}
	else
	{
		if (root->right)
			ltree_print(root->right, infos, options);
		print_lsl(&root->stats, infos, options[2]);
		if (root->left)
			ltree_print(root->left, infos, options);
	}
}