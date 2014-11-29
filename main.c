/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallete <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/25 16:44:53 by avallete          #+#    #+#             */
/*   Updated: 2014/11/29 15:45:57 by acouliba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	free_tree(t_btree *tree)
{
	if (tree)
	{
		if(tree->left)
			free_tree(tree->left);
		if (tree->right)
			free_tree(tree->right);
		free(tree->content);
		free(tree);
	}
}

void	free_tree_time(t_time *tree)
{
	if (tree)
	{
		if(tree->left)
			free_tree_time(tree->left);
		if (tree->right)
			free_tree_time(tree->right);
		free(tree->content);
		free(tree);
	}
}

void	free_tree_stat(t_lltree *tree)
{
	if (tree)
	{
		if(tree->left)
			free_tree_stat(tree->left);
		if (tree->right)
			free_tree_stat(tree->right);
		//	free(tree->stats);
		free(tree);
	}
}

void print_error(char *filename)
{
	ft_putstr("ls: ");
	perror(filename);
}

void print_files_args(t_btree *args, char reverse)
{
	if (!(reverse))
	{
		if (args->left)
			print_files_args(args->left, reverse);
		if (args->file_type == 0)
		{
			ft_putendl(args->content);
		}
		if (args->right)
			print_files_args(args->right, reverse);
	}
	else
	{
		if (args->right)
			print_files_args(args->right, reverse);
		if (args->file_type == 0)
			ft_putendl(args->content);
		if (args->left)
			print_files_args(args->left, reverse);
	}
}

void	call_setup(t_btree *args, char *choice)
{
	static int i = 0;

	if (args->left)
		call_setup(args->left, choice);
	if (args->file_type == 4)
	{
		if (i > 0)
			ft_putchar('\n');
		i = 1;
		ft_putstr(args->content);
		ft_putendl(":");
		set_up(args->content, choice);
	}
	if (args->right)
		call_setup(args->right, choice);
}

void argument_sort(const char **argv, int *tab, char *choice)
{
	int arg;
	t_btree *args;

	args = NULL;
	while (tab[0] < tab[1])
	{
		if ((arg = open(argv[tab[0]], O_RDONLY)))
		{
			if ((arg = open(argv[tab[0]], O_DIRECTORY) > 0))
				btree_insert_data(&args, (char*)argv[tab[0]], 4);
			else
				btree_insert_data(&args, (char*)argv[tab[0]], 0);
		}
		else
			print_error((char*)argv[tab[0]]);
		tab[0]++;
	}
	print_files_args(args, choice[3]);
	call_setup(args, choice);
}

int main(int argc, char const **argv)
{
	void (*f)(char*, char);
	int	i;
	char choice[5];
	int  tab[2];

	f = &ft_arg;
	ft_bzero(choice, 5);
	if (argc == 1)
		set_up(".", choice);
	if (argc > 1)
	{
		i = ft_arguments(argc, argv, choice, f);
		if (i >= argc)
			set_up((char*)".", choice);
		else
		{
			tab[0] = i;
			tab[1] = argc;
			if (argc > i + 1)
				argument_sort(argv, tab, choice);
			else
				set_up((char*)argv[i], choice);
		}
	}
	return 0;
}
