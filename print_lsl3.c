/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_lsl3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallete <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/25 17:12:28 by avallete          #+#    #+#             */
/*   Updated: 2014/11/25 17:12:44 by avallete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "libft.h"
# include "test_btree.h"
# include "ft_ls.h"

void print_time(time_t timefile, size_t oldtime)
{
	if (!oldtime)
		ft_putnstr((ctime(&timefile)) + 4, 12);
	else
	{
		if (ft_oldtime(timefile))
		{
			ft_putnstr((ctime(&timefile)) + 4, 6);
			ft_putchar(' ');
			ft_putnstr((ctime(&timefile)) + 19, 5);
		}
		else
			ft_putnstr((ctime(&timefile)) + 4, 12);
	}
	ft_putchar(' ');
}

void print_size(off_t size, size_t maxcol)
{
	size_t i;

	ft_putchar(' ');
	i = (maxcol - ft_nbrlen(size));
	while(i--)
		ft_putchar(' ');
	ft_putnbr(size);
	ft_putchar(' ');
}


