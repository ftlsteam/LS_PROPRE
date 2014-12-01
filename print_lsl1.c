/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_lsl1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallete <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/25 17:09:20 by avallete          #+#    #+#             */
/*   Updated: 2014/12/01 19:55:36 by avallete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "libft.h"
# include "test_btree.h"
# include "ft_ls.h"

void print_usrmod(int st_mode)
{
	st_mode & S_IRUSR ? ft_putchar('r') : ft_putchar('-');
	st_mode & S_IWUSR ? ft_putchar('w') : ft_putchar('-');
	if (st_mode & S_IXUSR)
	{
		if (st_mode & S_ISUID)
			ft_putchar('s');
		else
			ft_putchar('x');
	}
	else if (!(st_mode & S_IXUSR))
	{
		if (st_mode & S_ISUID)
			ft_putchar('S');
		else
			ft_putchar('-');
	}
}

void print_groupmod(int st_mode)
{
	st_mode & S_IRGRP ? ft_putchar('r') : ft_putchar('-');
	st_mode & S_IWGRP ? ft_putchar('w') : ft_putchar('-');
	if (st_mode & S_IXGRP)
	{
		if (st_mode & S_ISGID)
			ft_putchar('s');
		else
			ft_putchar('x');
	}
	else if (!(st_mode & S_IXGRP))
	{
		if (st_mode & S_ISGID)
			ft_putchar('S');
		else
			ft_putchar('-');
	}
}

void print_othermod(int st_mode)
{
	st_mode & S_IROTH ? ft_putchar('r') : ft_putchar('-');
	st_mode & S_IWOTH ? ft_putchar('w') : ft_putchar('-');
	if (st_mode & S_ISVTX)
	{
		if ((!(st_mode & S_IROTH)) && (!(st_mode & S_IXOTH)))
			ft_putchar('T');
		if (((st_mode & S_IROTH)) && ((st_mode & S_IXOTH)))
			ft_putchar('t');
	}
	else
		st_mode & S_IXOTH ? ft_putchar('x') : ft_putchar('-');
}

void print_extended(int st_mode)
{
	st_mode = st_mode;
	ft_putchar(' ');
}

void print_rights(int st_mode)
{
	print_usrmod(st_mode);
	print_groupmod(st_mode);
	print_othermod(st_mode);
	print_extended(st_mode);
	ft_putchar(' ');
}

void print_total(int st_blksize)
{
	ft_putstr("total ");
	ft_putnbr(st_blksize);
	ft_putchar('\n');
}
