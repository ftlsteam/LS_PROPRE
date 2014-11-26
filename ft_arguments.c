/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_btree.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acouliba <acouliba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/18 16:26:23 by acouliba          #+#    #+#             */
/*   Updated: 2014/11/26 15:01:58 by avallete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_btree.h"
#include "libft.h"

int			ft_arguments(int argc, char const **argv, char *choice,\
	   	void (*f)(char *c, char e))
{
	int	i;
	unsigned int	j;
	size_t l;

	i = 1;
	while (i < argc && argv[i][0] == '-')
	{
		j = 0;
		l = ft_strlen(argv[i]);
		while (j < l)
		{
			f(choice, argv[i][j]);
			j++;
		}
		i++;
	}
	return (i);
}

void	ft_arg(char *c, char e)
{
	if (e == 'l')
		c[0] = 1;
	if (e == 't')
		c[1] = 1;
	if (e == 'a')
		c[2] = 1;
	if (e == 'r')
		c[3] = 1;
	if (e == 'R')
		c[5] = 1;
}

void	ft_printls(char *filename, char hide)
{
	if ((hide))
		ft_putendl(filename);
	else
	{
		if (filename[0] != '.') 
			ft_putendl(filename);
	}
}
