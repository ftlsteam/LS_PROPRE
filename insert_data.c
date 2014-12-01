/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binary_tree.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acouliba <acouliba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/16 18:11:59 by acouliba          #+#    #+#             */
/*   Updated: 2014/12/01 15:25:32 by avallete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_btree.h"
#include "libft.h"

void	btree_insert_data(t_btree **tree, char *data, unsigned char type)
{
	t_btree *root;

	if (*tree)
	{
		root = *tree;
		if (ft_strcmp(data, root->content) < 0)
		{
			if (root->left)
				btree_insert_data(&root->left, data, type);
			else
				root->left = create_node(data, type);
		}
		else
		{
			if (root->right)
				btree_insert_data(&root->right, data, type);
			else
				root->right = create_node(data, type);
		}
	}
	else
		*tree = create_node(data, type);
}


void	ltree_insert_data(t_lltree **tree, t_llstat data)
{
	t_lltree *root;

	if (*tree)
	{
		root = *tree;
		if (ft_strcmp(data.filename, root->stats.filename) < 0)
		{
			if (root->left)
				ltree_insert_data(&root->left, data);
			else
				root->left = create_node_stat(data);
		}
		else
		{
			if (root->right)
				ltree_insert_data(&root->right, data);
			else
				root->right = create_node_stat(data);
		}
	}
	else
		*tree = create_node_stat(data);
}

void	ltree_insert_data_time(t_lltree **tree, t_llstat data)
{
	t_lltree *root;

	if (*tree)
	{
		root = *tree;
		if (data.date > root->stats.date)
		{
			if (root->left)
				ltree_insert_data_time(&root->left, data);
			else
				root->left = create_node_stat(data);
		}
		else if (data.date < root->stats.date)
		{
			if (root->right)
				ltree_insert_data_time(&root->right, data);
			else
				root->right = create_node_stat(data);
		}
		else
			ltree_insert_data(tree, data);
	}
	else
		*tree = create_node_stat(data);
}

void    btree_insert_data_time(t_time **tree, char *data, unsigned int time, unsigned char type)
{
	t_time *root;
	
	if (*tree)
	{
		root = *tree;
		if (time > root->time)
		{
			if (root->left)
				btree_insert_data_time(&root->left, data, time, type);
			else
				root->left = create_node_time(data, time, type);
		}
		else if (time < root->time)
		{
			if (root->right)
				btree_insert_data_time(&root->right, data, time, type);
			else
				root->right = create_node_time(data, time, type);
		}
		else
			btree_insert_data_alpha(tree, data, type, time);
	}
	else
		*tree = create_node_time(data, time, type);
}

void    btree_insert_data_alpha(t_time **tree, char *data, unsigned char type, unsigned int time)
{
    t_time *root;
	
	if (*tree)
	{
		root = *tree;
		if (ft_strcmp(data, root->content) < 0)
		{
			if (root->left)
				btree_insert_data_alpha(&root->left, data, type, time);
			else
				root->left = create_node_time(data, time,  type);
		}
		else
		{
			if (root->right)
				btree_insert_data_alpha(&root->right, data, type, time);
			else
				root->right = create_node_time(data, time, type);
		}
	}
	else
		*tree = create_node_time(data, time, type);
}
