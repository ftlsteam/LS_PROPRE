/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallete <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/25 16:44:53 by avallete          #+#    #+#             */
/*   Updated: 2014/11/26 15:02:01 by avallete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int main(int argc, char const **argv)
{
	void (*f)(char*, char);
	int	i;
	char choice[5];

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
			while (i < argc)
			{
				set_up((char*)argv[i], choice);
				i++;
			}
		}
	}
	return 0;
}
