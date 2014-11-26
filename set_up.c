/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arguments.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acouliba <acouliba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/17 15:55:48 by acouliba          #+#    #+#             */
/*   Updated: 2014/11/26 15:38:28 by avallete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "test_btree.h"

void		set_up(char *argv, char	*choice)
{
	if ((!(choice[5])))
	{
		if ((!(choice[0])))
		{
			if ((!(choice[1])) && (!(choice[5])))
			{	
				t_btree *tree;

				tree = NULL;
				ls_read(&tree, argv);
				btree_print(tree, choice);
			}
			if (choice[1])
			{
				t_time *time;

				time = NULL;
				ls_read_time(&time, argv);
				btree_print_time(time, choice);
			}
		}
		else if (choice[0])
		{
			t_lltree		*ltree;
			size_t			*infos;
			ltree = NULL;
			infos = ls_read_stat(&ltree, argv, choice);
			ltree_print(ltree, infos, choice);
		}
	}
	else
	{
		if ((!(choice[0])))
		{
			if ((!(choice[1])))
			{	
				t_btree *tree;

				tree = NULL;
				ls_read(&tree, argv);
				btree_print(tree, choice);
				ls_grep_dir(&tree, choice);
			}
			if (choice[1])
			{
				t_time *time;

				time = NULL;
				ls_read_time(&time, argv);
				btree_print_time(time, choice);
//				ls_grep_dir(&time, choice);
			}
		}
		else if (choice[0])
		{
			t_lltree		*ltree;
			size_t			*infos;
			ltree = NULL;
			infos = ls_read_stat(&ltree, argv, choice);
			ltree_print(ltree, infos, choice);
//			ls_grep_dir(&ltree, choice);
		}
	}
}