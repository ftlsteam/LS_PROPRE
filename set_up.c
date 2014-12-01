/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arguments.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acouliba <acouliba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/17 15:55:48 by acouliba          #+#    #+#             */
/*   Updated: 2014/12/01 19:46:49 by avallete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "test_btree.h"

void		initialize_infos(size_t *infos)
{
	int i;

	i = 0;
	while (i++ < 6)
		infos[i] = 0;
	infos[0] = 1;
}

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
			initialize_infos(infos);
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
				initialize_infos(infos);
			}
			else if (is_hide(argv) == 0)
			{
				infos = ls_read_stat(&ltree, argv, choice);
				ltree_print(ltree, infos, choice, argv);
				initialize_infos(infos);
			}
			else
			infos = ls_read_stat(&ltree, argv, choice);
			initialize_infos(infos);
			ls_grep_dir_stat(argv, &ltree, choice);
		}
	}
}
