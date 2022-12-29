/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paramsum.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejarod <alejarod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 18:52:55 by alejarod          #+#    #+#             */
/*   Updated: 2022/12/29 19:30:51 by alejarod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

void	put_nbr(int nbr)
{
	if (nbr >= 9)
		print_nbr(nbr / 10);
	nbr = nbr % 10 + '0';
	write(1, &nbr, 1);
}

int	main(int argc, char **argv)
{
	argv = 0;		// since we don't need it, initialize to 0 or cast it to void

	if (argc == 1)
		write(1, "0", 1);
	else
		print_nbr(argc - 1);	// we don't want argv[0]
	write(1, "\n", 1);
	return (0);
}

/* Assignment name  : paramsum
Expected files   : paramsum.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that displays the number of arguments passed to it, followed by
a newline.

If there are no arguments, just display a 0 followed by a newline.

Example:

$>./paramsum 1 2 3 5 7 24
6
$>./paramsum 6 12 24 | cat -e
3$
$>./paramsum | cat -e
0$
$>
 */