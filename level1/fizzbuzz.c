/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fizzbuzz.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejarod <alejarod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 19:05:39 by alejarod          #+#    #+#             */
/*   Updated: 2022/11/24 19:30:55 by alejarod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

void	print_nbr(int n)
{
	if (n > 9)
		print_nbr (n / 10);
	n = n % 10 + '0';
	write (1, &n, 1);
}

int	main(void)
{
	unsigned int	n;

	n = 1;
	while (n <= 100)
	{
		if (n % 3 == 0 && n % 5 == 0)
			write (1, "fizzbuzz", 8);
		else if (n % 3 == 0)
			write (1, "fizz", 4);
		else if (n % 5 == 0)
			write (1, "buzz", 4);
		else
			// we need this one to convert the int to 1 digit and then add + '0' to convert to char
			print_nbr(n);
		write (1, "\n", 1);
	n++;
	}
	return (0);
}