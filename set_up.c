/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arguments.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acouliba <acouliba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/17 15:55:48 by acouliba          #+#    #+#             */
/*   Updated: 2014/12/01 14:50:25 by avallete         ###   ########.fr       */
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
				free_tree(tree);
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
			ltree_print(ltree, infos, choice, argv);
			ft_bzero(infos, 6);
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
				if (choice[2] == 1)
				{
					ls_read(&tree, argv);
					btree_print(tree, choice);
				}
				else if (is_hide(argv) == 0)
				{
					ls_read(&tree, argv);
                    btree_print(tree, choice);
				}
				else
					ls_read(&tree, argv);
				ls_grep_dir(argv, &tree, choice);
			}
			if (choice[1])
			{
				t_time *time;

				time = NULL;
				if (choice[2] == 1)
				{
                    ls_read_time(&time, argv);
                    btree_print_time(time, choice);
				}
                else if (is_hide(argv) == 0)
				{
                    ls_read_time(&time, argv);
                    btree_print_time(time, choice);
                }
                else
                    ls_read_time(&time, argv);
                ls_grep_dir_time(argv, &time, choice);
			}
		}
		else if (choice[0])
		{
			t_lltree		*ltree;
			size_t			*infos;

			ltree = NULL;
			infos = NULL;
			if (choice[2] == 1)
			{
				infos = ls_read_stat(&ltree, argv, choice);
				ltree_print(ltree, infos, choice, argv);
			}
			else if (is_hide(argv) == 0)
			{
				infos = ls_read_stat(&ltree, argv, choice);
				ltree_print(ltree, infos, choice, argv);
				ft_bzero(infos, 6);
			}
			else
			ls_read_stat(&ltree, argv, choice);
			ls_grep_dir_stat(argv, &ltree, choice);
		}
	}
}
