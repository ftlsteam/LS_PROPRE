/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_lsl2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallete <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/25 17:10:19 by avallete          #+#    #+#             */
/*   Updated: 2014/12/02 18:25:53 by avallete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "libft.h"
# include "test_btree.h"
# include "ft_ls.h"
# include "struct_lsl.h"

void print_group(char *groupname, size_t maxcol)
{
	size_t i;

	i = (maxcol - ft_strlen(groupname)) + 1;
	ft_putstr(groupname);
	while (i--)
		ft_putchar(' ');
}

void print_owner(char *owner, size_t maxcol)
{
	size_t i;

	i = maxcol - ft_strlen(owner);
	ft_putstr(owner);
	while (i--)
		ft_putchar(' ');
	ft_putchar(' ');
	ft_putchar(' ');
}

void print_hlink(int nb, size_t maxcol)
{
	size_t i;

	i = (maxcol - ft_nbrlen(nb));
	while (i--)
		ft_putchar(' ');
	ft_putnbr(nb);
	ft_putchar(' ');
}

void print_typefile(unsigned char type)
{
	if (type == 0 || type == 14 || type == 8)
		ft_putchar('-');
	if (type == 1)
		ft_putchar('p');
	if (type == 2)
		ft_putchar('c');
	if (type == 4)
		ft_putchar('d');
	if (type == 6)
		ft_putchar('b');
	if (type == 10)
		ft_putchar('l');
	if (type == 12)
		ft_putchar('s');
}

void print_linkpath(char *filename, off_t size)
{
	char *linkpath;

	linkpath = NULL;
	ft_putstr(" -> ");
	linkpath = (char*)malloc(sizeof(char) * size + 1);
	ft_bzero(linkpath, (sizeof(char) * size + 1));
	readlink(filename, linkpath, size);
	ft_putstr(linkpath);
	free(linkpath);
	linkpath = NULL;
}
