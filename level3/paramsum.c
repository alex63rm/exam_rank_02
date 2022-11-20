/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paramsum.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejarod <alejarod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 18:52:55 by alejarod          #+#    #+#             */
/*   Updated: 2022/11/20 20:28:33 by alejarod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

void	print_nbr(int n)
{
	if (n > 9)
		print_nbr(n / 10);
	n = n % 10 + '0';
	write(1, &n, 1);
}

int	main(int argc, char **argv)
{
	argv = 0;

	if (argc == 1)
		write(1, "0", 1);
	// just convert the int argc to char
	else
	{
		print_nbr(argc - 1);
	}
	write(1, "\n", 1);
	return (0);
}