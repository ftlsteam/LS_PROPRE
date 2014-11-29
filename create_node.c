/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_node.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallete <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/25 16:53:36 by avallete          #+#    #+#             */
/*   Updated: 2014/11/29 15:46:08 by acouliba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_btree.h"
#include "libft.h"

t_btree  *create_node(char *content, unsigned char type)
{
    t_btree     *new;


    new = malloc(sizeof(t_btree));
    new->content = ft_strdup(content);
	new->file_type = type;
    new->left = NULL;
    new->right = NULL;

    return (new);
}

t_lltree	*create_node_stat(t_llstat datas)
{
	t_lltree *new;

	new = (t_lltree*)malloc(sizeof(t_lltree));
	new->left = NULL;
	new->right = NULL;
	new->stats = (datas);
	return (new);
}

t_time  *create_node_time(char *content, int time, unsigned char type)
{
    t_time   *new;

    new = malloc(sizeof(t_btree));
    new->content = ft_strdup(content);
    new->time = time;
    new->file_type = type;
    new->left = NULL;
    new->right = NULL;

    return (new);
}
